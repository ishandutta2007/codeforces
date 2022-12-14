// time-limit: 1000
// problem-url: https://codeforces.com/contest/1610/problem/E

// again?

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
	int len; std::cin>>len;
	std::vector<int> a(len);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	int last=0;
	int maxSubsequenceLen=0;
	for(int i=1; i<=len; ++i) if(i==len or a[i]!=a[i-1]){
		int curLen=i-last, curValue=a[i-1];
		auto const first=a[i-1];
		if(i!=len){
			curLen++;
			int next=a[i];
			while(true){
				int target=next*2-first;
				auto iter=std::lower_bound(begin(a), end(a), target);
				if(iter==a.end()) break;
				curValue=next; next=*iter; curLen++;
			}
		}
		maxSubsequenceLen=std::max(maxSubsequenceLen, curLen);

		last=i;
	}
	std::cout<<len-maxSubsequenceLen<<'\n';
}