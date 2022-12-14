// 3e5 calls to `index`, each one takes 4**2*3e4*log(3e4)=7e6...
// obviously TLE.
// note that there are also 30 test cases!!!
// ...
// how can people implement something like this in the contest.
// is this the expected algorithm? is this efficient enough to pass?
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

void up(){
	int n, globalMaxCost, numQuery; std::cin>>n>>globalMaxCost>>numQuery;
	std::vector<int> p;
	//p.clear();
	p.resize(n); for(auto& it: p){ std::cin>>it; --it; }
	struct Sequence{
		int start;
		int cost;
	};

	std::vector<std::array<int64_t, 5>> value(n+1);
	value[0].fill(1);

	static int64_t constexpr BOUND=(int64_t)2e18;
	static auto const addSaturated=[](int64_t& a, int64_t b){
		a+=b; if(a>=BOUND) a=BOUND;
	};

	for(int len=1; len<=n; ++len){ // 3e5
		for(int cost=0; cost<(int)value[len].size(); ++cost){ // 5
			int64_t cur=0;
			for(int prefixLength=1; prefixLength<=std::min(len, cost+1); ++prefixLength){ // 5
				addSaturated(cur, value[len-prefixLength][cost-(prefixLength-1)]);
			}
			value[len][cost]=cur;
		}
	} // -> 3e5*5*5=7.5e6
	auto const count=[&](Sequence sequence)->int64_t{ // 1
		return value[n-sequence.start][sequence.cost];
	};

	Sequence all{0, globalMaxCost};

	std::vector<int64_t> result(numQuery);
	assert((result.assign(result.size(), -2), true));
	struct Query{
		int pos; int64_t sequenceIndex;
		Sequence sequence;
		int queryIndex;
	};
	std::vector<std::vector<Query>> queries(globalMaxCost+1);
	for(int queryIndex=0; queryIndex<numQuery; ++queryIndex){
		int pos; int64_t sequenceIndex; std::cin>>pos>>sequenceIndex;
		--pos;--sequenceIndex;
		assert(sequenceIndex<BOUND);
		if(sequenceIndex>=count(all))
			result[queryIndex]=-1;
		else
			queries[globalMaxCost].push_back({pos, sequenceIndex, all, queryIndex});
	}

	// ======== actual computation

	struct Part{
		int firstDiff, firstDiffValue; // both INT_MAX if there's none
		Sequence value; // contains [start] field
	};
	auto const generateParts=[&](Sequence sequence){
		// time complexity: globalMaxCost*n*log(globalMaxCost*n)
		std::vector<Part> partsBefore, partsAfter;
		for(int prefixLength=2; prefixLength<=sequence.cost+1 and sequence.start+prefixLength<=n; ++prefixLength){
			for(int nextStart=sequence.start+prefixLength; nextStart<=(int)p.size(); ++nextStart){
				auto const firstDiffValue=p[nextStart-1];
				auto const firstDiff=nextStart-prefixLength;
				auto const newCost=sequence.cost-(prefixLength-1);
				assert(newCost<sequence.cost);
				assert(firstDiffValue!=p[firstDiff]);
				(firstDiffValue<p[firstDiff] ? partsBefore: partsAfter).push_back(
						{firstDiff, firstDiffValue, Sequence{nextStart, newCost}}
						);
			}
		}
		std::sort(begin(partsBefore), end(partsBefore), [&](auto const& first, auto const& sec){
			return first.firstDiff!=sec.firstDiff ? first.firstDiff<sec.firstDiff: first.firstDiffValue<sec.firstDiffValue;
		});
		std::sort(begin(partsAfter), end(partsAfter), [&](auto const& first, auto const& sec){
			return first.firstDiff!=sec.firstDiff ? first.firstDiff>sec.firstDiff: first.firstDiffValue<sec.firstDiffValue;
		});
		partsBefore.push_back({INT_MAX, INT_MAX, {(int)p.size(), sequence.cost}});
		partsBefore.insert(partsBefore.end(), begin(partsAfter), end(partsAfter));
		partsAfter.clear();
		return partsBefore;
	};

	for(int cost=(int)queries.size(); cost--;){
		// the case cost==0 can be special cased to be a little more efficient
		// propagate queries[cost]...
		std::vector<Part> parts=generateParts(Sequence{0, cost});
		struct Tree{
			std::vector<int64_t> value;
			Tree(int number): value(number*2){}
			int nodeOf(int pos)const{
				int node=pos+(1<<(31^__builtin_clz((int)value.size())));
				return node<(int)value.size() ? node: node-int(value.size()/2);
			}
			int posOf(int node)const{
				int pos=node-(1<<(31^__builtin_clz((int)value.size())));
				return pos>=0 ? pos: pos+int(value.size()/2);
			}
			void add(int pos, int64_t delta){
				for(int node=nodeOf(pos); node; node>>=1)
					addSaturated(value[node], delta);
			}
			std::pair<int, int64_t> posIndex(int64_t index, int node=1)const{
				assert(0<=index); assert(index<value[node]);
				if(node>=int(value.size()/2)) return {posOf(node), index};
				return index<value[node*2] ? posIndex(index, node*2):
					posIndex(index-value[node*2], node*2+1);
			}
		}; // **try not to reimplement things like this...**

		// (I hope C++20's ranges library arrives (to Codeforces) soon)

		std::vector<std::vector<int>> indicesInPart(p.size()); // [firstDiff]
		Tree tree((int)parts.size());
		for(int partIndexInParts=0; partIndexInParts<(int)parts.size(); ++partIndexInParts){
			auto const part=parts[partIndexInParts];
			if(part.firstDiff==INT_MAX){
				assert(count(part.value)==1);
				tree.add(partIndexInParts, 1);
			}else
				indicesInPart[part.firstDiff].push_back(partIndexInParts);
		}

		// plan: process in decreasing sequence.start order, gradually add to the tree
		std::sort(begin(queries[cost]), end(queries[cost]), [&](auto const& first, auto const& sec){
			return first.sequence.start>sec.sequence.start;
		});
		for(auto [posInString, sequenceIndex, sequence, queryIndex]: queries[cost]){
			assert(sequence.cost==cost);
			assert(posInString>=sequence.start);
			while(true){ // add to the tree
				int nextFirstDiffValue=(int)indicesInPart.size()-1;
				if(nextFirstDiffValue>=sequence.start){
					for(auto index: indicesInPart.back()){
						assert(parts[index].firstDiff==nextFirstDiffValue);
						tree.add(index, count(parts[index].value));
					}
					indicesInPart.pop_back();
				}else{
					assert(nextFirstDiffValue==sequence.start-1);
					assert(tree.value[1]==count(sequence) or not(std::cerr<<tree.value[1]<<' '<<count(sequence)<<'\n'));
					break;
				}
			}
			// lookup in the tree
			auto const [partIndexInParts, sequenceIndexInPart]=tree.posIndex(sequenceIndex);
			auto const part=parts[partIndexInParts];
			if(posInString>=part.value.start){
				//assert(part.value.cost!=0);
				queries[part.value.cost].push_back(
						Query{posInString, sequenceIndexInPart, part.value, queryIndex}
						);
			}else if(posInString>=part.firstDiff)
				result[queryIndex]=p[part.firstDiff+(part.value.start-1)-posInString];
			else
				result[queryIndex]=p[posInString];
		}
	}
	// ========

	for(auto it: result) 
		if(it<0) {
			assert(it!=-2);
			std::cout<<"-1\n"; 
		}else
			std::cout<<it+1<<'\n';
}