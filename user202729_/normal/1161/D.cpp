#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

struct edge{
	int x:31;
	bool diff:1;
};
std::vector<std::vector<edge>> ad;

void addedge(int x,int y,bool diff){
	ad[x].push_back({y,diff});
	ad[y].push_back({x,diff});
}

std::vector<signed char> num;
struct non_bipartite_error{};

void dd(int x,int comp){
	assert(num[x]<0);
	assert(comp==0 or comp==1);
	num[x]=comp;
	for(auto [y,diff]:ad[x]){
		if(num[y]<0)
			dd(y,comp xor diff);
		else if(num[y]!=(comp xor diff))
			throw non_bipartite_error{};
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;std::cin>>s;
	std::reverse(begin(s),end(s));

	int out=0;
	for(int lena=(int)s.size();--lena;){
		ad.clear();ad.resize(lena+s.size()+2);
		int const abase=2;
		int const bbase=abase+lena;
		int const lenb=(int)s.size();

		for(int i=0;i<lena-i-1;++i) // a is palindrome
			addedge(abase+i, abase+lena-i-1, false);

		for(int i=0;i<lenb-i-1;++i) // b is palindrome
			addedge(bbase+i, bbase+lenb-i-1,false);

		addedge(1,abase+lena-1,false); // a starts with 1
		addedge(1,bbase+lenb-1,false);

		for(int i=0;i<(int)s.size();++i)if(s[i]!='?') // a xor b matches s
			addedge(bbase+i, i>=lena ? 0 : abase+i, s[i]=='1');

		addedge(0,1,true);

		num.assign(ad.size(),-1);
		int n_component=0;
		int two_pow_n_component=1;
		int const MOD=998244353;
		try{
			for(unsigned i=2;i<ad.size();++i)
				if(num[i]<0){
					dd(i,0);
					++n_component;
					two_pow_n_component=two_pow_n_component*2%MOD;
				}
			if(num[0]>=0 and num[1]>=0 and num[0]==num[1])
				continue;
		}catch(non_bipartite_error){
			continue;
		}

		out=(out+(num[0]>=0 ? two_pow_n_component*((MOD+1LL)/2)%MOD : two_pow_n_component))%MOD;
	}
	std::cout<<out<<'\n';
}