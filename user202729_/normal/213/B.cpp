#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>
#include<array>


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

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int maxndigit;std::cin>>maxndigit;
	std::array<int,10> least_count;for(int& x:least_count)std::cin>>x;

	std::vector<modular> fact(maxndigit+1);
	fact[0]=1;
	for(unsigned i=1;i<fact.size();++i)fact[i]=fact[i-1]*i;

	std::vector<modular> invfact(maxndigit+1);
	std::transform(begin(fact),end(fact),begin(invfact),[](auto x){return modular(1)/x;});

	modular out=0;

	for(int ndigit=1;ndigit<=maxndigit;++ndigit){
		std::vector<std::vector<modular>> dp(11,std::vector<modular>(ndigit+1)); // [n filled digit type (0-9)][n empty position]
		dp[0][ndigit]=1;
		for(int i=0;i<10;++i){
			modular cur;
			for(int nempty=0;nempty<=ndigit;++nempty)if((cur=dp[i][nempty])!=0){
				for(int ntypei=least_count[i];ntypei<=nempty;++ntypei){
					int const a=i ? nempty : ndigit-1;
					if(i==0){
						assert(nempty==ndigit);
						if(ntypei>a)
							continue;
					}

					dp[i+1][nempty-ntypei]+=cur*fact[a]*invfact[ntypei]*invfact[a-ntypei];
				}
			}
		}
		out+=dp[10][0];
	}
	std::cout<<(int)out<<'\n';
}