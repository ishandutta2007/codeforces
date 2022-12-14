#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

int const MOD=998244353;
int const root=31;

void add(int& a,int b){
	a+=b;if(a>=MOD)a-=MOD;
}
 
unsigned constexpr ceil_log2(unsigned x){
	return 31^__builtin_clz(2*x-1);
}
static_assert((1<<ceil_log2(4))==4,"");
static_assert((1<<ceil_log2(5))==8,"");
static_assert((1<<ceil_log2(8))==8,"");
 
unsigned constexpr revbit(unsigned x){
	x=(x&0x55555555)<<1|((x>>1)&0x55555555);
	x=(x&0x33333333)<<2|((x>>2)&0x33333333);
	x=(x&0x0f0f0f0f)<<4|((x>>4)&0x0f0f0f0f);
	x=(x&0x00ff00ff)<<8|((x>>8)&0x00ff00ff);
	return x>>16|x<<16;
}
static_assert(revbit(0x0f000fffU)==0xfff000f0U);
 
void fft(std::vector<int>& a){
	int n=ceil_log2(a.size());
	assert(a.size()==(1<<n));

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

int inv(int x,int y=MOD){
	int a=x,b=y,ax=1,bx=0;
	while(b){
		int q=a/b;
		a%=b;
		ax-=bx*q;
		std::swap(a,b);
		std::swap(ax,bx);
	}
	if(ax<0)ax+=y;
	return ax;
}

std::vector<int> fact;
int binom(int n,int k){
	if(k<0||k>n)return 0;
	return fact[n]*(int64_t)inv(fact[k]*(int64_t)fact[n-k]%MOD)%MOD;
}

void init_fact(int n){
	fact.resize(n+1);fact[0]=1;
	for(int i=1;i<=n;++i)
		fact[i]=(int64_t)(fact[i-1])*i%MOD;
}

#ifdef _GLIBCXX_DEBUG
int const NN=600;
#else
int const NN=600000;
#endif

struct red_fence{
	int height;
	int num_white_once;
	int num_white_dup;

	std::vector<int> ans;

	void compute(){

		std::vector<int> va(std::min(NN,num_white_once+1));
		std::vector<int> vb(std::min(NN,num_white_dup*2+1));

		for(unsigned i=0;i<va.size();++i)
			va[i]=binom(num_white_once,i)*(int64_t)powmod(2,i)%MOD;

		for(unsigned i=0;i<vb.size();++i)
			vb[i]=binom(2*num_white_dup,i);

		va.resize(1<<ceil_log2(va.size()+vb.size()-1));
		vb.resize(va.size());

		fft(va);
		fft(vb);
		std::transform(begin(va),end(va),begin(vb),begin(va),[](int a,int b){return int(a*(int64_t)b%MOD);});
		ifft(va);

		ans.resize(NN);
		std::copy(begin(va),begin(va)+std::min(va.size(),ans.size()),begin(ans));
	}
};



int main(){
	init_fact(NN*2);

	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nwhite,nred;std::cin>>nwhite>>nred;
	std::vector<int> whiteh(nwhite);
	for(int& x:whiteh)std::cin>>x;
	std::sort(begin(whiteh),end(whiteh));
	
	std::vector<int> wo; // numbers appears once int whiteh
	std::vector<int> wd; // numbers appears more than once int whiteh
	for(int j=0,i=1;i<=nwhite;++i){
		if(i==nwhite||whiteh[i]!=whiteh[i-1]){
			(i-j==1?wo:wd).push_back(whiteh[j]);
			j=i;
		}
	}

	std::vector<red_fence> rf(nred);
	for(auto& f:rf){
		std::cin>>f.height;
		f.num_white_once=std::lower_bound(begin(wo),end(wo),f.height)-begin(wo);
		f.num_white_dup=std::lower_bound(begin(wd),end(wd),f.height)-begin(wd);
		f.compute();
	}

	int nquery;std::cin>>nquery;
	for(int _=nquery;_--;){
		int x;std::cin>>x;
		int ans=0;
		for(auto& f:rf){
			int nwhite_good=x/2-1-f.height;
			if(nwhite_good>=0){
				//std::cerr<<f.height<<' '<<nwhite_good<<' '<<f.ans[nwhite_good]<<'\n';
				add(ans,f.ans[nwhite_good]);
			}
		}
		std::cout<<ans<<'\n';
	}
}