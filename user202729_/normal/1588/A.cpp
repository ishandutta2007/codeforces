// time-limit: 1000
// problem-url: https://codeforces.com/contest/1588/problem/A
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
	int n; std::cin>>n;
	std::vector<int> a(n);
	for(auto& it: a) {
		std::cin>>it;
	}
	std::vector<int> b(n);
	for(auto& it: b) {
		std::cin>>it;
	}
	std::sort(begin(a), end(a));
	std::sort(begin(b), end(b));
	for(int i=0; i<n; ++i)
		if(not(a[i]==b[i] or a[i]==b[i]-1)){
			std::cout<<"NO\n";
			return;
		}
	std::cout<<"YES\n";
}