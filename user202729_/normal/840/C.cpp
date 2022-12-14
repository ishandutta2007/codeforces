#ifndef LOCAL
#define NDEBUG
#endif
#include<map>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<iostream>
#include<vector>

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int const MOD=1000000007;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	constexpr modular(int64_t v):val(int(v%MOD)){
		if(val<0)val+=MOD;
	}
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	modular operator-() const { return modular(val ? MOD-val : 0); }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) { val = int((int64_t)val*m.val%MOD); return *this; }
	modular constexpr pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular constexpr inv() const {
		int a=val,b=MOD, ax=1,bx=0;
		while(b){
			int q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	modular constexpr& operator/=(modular m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) friend modular constexpr operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

std::vector<modular> factt{1};

void ensure_fact(int x){
	while(x>=(int)factt.size())
		factt.push_back(factt.back()*factt.size());
}

modular fact(int x){
	//ensure_fact(x);
	return factt[x];
}

std::vector<modular> invfactt{1};

void ensure_invfact(int x){
	while(x>=(int)invfactt.size())
		invfactt.push_back(invfactt.back()/modular(invfactt.size()));
}

modular invfact(int x){
	//ensure_invfact(x);
	return invfactt[x];
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ensure_fact(n);
	ensure_invfact(n);

	std::map<int,int> a;
	for(int i=0;i<n;++i){
		int ai;
		std::cin>>ai;
		for(int i=int(std::sqrt(ai))+1;i>1;--i)
			if(ai%(i*i)==0)
				ai/=i*i;
		++a[ai];
	}

	int nnum=0;
	std::vector<modular> dp(1,1); // [number of consecutive pair with same value]

	std::vector<int> c_values(a.size());
	std::transform(begin(a),end(a),begin(c_values),[](auto x){return x.second;});
	std::sort(begin(c_values),end(c_values)); // ensure good enough performance, does not affect correctness

	// if(*std::max_element(begin(c_values),end(c_values))>(n+1)/2){ std::cout<<"0\n"; return 0; }
	// special case, does not affect correctness

	for(auto c:c_values){
		std::vector<modular> newdp;
		for(int b=(int)dp.size();b--;){
			assert(nnum==0 or b<=nnum-1);

			assert(c>0);
			for(int d=std::min(c,nnum+1); d>0; --d)
				for(int d1=std::min(d,b); d1>=std::max(0,d-(nnum+1-b)); --d1){
					int b_=b+c-d-d1;
					while(b_>=(int)newdp.size())
						newdp.push_back(0);

					/*
					newdp[b_]+=dp[b]*
						fact(c) *
						fact(c-1)/(fact(d-1)*fact(c-d)) *
						fact(b)/(fact(d1)*fact(b-d1)) *
						fact(nnum+1-b)/(fact(d-d1)*fact(nnum+1-b-(d-d1)));
						*/
					newdp[b_]+=dp[b]*
						fact(c) *
						fact(c-1)*invfact(d-1)*invfact(c-d) *
						fact(b)*invfact(d1)*invfact(b-d1) *
						fact(nnum+1-b)*invfact(d-d1)*invfact(nnum+1-b-(d-d1));
				}
		}
		dp=std::move(newdp);
		nnum+=c;
	}
	std::cout<<(int)dp[0]<<'\n';
}