#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 0
int const MOD=998244353;
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

	void asm_mul(modular m){
		auto x=(uint64_t)val*m.val;
		unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, mm;
		asm(
			"divl %4; \n\t"
			: "=a" (d), "=d" (mm)
			: "d" (xh), "a" (xl), "r" (MOD)
		);
		val= mm;
	}

	modular & operator*=(modular m) {
		//if(__builtin_is_constant_evaluated()){
		//	val = int((int64_t)val*m.val%MOD);
		//}else{
			asm_mul(m);
		//}
		return *this;
	}
	modular pow(auto p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular inv() const {
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

#define ARITHBINARYOP(OP) friend modular operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
		
	friend auto& operator<<(std::ostream& str,modular x){
		return str<<( x.val>MOD/2 ? x.val-MOD : x.val );
	}
};

// A faster way to raise multiple numbers to the same exponent (by a constant factor),
// without any assembly tricks.
// JIT might be slightly faster because of memory locality.
// Finding better addition chain might also be slightly faster.
void process(std::vector<modular>& a,int exp){
	auto const tmp=a;
	for(int bit=31^__builtin_clz(exp);bit--;){
		std::transform(begin(a),end(a),begin(a),[](auto x){ return x*x; });
		if (exp>>bit&1)
			std::transform(begin(a),end(a),begin(tmp),begin(a),[](auto x,auto y){ return x*y; });
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	auto const mul_1pow=[](modular a,int b){ // a * (-1)^b
		if(b&1) a=-a;
		return a;
	};
	auto const mul3=[](modular a){return a+a+a; };

	int i=0;
	modular three_pow_i=1; // - (3^i)

	std::vector<modular> inv(std::max(3,n+1));
	inv[1]=1;
	for(unsigned i=2;i<inv.size();++i) inv[i]=((int64_t)MOD*MOD-inv[MOD%i].val*int64_t(MOD/i))%MOD;
	// for some reason compute inv at the same time as the part below takes more time?...

	std::vector<modular> tmp_pow_base(n);
	for(;i<n;
			++i,
			three_pow_i=mul3(three_pow_i)
			){
		tmp_pow_base[i]=1-three_pow_i;
	}

	process(tmp_pow_base,n);

	i=0;
	modular ff=MOD-1; // (n choose i) * (-1)**i
	modular out=0;
	for(;i<n;
			++i,
			ff*=(MOD - (n+1-i))*inv[i]
			){
		out.val=int((out.val+(int64_t)(int)tmp_pow_base[i]*(int)ff)%MOD);
	}

	out=mul3(out);

	modular const three_pow_n_minus_one=modular(3).pow(n-1);
	auto zz = -three_pow_n_minus_one;
	auto const three_pow_n = mul3(three_pow_n_minus_one);
	auto const hh=-three_pow_n;
	out+= ( (zz+1).pow(n)-zz.pow(n) ) * mul_1pow(three_pow_n+three_pow_n, n+1);
	out+= mul_1pow(mul3( (hh+1).pow(n)-hh.pow(n) ), n);

	std::cout<<(int)out<<'\n';
}