// is it too slow?
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
	int n, q; std::cin>>n>>q;
	std::string s; s.reserve(n); std::cin>>s;
	std::string f; f.reserve(n); std::cin>>f;
	std::vector<std::pair<int, int>> operations(q);
	for(int index=0; index<q; ++index){
		int left, right; std::cin>>left>>right;
		operations[index]={left-1, right};
	}

	std::map<int, int> changes; // leftmost->new value (0|1)
	for(int index=0; index<n; ++index)
		changes.insert(changes.end(), {index, f[index]-'0'});
	changes.insert(changes.end(), {n, -1});

	for(int i=q; i--;){
		auto const [left, right]=operations[i];
		auto const split=[&](int splitPos){
			auto const iterator=changes.lower_bound(splitPos);
			if(iterator->first!=splitPos){
				return changes.insert(iterator, {splitPos, std::prev(iterator)->second});
			}
			return iterator;
		};
		auto leftIter=split(left), rightIter=split(right);

		std::array<int, 2> count{};
		// erase and count at the same time
		assert(leftIter!=rightIter);
		int lastPos=leftIter->first, lastValue=leftIter->second;
		while(true){
			leftIter=changes.erase(leftIter);
			int curPos=leftIter->first, curValue=leftIter->second;
			assert(curPos>lastPos);
			count[lastValue]+=curPos-lastPos;
			lastPos=curPos; lastValue=curValue;
			if(leftIter==rightIter) break;
		}

		if(count[0]==count[1]){
			std::cout<<"NO\n";
			return;
		}
		changes.insert(leftIter, {left, count[0]<count[1] ? 1 : 0});
	}

	// check
	auto iter=changes.begin();
	int lastPos=iter->first, lastValue=iter->second;
	while(true){
		++iter;
		int curPos=iter->first, curValue=iter->second;
		for(int i=lastPos; i<curPos; i++) if(lastValue!=(s[i]-'0')){
			std::cout<<"NO\n";
			return;
		}
		lastPos=curPos; lastValue=curValue;
		if(curPos==n) break;
	}
	std::cout<<"YES\n";
}