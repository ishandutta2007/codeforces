// time-limit: 1000
// problem-url: https://codeforces.com/contest/1603/problem/A
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
	for(int i=0; i<n; ++i){
		for(int f=2; f<=2+i; ++f)
			if(a[i]%f!=0){
				goto good;
			}
		std::cout<<"NO\n";
		return;
good: continue;
	}
	std::cout<<"YES\n";
	return;
}