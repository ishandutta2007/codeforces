// time-limit: 2000
// problem-url: https://codeforces.com/contest/1586/problem/B

// why the sudden bold text, are they matrices
// I use letters in different fonts for different variables (!)

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
	int m; std::cin>>m;
	std::vector<int> isAnyB(n);
	for(int _=0; _<m; ++_){
		int a; std::cin>>a; --a;
		int b; std::cin>>b; --b;
		int c; std::cin>>c; --c;
		isAnyB[b]=true;
	}
	for(int root=0; root<n; ++root) if(not isAnyB[root]){
		for(int other=0; other<n; ++other) if(other!=root)
			std::cout<<root+1<<' '<<other+1<<'\n';
		break;
	}
}