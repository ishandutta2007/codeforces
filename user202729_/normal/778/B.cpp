#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<algorithm>
#include<iostream>
#include<array>
#include<string>
#include<map>

using bit=std::array<char,2>;
template<int type>
bit fn(bit x,bit y){
	std::transform(begin(x),end(x),begin(y),begin(x),[](char a,char b){
			return char(
				type==1 ? a&b :
				type==2 ? a|b :
				a^b);
				});
	return x;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nvar,nbit;std::cin>>nvar>>nbit;

	std::map<std::string,std::vector<bit>> vars;
	vars["?"].assign(nbit,bit{0,1});

	std::string v,s,op,t;
	std::vector<std::array<int,2>> sum(nbit);
	for(int z=nvar;z--;){
		std::cin>>v;
		std::cin.ignore(4,'=');

		std::cin>>s;
		std::vector<bit> val(nbit);
		if(s[0]=='0' or s[0]=='1')
			std::transform(begin(s),end(s),begin(val),[](char c){return bit{c-'0',c-'0'};});
		else{
			std::cin>>op>>t;
			auto const vs=vars.at(s);
			auto const vt=vars.at(t);
			std::transform(begin(vs),end(vs),begin(vt),begin(val),
					op=="AND" ? fn<1> :
					op=="OR" ? fn<2> :
					fn<3>);
		}

		std::transform(begin(sum),end(sum),begin(val),begin(sum),[](auto x,bit y){
				x[0]+=y[0];
				x[1]+=y[1];
				return x;
				});
		vars[v]=std::move(val);
	}

	for(auto x:sum)
		std::cout<<(x[1]<x[0] ? '1' : '0');
	std::cout<<'\n';

	for(auto x:sum)
		std::cout<<(x[1]>x[0] ? '1' : '0');
	std::cout<<'\n';
}