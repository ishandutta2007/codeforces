#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<algorithm>
#include<set>
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

struct ST{
	using T=modular;
	struct node{
		// [p1, p2, ..., pn] =>
		T sp; // 1 + p1 + p1 p2 + ... + (p1 p2 .. pn)
		T prod; // p1 p2 .. pn

		constexpr node():sp(1),prod(1){}
		constexpr node(T p1):sp(1+p1),prod(p1){}
		constexpr node(node l,node r):
			sp(l.sp+(r.sp-1)*l.prod),
			prod(l.prod*r.prod)
		{}

		auto constexpr etime_pass()const{
			return (sp-prod)/prod;
		}
	};

	std::vector<node> d;
	ST(std::vector<int> const& probpercent):d(probpercent.size()*2){
		std::transform(begin(probpercent),end(probpercent),begin(d)+probpercent.size(),
				[inv100=T(1)/100](int x){ return inv100*x; });
		for(auto i=probpercent.size();--i;)
			d[i]=node(d[i<<1],d[i<<1|1]);
	}

	node get(int l,int r)const{
		l+=int(d.size()/2);
		r+=int(d.size()/2);
		node outl,outr;
		while(l<r){
			if(l&1) outl=node(outl,d[l++]);
			if(r&1) outr=node(d[--r],outr);
			l>>=1;r>>=1;
		}
		return node(outl,outr);
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nq;std::cin>>n>>nq;
	std::vector<int> probpercent(n);
	for(int& x:probpercent)std::cin>>x;

	ST st(probpercent);
	std::set<int> check{0,n};
	auto val=st.get(0,n).etime_pass();
	while(nq--){
		int u;std::cin>>u;--u;
		auto [iter,inserted]=check.insert(u);
		if(inserted){
			auto nxt=std::next(iter);
			auto pre=std::prev(iter);
			val-=st.get(*pre,*nxt).etime_pass();
			val+=st.get(*pre,u).etime_pass();
			val+=st.get(u,*nxt).etime_pass();
		}else{
			auto nxt=check.erase(iter);
			auto pre=std::prev(nxt);
			val-=st.get(*pre,u).etime_pass();
			val-=st.get(u,*nxt).etime_pass();
			val+=st.get(*pre,*nxt).etime_pass();
		}
		std::cout<<(int)val<<'\n';
	}
}