#include<iostream>
#include<string>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::string s;s.reserve(n);std::cin>>s;

	int64_t ans=n*(n+1LL)/2-n;
	int cntl=n-(std::find(begin(s),end(s),'A'^'B'^s[0])-begin(s));
	int cntr=n-(std::find(s.rbegin(),s.rend(),'A'^'B'^s.back())-s.rbegin());
	int cntlr=std::unique(begin(s),end(s))-begin(s)-1; // destructive
	std::cout<<ans-cntl-cntr+cntlr<<'\n';
}