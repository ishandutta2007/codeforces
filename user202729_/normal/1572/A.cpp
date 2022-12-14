// time-limit: 1500
// problem-url: https://codeforces.com/contest/1572/problem/A

// okay, unrated so can't compare
// still, can compare rank
// anyway, it might not be indicative of the real performance

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
	int number; std::cin>>number;
	std::vector<std::vector<int>> require(number), support(number);
	for(int target=0; target<number; ++target){
		int k; std::cin>>k;
		for(int _=0; _<k; ++_){
			int source; std::cin>>source;
			--source;
			require[target].push_back(source); support[source].push_back(target);
		}
	}

	std::vector<char> understood(number);
	std::set<int> pend;
	std::vector<int> requireLeft(number);
	for(int i=0; i<number; ++i){
		requireLeft[i]=(int)require[i].size();
		if(requireLeft[i]==0)
			pend.insert(i);
	}

	int pass=0;
	while(not pend.empty()){
		++pass;
		int i=0;
		while(true){
			auto it=pend.lower_bound(i);
			if(it==pend.end()) break;
			i=*it;

			assert(not understood[i]);
			understood[i]=true;
			pend.erase(it);

			for(auto other: support[i]){
				assert(requireLeft[other]);
				requireLeft[other]--;
				if(requireLeft[other]==0) pend.insert(other);
			}
		}
	}

	if(std::all_of(begin(understood), end(understood), [&](auto const& it){
		return it;
	}))
		std::cout<<pass<<'\n';
	else
		std::cout<<"-1\n";
}