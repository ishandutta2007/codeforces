// time-limit: 2000
// problem-url: https://codeforces.com/contest/1588/problem/C
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// too slow... (and make many errors along the way somehow)

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int n; std::cin>>n;
	std::vector<int> a(n);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	auto const multiple=[&](int i){
		return (i&1)? 1: -1;
	};

	std::vector<int64_t> sum(n+1);
	for(int i=0; i<n; ++i)
		sum[i+1]=sum[i]+a[i]*multiple(i);

	int64_t result {};

	if(0){
		for(int right=1; right<=n; ++right)
			for(int left=0; left<right; ++left){
				if(sum[left]==sum[right] and [&]{
					for(int i=left+1; i<right; ++i)
						if(not(sum[i]*multiple(i) <= sum[left]*multiple(i))) return false;
					return true;
				}())
					++result;
			}
	}


	std::map<int64_t, std::vector<int>> byValue;
	for(int i=0; i<=n; ++i) byValue[sum[i]].push_back(i);

	std::set<int> fail;
	for(int i=0; i<=n; ++i)
		if(multiple(i)==1) fail.insert(i);

	for(auto const& [value, indices]: byValue){
		for(auto i: indices){
			assert(sum[i]==value);
			if(multiple(i)==1) fail.erase(fail.find(i));
		}

		for(
				int last=0, i=1;
				;
				i++){
			if(i==(int)indices.size()){
				result+=(int64_t(i-last)*(i-last-1))>>1;
				break;
			}

			auto iter=fail.lower_bound(indices[i]);
			if(iter!=fail.begin() and *(--iter)>indices[i-1]){
				result+=(int64_t(i-last)*(i-last-1))>>1;
				last=i;
			}
		}

		for(auto i: indices){
			if(multiple(i)==-1){
				auto const inserted=fail.insert(i).second;
				assert(inserted);
			}
		}
	}

	
	
	std::cout<<result<<'\n';

}