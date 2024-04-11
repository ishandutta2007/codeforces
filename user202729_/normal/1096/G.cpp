#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

int const MOD=998244353;
int const root=31;

unsigned constexpr ceil_log2(unsigned x){
	return 31^__builtin_clz(2*x-1);
}
static_assert((1<<ceil_log2(4))==4,"");
static_assert((1<<ceil_log2(5))==8,"");
static_assert((1<<ceil_log2(8))==8,"");

unsigned constexpr revbit(unsigned x){
	x=(x&0x55555555)<<1|(x>>1)&0x55555555;
	x=(x&0x33333333)<<2|(x>>2)&0x33333333;
	x=(x&0x0f0f0f0f)<<4|(x>>4)&0x0f0f0f0f;
	x=(x&0x00ff00ff)<<8|(x>>8)&0x00ff00ff;
	return x>>16|x<<16;
}
static_assert(revbit(0x0f000fffU)==0xfff000f0U);

void fft(std::vector<int>& a){
	int n=ceil_log2(a.size());
	a.resize(1<<n);
	std::vector<int> roots={root};
	while(roots.back()!=MOD-1){
		roots.push_back(roots.back()*(int64_t)roots.back()%MOD);
	}

	for(unsigned i=1;i<a.size();++i){
		unsigned j=revbit(i)>>(32-n);
		if(i<j)std::swap(a[i],a[j]);
	}

	for(unsigned blocksize=1;blocksize<a.size();blocksize<<=1){
		int w=roots.back();
		roots.pop_back();
		for(unsigned base=0;base<a.size();base+=blocksize*2)
			for(unsigned i=0,x=1;i<blocksize;++i,x=x*(int64_t)w%MOD){
				int& even=a[base+i];
				int& odd=a[base+blocksize+i];
				int e1=(even+x*(int64_t)odd)%MOD;
				int o1=(even+MOD*(int64_t)MOD-x*(int64_t)odd)%MOD;
				even=e1;odd=o1;
			}
	}
}

int powmod(int base,int exp){
	int result=1;
	while(true){
		if(exp&1)result=result*(int64_t)base%MOD;
		if(0==(exp>>=1))return result;
		base=base*(int64_t)base%MOD;
	}
}

void ifft(std::vector<int>& a){
	assert(a.size()==(1<<__builtin_ctz(a.size())));
	std::reverse(++a.begin(),a.end());
	fft(a);
	int invn=powmod(a.size(),MOD-2);;
	for(int& x:a)x=x*(int64_t)invn%MOD;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ndigit,k;std::cin>>ndigit>>k;
	std::vector<int> poly(10);
	while(k--){int x;std::cin>>x;poly[x]=1;}
	while(poly.back()==0)poly.pop_back();

	ndigit/=2u;
	poly.resize((poly.size()-1)*ndigit+1);
	fft(poly);
	for(int& x:poly)
		x=powmod(x,ndigit);
	ifft(poly);

	int ans=0;
	for(int x:poly)
		ans=(x*(int64_t)x+ans)%MOD;
	std::cout<<ans<<'\n';
}