// 7 minutes
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>

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
	int n,m,k;std::cin>>n>>m>>k;

	std::vector<std::vector<modular>> dp(k+1);
	// dp[k][n] = number of binary matrices with k row n column (n<=k), each row has 1 cell ==1,
	// each col has >=1 cell ==1
	dp[1].resize(2);
	dp[1][1]=1;

	for(int k1=2;k1<=k;++k1){
		dp[k1].resize(k1+1);
		for(int n1=1;n1<k1;++n1)
			dp[k1][n1]=modular(n1)*(dp[k1-1][n1]+dp[k1-1][n1-1]);
		dp[k1][k1]=modular(k1)*dp[k1-1][k1-1]; // = (k1!)
	}

	modular out=0,
			invm=modular(1)/m,
			invm_powi=invm,
			n_choose_i=n;
	for(int i=1;i<=k;
			++i,invm_powi*=invm,
			n_choose_i*=modular(n+1-i)/i){
		out+=invm_powi*n_choose_i*dp[k][i];
	}
	std::cout<<(int)out<<'\n';
}