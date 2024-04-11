#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s,t;std::cin>>s>>t;
	for(char& c:s) if(c=='C') c='B';
	for(char& c:t) if(c=='C') c='B';
	int nquery;std::cin>>nquery;

	auto const ntaila=[](std::string const& s){
		std::vector<int> ntaila(s.size()+1);
		for(unsigned i=1;i<=s.size();++i)
			ntaila[i]=s[i-1]=='A' ? ntaila[i-1]+1 : 0;
		return ntaila;
	};
	auto const nsuffixb=[](std::string const& s){
		std::vector<int> nsuffixb(s.size()+1);
		for(auto i=s.size();i--;)
			nsuffixb[i]=nsuffixb[i+1]+(s[i]=='B');
		return nsuffixb;
	};

	auto const s_ntaila=ntaila(s);
	auto const t_ntaila=ntaila(t);
	auto const s_nsuffixb=nsuffixb(s);
	auto const t_nsuffixb=nsuffixb(t);

	while(nquery--){
		int sl,sr,tl,tr;std::cin>>sl>>sr>>tl>>tr;
		--sl;--tl;

		int s_nta=std::min(sr-sl,s_ntaila[sr]);
		int s_nb=s_nsuffixb[sl]-s_nsuffixb[sr];
		int t_nta=std::min(tr-tl,t_ntaila[tr]);
		int t_nb=t_nsuffixb[tl]-t_nsuffixb[tr];

		if(s_nta>=t_nta and s_nb<=t_nb and (s_nb&1)==(t_nb&1) and
				(s_nb<t_nb or (s_nta-t_nta)%3==0)
				and not (s_nb==0 and s_nta==t_nta and s_nb<t_nb)
				){
			std::cout<<'1';
		}else{
			std::cout<<'0';
		}
	}
	std::cout<<'\n';
}
// There are so many special cases. I hope this is correct.
// UPD: Just a typo...
// UPD: ??? It's hard to generate tests for this problem.
// Yet another mistake.........
// (I didn't take the whole 30 minutes for debugging this problem. I spent some time to try to solve E too.)
// UPD: Logical error.
// UPD: Another logical error.
// I hate such kinds of problems, /.{14}\./
// UPD: