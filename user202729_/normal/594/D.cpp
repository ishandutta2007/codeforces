#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<cassert>

template<class T,unsigned N>
struct limvec{
	unsigned size;
	std::array<T,N> data;
	limvec():size(){}
	T& operator[](unsigned i){
		assert(i<size);
		return data[i];
	}
	void push_back(T x){
		assert(size<N);
		data[size++]=x;
	}
	typename std::array<T,N>::iterator begin(){return data.begin();}
	typename std::array<T,N>::iterator end(){return data.begin()+size;}
};

struct en{int prime,exp;};
using intfact=limvec<en,7>;
intfact factorize(int a){
	assert(a!=0);
	assert(a<=1000000);
	intfact fact;

	if(a%2u==0){
		int z=__builtin_ctz(a);
		fact.push_back({2,__builtin_ctz(a)});
		a>>=z;
	}

	for(int i=3;i*i<=a;i+=2){
		if(a%i==0){
			int e=1;
			a/=i;
			while(a%i==0){
				a/=i;
				++e;
			}
			fact.push_back({i,e});
		}
	}
	if(a!=1)
		fact.push_back({a,1});
	return fact;
}

int constexpr MOD=1000000007;

int powmod(int base,int exp){
	assert(exp>=0);
	int ans=1;
	for(;;){
		if(exp&1)ans=ans*(int64_t)base%MOD;
		if((exp>>=1)==0)return ans;
		base=base*(int64_t)base%MOD;
	}
}

int invmod(int x){
	assert(x!=0);
	return powmod(x,MOD-2);
}

struct phi_computer{
	std::vector<int> exp;
	operator int()const{
		return ans*(int64_t)invmod(ansdiv)%MOD;
	}

	phi_computer():exp(999984),ans(1),ansdiv(1){}

	void operator*=(std::pair<intfact,int>& z){
		for(auto e:z.first)
			partial_mul(e);
		ans=(int64_t)ans*z.second%MOD;
	}

	void operator/=(std::pair<intfact,int>& z){
		for(auto e:z.first)
			partial_div(e);
		ansdiv=(int64_t)ansdiv*z.second%MOD;
	}

private:
	int ans,ansdiv;

	void partial_div(en x){
		assert(x.prime!=1);
		exp[x.prime]-=x.exp;
		assert(exp[x.prime]>=0);
		if(exp[x.prime]==0){
			ansdiv=ansdiv*(x.prime-1LL)%MOD;
			ans=ans*(int64_t)x.prime%MOD;
		}
	}
	void partial_mul(en x){
		assert(x.prime!=1);
		if(exp[x.prime]==0){
			ans=ans*(x.prime-1LL)%MOD;
			ansdiv=ansdiv*(int64_t)x.prime%MOD;
		}
		exp[x.prime]+=x.exp;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<std::pair<intfact,int>> a(n);
	for(auto& x:a){
		int ai;std::cin>>ai;
		x={factorize(ai),ai};
	}

	struct query{
		int index,l,r;
	};
	int nquery;std::cin>>nquery;
	std::vector<query> queries(nquery);
	for(int i=0;i<nquery;++i){
		queries[i].index=i;
		std::cin>>queries[i].l>>queries[i].r;
		--queries[i].l;
	}

	std::sort(queries.begin(),queries.end(),[](query a,query b){
		unsigned constexpr BLOCKSIZE=512;
		if(a.l/BLOCKSIZE==b.l/BLOCKSIZE)
			if((a.l/BLOCKSIZE)&1)
				return a.r<b.r;
			else
				return a.r>b.r;
		return a.l<b.l;
	});

	phi_computer f;
	int l=0,r=0;
	std::vector<int> ans(nquery);
	for(auto q:queries){
		while(r<q.r) f*=a[r++];
		while(l>q.l) f*=a[--l];
		while(r>q.r) f/=a[--r];
		while(l<q.l) f/=a[l++];
		ans[q.index]=int(f);
	}
	for(auto x:ans)
		std::cout<<x<<'\n';
}