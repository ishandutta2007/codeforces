// time-limit: 2000
// problem-url: https://codeforces.com/contest/1609/problem/B
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	int numQuery; std::cin>>numQuery;
	std::string s; std::cin>>s;

	int count {};
	auto const weight=[&](int i)->int{
		return s[i]=='a' and s[i+1]=='b' and s[i+2]=='c';
	};
	for(int i=0; i<(int)s.size()-2; ++i)
		count+=weight(i);

	for(int _=0; _<numQuery; ++_){
		int pos; std::cin>>pos; --pos;
		char ch; std::cin>>ch;

		int left=std::max(pos-2, 0), right=std::min(pos+1, (int)s.size()-2);
		for(int i=left; i<right; ++i) count-=weight(i);
		s[pos]=ch;
		for(int i=left; i<right; ++i) count+=weight(i);
		std::cout<<count<<'\n';
	}
}