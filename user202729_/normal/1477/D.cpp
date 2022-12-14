#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

std::vector<std::vector<int>> add, complement;
std::set<int> left;
void work(int node){ // I don't really remember this algorithm...
	assert(not left.count(node));
	int other=-1;
	while(true){
		auto const iterator=left.upper_bound(other);
		if(iterator==left.end()) break;
		other=*iterator;

		if(not std::binary_search(begin(add[node]), end(add[node]), other)){
			complement[node].push_back(other); complement[other].push_back(node);
			left.erase(iterator); work(other);
		}
	}
}

struct Star{int root; std::vector<int> leaves;};
std::vector<Star> stars;
std::vector<char> visited;
bool work2(int node){ // returns true if the node is free (to be used as the parent's leaf), false otherwise
	assert(not visited[node]); visited[node]=true;
	std::vector<int> leafChildren;
	for(auto child: complement[node]) {
		complement[child].erase(std::find(begin(complement[child]), end(complement[child]), node));
		if(work2(child)) leafChildren.push_back(child);
	}
	if(leafChildren.empty()) return true;
	stars.push_back({node, std::move(leafChildren)});
	return false;
}

void up(){
	int n, m; std::cin>>n>>m;
	add.clear(); add.resize(n);
	complement.clear(); complement.resize(n);
	stars.clear();
	for(int _=0; _<m; ++_){
		int left, right; std::cin>>left>>right;--left;--right;
		add[left].push_back(right); add[right].push_back(left);
	}
	for(auto& it: add) std::sort(begin(it), end(it));

	// dfs to find a spanning tree of the complement of add
	//visited.assign(n, false);
	left.clear(); for(int node=0; node<n; ++node) left.insert(left.end(), node);
	while(not left.empty()){
		auto const node=*left.begin(); left.erase(left.begin());
		work(node);
	}
	add.clear(); // (why not.)

	std::vector<int> p(n), q(n);
	int last=0;

	visited.assign(n, false);
	for(int node=0; node<n; ++node) if(complement[node].size()==1 and not visited[node]){
		if(work2(node)){
			assert(stars.back().root==complement[node][0]);
			stars.back().leaves.push_back(node);
		}
	}else if(not visited[node] and complement[node].empty()){
		p[node]=q[node]=last++; // unavoidable point deduction
	}

	assert((
				visited.assign(n, false)
				, true));
	for(auto const& [root, leaves]: stars){
		assert(not visited[root]); assert((visited[root]=true));
		q[root]=last;
		for(auto it: leaves){
			assert(not visited[it]); assert((visited[it]=true));
			p[it]=last++;
			q[it]=last;
		}
		p[root]=last++; // pretty confusing...
	}
	assert(last==n);

	for(auto it: p) std::cout<<it+1<<' ';
	std::cout<<'\n';
	for(auto it: q) std::cout<<it+1<<' ';
	std::cout<<'\n';
	
}