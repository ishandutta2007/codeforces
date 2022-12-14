// Idea: Divide it into block with size==s, then solve with complexity
// n/s * (3**s + n), which is = 1.3e9 when s ==9. Not good enough.
// Observation: the order is not important.
// Observation: value of x, y and z is the same over all values.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<vector>
#include<algorithm>
#include<iostream>

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int constexpr MOD=998244353;
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

modular constexpr INV2=modular(1)/2;

void tf(std::vector<modular>& a){
	for(auto bit=a.size();bit>>=1;)
		for(auto i=a.size();i--;)
			if(i&bit){
				auto even=a[i^bit];
				auto odd=a[i];
				a[i^bit]=even+odd;
				a[i]=even-odd;
			}
}

void itf(std::vector<modular>& a){
	int n=__builtin_ctzll(a.size());
	assert((1u<<n)==a.size());
	tf(a);
	std::transform(begin(a),end(a),begin(a),[fac=INV2.pow(n)](modular x){return x*fac;});
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nbit;std::cin>>n>>nbit;

	// unreadable code.
	std::vector<modular> v1(1<<nbit);
	std::vector<modular> v12(1<<nbit);
	std::vector<modular> v13(1<<nbit);

	int x,y,z;std::cin>>x>>y>>z;
	int aall=0;
	for(int i=n;i--;){
		int a,b,c;std::cin>>a>>b>>c;
		aall^=a;
		b^=a;
		c^=a;

		v1[0]  +=modular(1)/4;
		v1[b]  +=modular(1)/4;
		v1[c]  +=modular(1)/4;
		v1[b^c]+=modular(1)/4;

		v12[0]+=INV2;
		v12[b]+=INV2;

		v13[0]+=INV2;
		v13[c]+=INV2;
	}

	tf(v1);
	tf(v12);
	tf(v13);

	std::vector<modular> out(1<<nbit);
	modular const mx=x;
	for(int i=0;i<(1<<nbit);++i){
		out[i]=
			(mx+y+z).pow((int)v1[i])*
			(mx+y-z).pow((int)v12[i]-(int)v1[i])*
			(mx-y+z).pow((int)v13[i]-(int)v1[i])*
			(mx-y-z).pow(n-(int)v12[i]-(int)v13[i]+(int)v1[i]);
	}

	itf(out);
	for(int i=0;i<(1<<nbit);++i)
		std::cout<<int(out[i^aall])<<' ';
	std::cout<<'\n';
}