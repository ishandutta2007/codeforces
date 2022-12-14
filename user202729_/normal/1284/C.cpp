#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int MOD;
struct modular {
	int val;
	explicit  operator int() const { return val; }
	 modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	 modular(int64_t v):val(int(v%MOD)){
		if(val<0)val+=MOD;
	}
#else
	 modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool  operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	modular operator-() const { return modular(val ? MOD-val : 0); }
	modular & operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular & operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular & operator*=(modular m) { val = int((int64_t)val*m.val%MOD); return *this; }
	modular  pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular  inv() const {
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
	modular & operator/=(modular m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) friend modular  operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n>>MOD;
	std::vector<modular> fact(n+1);
	fact[0]=1;
	for(unsigned i=1;i<fact.size();++i) fact[i]=fact[i-1]*i;

	modular out=0;
	for(int framelen=1;framelen<=n;++framelen)
		out+=fact[framelen]*fact[n-framelen+1]*(n-framelen+1);
	std::cout<<(int)out<<'\n';
}