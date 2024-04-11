// Funny bug that only happens when sizeof(size_t) < size_t(int64_t).

#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
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

int const MAX_MAX_NVISIT=12;
int const MAX_MAX_INC=4;
int n,nvisit,maxinc;

template<int MAX_NVISIT=1>
int solve(){
	assert(nvisit<=MAX_MAX_NVISIT);
	if constexpr(MAX_NVISIT<MAX_MAX_NVISIT)
		if(nvisit>MAX_NVISIT)
			return solve<MAX_NVISIT+1>(); // "dynamic static array". Avoid accidental out of bound (int debug mode).
	// Of course if MAX_MAX_NVISIT is set incorrectly then it would still cause problem...
	// A disadvantage is that when there's some warning it will be duplicated 12 times.

	assert(maxinc<=MAX_MAX_INC);

	int i=0;

	std::vector<std::array<std::array<modular,1<<MAX_MAX_INC>,MAX_NVISIT+1>> dpi,dpnext /* dp[i+1] */;
	// # of first, n seg, n visited, prev is tail[maxinc] = n path
	// (prev is tail)[maxinc-1] = most recent .. [0] = least recent (leftmost)
	dpi.resize(2);
	dpi[1 /* for simplicity assumes that there's a "past-the-end" segment */ ][0][0b0000]=1;

	std::array<modular,200> out; // Surprisingly large? Replacing 200 with 40 does not work for nvisit>=7.
	while(true){
		while(not dpi.empty() and
				std::all_of(begin(dpi.back()),end(dpi.back()),
					[](auto const& x){ return std::all_of(begin(x),end(x),[](auto y){ return y==0; }); }))
			dpi.pop_back();
		if(dpi.empty()) break;
		// I guess now dpi.size() is int O(1)?

		dpnext.clear(); dpnext.resize(dpi.size()+1);
		for(auto nseg=dpi.size();--nseg;)
		for(auto nvisited=0;nvisited<=nvisit;++nvisited)
		for(auto prevtail=1<<maxinc;prevtail--;){
			auto const cur=dpi[nseg][nvisited][prevtail];
			if(cur==0) continue;

			for(auto tmp=prevtail;tmp;tmp^=tmp&-tmp){
				auto prevtail_bit=tmp&-tmp;
				auto prevtail_rem=prevtail^prevtail_bit;
				assert(prevtail_rem!=prevtail);
				if(prevtail_rem&1) continue;

				// consider (prevtail_bit) connected to [i]
				if(nvisited!=nvisit)
					dpnext[nseg][nvisited+1][prevtail_rem>>1 | 1<<(maxinc-1)]+=cur; // nxt[i] after i (not inserted)
				if(nseg>1)
					if(nvisited!=nvisit)
						dpnext[nseg-1][nvisited+1][prevtail_rem>>1]+=cur*(nseg-1); // nxt[i] before i (existing)
			}

			if(not (prevtail&1)){
				// consider none existing connected to i
				dpnext[nseg][nvisited][prevtail>>1]+=cur; // none at [i]
				if(nvisited!=nvisit){
					dpnext[nseg][nvisited+1][prevtail>>1]+=cur*nseg; // i -> existing (i is not tail)
					dpnext[nseg+1][nvisited+1][prevtail>>1 | 1<<(maxinc-1)]+=cur; // i -> none (i is tail)
				}
			}
		}

		out[i]=1<=dpi.size() ? dpi[1][nvisit][0b0000] : 0;

		++i;
		std::swap(dpi,dpnext);
		if(i==n or i==(int)out.size()) break;
	}

	if(dpi.empty() and i<=n) return 0;
	else if(i==n) return (int)dpi[1][nvisit][0b0000];
	else assert(n>=(int)out.size());

	// interpolate with values ( (i,out[i]) for i = [out.size()/2 .. out.size()[ )
	auto const val=[&](int n){
		modular outt=0;
		for(auto i=(int)out.size()/2;i<out.size();++i){
			modular tmp=out[i];
			for(auto j=(int)out.size()/2;j<out.size();++j) if(j!=i) tmp*=modular(n-j)/(i-j);
			outt+=tmp;
		}
		return outt;
	};

	for(auto i=out.size()/2;i<out.size();++i) assert(val(int(i))==out[i]);

	return (int)val(n);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::cin>>n>>nvisit>>maxinc;
	std::cout<<solve()<<'\n';
}