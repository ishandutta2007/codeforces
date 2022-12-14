#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

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


template<class T>
struct undoable_vector{
	std::vector<T> d;
	struct undo_entry{
		int ind;T val;
	};
	std::vector<undo_entry> undost;

	int operator[](int ind)const{
		return d[ind];
	}
	void set(int ind,T val){
		undost.push_back({ind,std::move(d[ind])});
		d[ind]=std::move(val);
	}
	void undoto(std::size_t pos){
		assert(pos<=undost.size());
		for(auto z=undost.size()-pos;z--;){
			auto [ind,val]=std::move(undost.back());
			undost.pop_back();
			d[ind]=std::move(val);
		}
	}

	auto size()const{return d.size();}
};

struct DSU{
	undoable_vector<int> p;
	int ncc;

	DSU():p(){}
	DSU(int n):p(){reset(n);}
	void reset(int n){
		ncc=n;
		p.undost.clear();
		p.d.assign(n,-1);
	}
	int root(int x){
		// return p[x]>=0?p.set(x, root(p[x])):x;
		return p[x]>=0 ? root(p[x]) : x;
	}
	void join(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;

		assert(p[a]<0 and p[b]<0);
		if(p[a]==p[b]) p.set(a,p[a]-1);
		else if(p[a]>p[b]) std::swap(a,b);
		--ncc;
		p.set(b,a);
	}

	void undoto(std::size_t pos,int old_ncc){
		ncc=old_ncc;
		p.undoto(pos);
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode,nedge,nbit;std::cin>>nnode>>nedge>>nbit;
	std::vector<int64_t> c(nnode); for(auto& x:c)std::cin>>x;

	struct edge{ int x,y; };
	std::map<int64_t,std::vector<edge>> edges_map;

	std::vector<modular> p2(nnode+1);
	std::generate(begin(p2),end(p2),[x=modular(1)/2] () mutable { return x+=x; });

	DSU dd(nnode);
	for(int z=nedge;z--;){
		int u,v;std::cin>>u>>v;
		--u;--v;
		if(c[u]==c[v]){
			dd.join(u,v); // (u in A) != (v in A)
		}else{
			edges_map[c[u] xor c[v]].push_back({u,v});
		}
	}
	
	auto checkpt=dd.p.undost.size();
	auto old_ncc=dd.ncc;

	modular out=0;
	if(old_ncc==nnode){ // case virus value = 0
		out+=p2[nnode];
	}

	for(auto const& [virusval,edges]:edges_map){
		for(auto [u,v]:edges){
			// for virusval = virusval, (u in A) == (v in A)
			dd.join(u,v);
		}
		out+=p2[dd.ncc];
		dd.undoto(checkpt,old_ncc);
	}

	// case virus value != 0 and not a key in edges_map
	auto nvirusvalue=modular((1LL<<nbit) - 1 - edges_map.size());
	out+=nvirusvalue*p2[old_ncc];

	std::cout<<(int)out<<'\n';

}