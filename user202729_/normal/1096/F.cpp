#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

struct BIT{
	std::vector<int> data;
	// represent array [1..n] ([0] is undefined)
	BIT(unsigned n):data(n+1){}

	// change suffix start at x inclusively
	void update(unsigned x,int delta){
		assert(x!=0);
		while(x<data.size()){
			data[x]+=delta;
			x+=x&-x;
		}
	}
	int operator[](unsigned x){
		assert(x!=0);
		int ans=0;
		while(x>0){
			ans+=data[x];
			x-=x&-x;
		}
		return ans;
	}
};

int const MOD=998244353;
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnum;std::cin>>nnum;
	std::vector<int> data(nnum);
	for(int& x:data)std::cin>>x;

	// consider known_inv
	BIT z(nnum);
	std::vector<char> value_known(nnum+1);
	int64_t nknown_inv=0;
	for(int i=nnum;i-->0;){
		// z[x] = number of numbers <= x and have index > i
		if(data[i]<0)continue;
		value_known[data[i]]=true;
		nknown_inv+=z[data[i]];
		z.update(data[i],1);
	}

	std::vector<int> nvalue_unknown_le(nnum+1);
	for(int i=1;i<=nnum;++i)
		nvalue_unknown_le[i]=nvalue_unknown_le[i-1]+!value_known[i];

	int exp_ninv=nknown_inv%MOD;
	int nvalue_unknown=nvalue_unknown_le[nnum];

	if(nvalue_unknown==0){
		std::cout<<exp_ninv<<'\n';
		return 0;
	}

	int inv_nvalue_unknown=0;
	{
		int64_t one=1;
		while(one%nvalue_unknown!=0)one+=MOD;
		inv_nvalue_unknown=one/nvalue_unknown;
	}

	// consider pair_unknown
	int npair_unknown=nvalue_unknown*(nvalue_unknown-1ull)/2%MOD;
	exp_ninv=(exp_ninv+npair_unknown*(MOD+1LL)/2)%MOD;

	int nbefore_unknown=0;
	for(int x:data){
		if(x<0){
			++nbefore_unknown;
			continue;
		}
		// consider (?, x)
		exp_ninv=(exp_ninv+
				nbefore_unknown
				*int64_t(nvalue_unknown-nvalue_unknown_le[x])
				%MOD*inv_nvalue_unknown
				)%MOD;
		// consider (x, ?)
		exp_ninv=(exp_ninv+
				int64_t(nvalue_unknown-nbefore_unknown)
				*nvalue_unknown_le[x]
				%MOD*inv_nvalue_unknown
				)%MOD;
	}
	std::cout<<exp_ninv<<'\n';

}