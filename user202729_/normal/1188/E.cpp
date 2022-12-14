// [I didn't read the editorial or see any failed test cases]
// Read TODO below. Please hack this solution if possible {and this solution passes the existing tests.
// (however Codeforces doesn't support uphacking solutions on old contests)
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>

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

std::vector<modular> fact{1};
modular binom(int n,int k){
	k=std::min(k,n-k);
	if(k<0)return 0;
	while(n>=(int)fact.size())
		fact.push_back(fact.back()*modular(fact.size()));
	return fact[n]/(fact[k]*fact[n-k]);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	int req=0; // number of "forced blocks"
	std::priority_queue<int,std::vector<int>,std::greater<int>> q; // next positions for increasing req

	std::vector<int> a(n);
	for(int& ai:a){
		std::cin>>ai;
		q.push(ai);
	}

	std::vector<modular> f(1,1); // [i] = number of resulting states reachable from moving i steps
	modular out=0;

	for(int i=0;;++i){
		if(i>=n and f[i]==f[i-n]) // TODO is this okay? What if f[i] - f[i-n] is some nonzero multiple of MOD?
			break;

		out+=f[i];
		if(i>=n) out-=f[i-n];

		assert(f.size()==i+1u); 

		while(q.top()==i){
			q.pop();
			q.push(i+n);
			++req;
		} // TODO is the total complexity of this loop O(n)?

		if(req>i+1) break;
		f.push_back(binom(i+1-req + n-1,n-1));
	}

	std::cout<<(int)out<<'\n';
}