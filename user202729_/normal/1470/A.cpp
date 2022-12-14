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
	int n, m; std::cin>>n>>m;
	std::vector<int> k(n); for(auto& it: k) std::cin>>it;
	std::vector<int> c(m); for(auto& it: c) std::cin>>it;

	int64_t result{};
	std::sort(begin(k), end(k));
	for(int i=0; i<n; ++i)
		result+=std::min(c[k[i]-1], n-1-i>=(int)c.size() ? INT_MAX: c[n-1-i]);
	std::cout<<result<<'\n';
}