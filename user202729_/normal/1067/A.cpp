#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<array>
#include<numeric>
#include<algorithm>

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
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

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::array<std::array<modular,2>,200> dp{}; // [lastvalue][leq_prev (ok)] = nchoice
	int ai;
	std::cin>>ai; --ai;
	if(ai<0)
		for(ai=0;ai<dp.size();++ai) dp[ai][false]=1;
	else
		dp[ai][false]=1;

	for(int i=1;i<n;++i){
		decltype(dp) dpnxt{};

		for(int i=0;i<dp.size();++i) dp[i][false]+=dp[i][true];
		for(int i=1;i<dp.size();++i) dp[i][false]+=dp[i-1][false];
		for(auto i=dp.size();--i;) dp[i-1][true]+=dp[i][true];

		auto const proc=[&](int ai){
			if(ai) dpnxt[ai][false]+=dp[ai-1][false];

			dpnxt[ai][true]+=dp[ai][false];
			if(ai) dpnxt[ai][true]-=dp[ai-1][false];

			if(ai+1<dp.size()) dpnxt[ai][true]+=dp[ai+1][true];
		};

		std::cin>>ai; --ai;
		if(ai<0)
			for(ai=0;ai<dp.size();++ai) proc(ai);
		else proc(ai);

		dp=dpnxt;
	}

	modular out=0;
	for(auto const& row:dp) out+=row[true];
	std::cout<<(int)out<<'\n';
}