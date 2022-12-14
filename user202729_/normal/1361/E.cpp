// Another bug detected while reimplementing the solution.
// Not sure if it's faster or slower to determine the bug if I just read the code.
// Although my typing speed is (still) slower than my reading speed,
// reimplementing requires more attention so it's more likely to detect the bug,
// or at least I subconsciously fix the bug in the reimplementation.
//
//
// ========

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}


std::mt19937 engine(
#if LOCAL
		123456
#else
		std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count()
#endif
		);

std::vector<std::vector<int>> add, children;
std::vector<int> depth; // -<depth>: visited, 0: not visited, 1: root, 2: below 1,...
std::vector<int> parOf;
std::vector<char> bad, // contained in two different back edges
	badTree; // under a bridge
struct CrossOrForwardEdge{};

std::vector<std::array<int, 2>> resultOf; // back edge reachability information

std::array<int, 2> work(int node, int par){ // returns minimum depth of nodes reachable with one back edge or depth[node]
	parOf[node]=par;

	assert(depth[node]>0);
	auto const nextDepth=depth[node]+1;
	std::array<int, 2> result{{depth[node], depth[node]}}; // result[0] is smaller
	auto const insert=[&](int x){
		if(x<result[1]){
			result[1]=x;
			if(result[1]<result[0]) std::swap(result[0], result[1]);
		}
	};

	for(auto other: add[node]) {
		if(depth[other]==0){
			depth[other]=nextDepth;
			for(auto x: work(other, node)) insert(x);
		}else if(depth[other]<0){
			throw CrossOrForwardEdge{};
		}else{ // back edge
			insert(depth[other]);
		}
	}

	if(result[1]<depth[node]){ // two back edges
		bad[node]=true;
	}else if(result[0]>=depth[node] and par>=0) // no back edge, par..node is a bridge
		badTree[node]=true;

	depth[node]=-depth[node];
	assert(depth[node]<0);
	return result;
}

std::vector<char> filledBad;
void fillBad(int node){
	if(filledBad[node]) return;
	bad[node]=filledBad[node]=true;
	for(auto other: add[node]) {
		assert(depth[node]>0 and depth[other]>0);
		if(depth[other]==depth[node]+1) fillBad(other);
	}
}

std::vector<std::array<bool, 20>> sparseVisited;
std::vector<std::array<int, 20>> jump; // -1: none
std::vector<std::vector<int>> reverseAdd;

void fillSparse(int node, int layer){
	// (1<<layer) nearest ancestors of node (including node) are bad
	if(node<0 or sparseVisited[node][layer]) return;
	sparseVisited[node][layer]=true;
	if(layer==0){
		bad[node]=true;

		for(auto other: reverseAdd[node]){
			int number=depth[other]-depth[node]; assert(number>0);
			while(number){
				fillSparse(other, __builtin_ctz(number));
				other=jump[other][__builtin_ctz(number)];
				if(other<0) break;
				number-=number&-number;
			}
		}
	}else{
		fillSparse(node, layer-1);
		fillSparse(jump[node][layer-1], layer-1);
	}
}

void up(){
	add.clear();int numNode, numEdge; std::cin>>numNode>>numEdge;
	add.resize(numNode);
	for(int _=0; _<numEdge; ++_){
		int first, sec; std::cin>>first>>sec;
		--first;--sec;
		add[first].push_back(sec);
	}

	parOf.resize(numNode);
	for(int _=0; _<60; ++_){
		// 60 tries->estimated success probability=  (1-0.8**60)**2000 = 0.9969396988668168
		auto const root=std::uniform_int_distribution(0, numNode-1)(engine);
		try{
			depth.assign(numNode, 0);
			bad.assign(numNode, false);
			badTree.assign(numNode, false);
			depth[root]=1; work(root, -1);

			for(auto & it: depth){
				if(it==0){
					// some nodes are not reachable ->root is bad
					goto try_other_root;
				}
				it=-it; assert(it>0);
			}

			// otherwise, root is good

			filledBad.assign(numNode, false);
			for(int node=0; node<numNode; ++node)
				if(badTree[node]) fillBad(node);
			assert(not bad[root]);

			reverseAdd.clear();
			reverseAdd.resize(numNode);
			for(int node=0; node<numNode; ++node)
				for(auto other: add[node]) if(depth[other]<depth[node])
					reverseAdd[other].push_back(node);

			jump.resize(numNode);
			for(int node=0; node<numNode; ++node)
				jump[node][0]=parOf[node];
			for(int layer=1; layer<(int)jump[0].size();++layer){
				for(int node=0; node<numNode; ++node){
					auto& it=jump[node][layer];
					it=jump[node][layer-1];
					if(it>=0) it=jump[it][layer-1];
				}
			}


			sparseVisited.clear();
			sparseVisited.resize(numNode);
			for(int node=0; node<numNode; ++node)
				if(bad[node]) fillSparse(node, 0);



			if((numNode-std::accumulate(begin(bad), end(bad), 0))*5<numNode){
				std::cout<<"-1\n";
				return;
			}
			for(int node=0; node<numNode; ++node)
				if(not bad[node]) std::cout<<node+1<<' ';
			std::cout<<'\n';

			return;
		}catch(CrossOrForwardEdge){ // root is bad
			goto try_other_root;
		}

try_other_root:;
	}
	std::cout<<"-1\n";
}