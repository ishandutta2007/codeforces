// time-limit: 2000
// problem-url: https://codeforces.com/contest/1523/problem/C

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
	std::vector<int> v;
	for(int _=0; _<n; ++_){
		int a; std::cin>>a;
		if(a==1){
			v.push_back(1);
		}else{
			while(v.back()!=a-1) v.pop_back();
			v.back()++;
		}

		std::cout<<v[0];
		for(int i=1; i<(int)v.size(); ++i)
			std::cout<<'.'<<v[i];
		std::cout<<'\n';
	}

}