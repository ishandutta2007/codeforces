#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int const MOD=998244353;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	constexpr modular(auto v):val(int(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) [[nodiscard]] bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] friend modular constexpr operator-(modular x) { x.val=x.val?MOD-x.val:0; return x; }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) {
		val = int((int64_t)val*m.val%MOD);
		return *this;
	}
	[[nodiscard]] modular constexpr pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] modular constexpr inv() const {
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

#define ARITHBINARYOP(OP) [[nodiscard]] friend modular constexpr operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};



int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int len, numSegment; std::cin>>len>>numSegment;
	std::vector<int> values(len);
	for(auto &x: values) std::cin>>x;
	modular result=1;
	for(int last=-1, index=0;index<len;++index) {
		if(values[index]>len-numSegment){
			if(last>=0)
				result*=index-last;
			last=index;
		}
	}

	int64_t total=0;
	for(int value=len-numSegment+1;value<=len;++value) 
		total+=value;
	std::cout<<total<<' '<<(int)result<<'\n';
}