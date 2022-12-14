// .........

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>

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

#include<string>
#include<vector>
#include<functional>
#include<algorithm>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s;
	std::cin>>s;

	std::vector<modular> fact(s.size()+1);
	std::vector<modular> pow2(s.size()+1);
	fact[0]=1;
	pow2[0]=1;
	for(unsigned x=1;x<=s.size();++x){
		fact[x]=fact[x-1]*x;
		pow2[x]=pow2[x-1]*2;
	}

	auto const binom=[&](int a,int b){
		b=std::min(b,a-b);
		return b<0 ? 0 : fact[a]/(fact[b]*fact[a-b]);
	};

	modular out=0;

	auto nqu=std::count(begin(s),end(s),'?');
	auto nop=std::count(begin(s),end(s),'(');

	int nqux=std::count(begin(s),end(s)-nop,'?');
	int nopx=std::count(begin(s),end(s)-nop,'(');

	for(int nop1=0;;){
		// now nqux, nopx = count of qu ('?'), op ('(') at indices < s.size()-nop-nop1
		assert(nqux==std::count(begin(s),end(s)-nop-nop1,'?'));
		assert(nopx==std::count(begin(s),end(s)-nop-nop1,'('));
		out+=nopx*binom(nqu,nop1);
		out+=nqux*binom(nqu-1,nop1-1);

		++nop1;
		if(nop1>(int)s.size()-1-nop)break;
		nqux-=s[s.size()-nop-nop1]=='?';
		nopx-=s[s.size()-nop-nop1]=='(';
		assert(nqux>=0);
		assert(nopx>=0);
	}
	std::cout<<(int)out<<'\n';
}