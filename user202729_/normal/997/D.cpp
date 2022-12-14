#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>


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
	modular constexpr pow(auto p) const {
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
		
	friend auto& operator<<(std::ostream& str,modular x){
		return str<<( x.val>MOD/2 ? x.val-MOD : x.val );
	}
};

struct Tree{
	struct edge{ int node,revind; };
	std::vector<std::vector<edge>> ad;
	Tree(int n):ad(n),par(n){}
	void read(){
		for(int z=(int)ad.size(),u,v;--z;){
			std::cin>>u>>v;
			--u;--v;
			ad[u].push_back({v,(int)ad[v].size()});
			ad[v].push_back({u,(int)ad[u].size()-1});
		}
		dd(0,-1);
	}

	std::vector<int> par;
	void dd(int x,int parx){ // does not delete parent edge
		par[x]=parx;
		for(auto [child,revind]:ad[x]) if(child!=parx) dd(child,x);
	}

	std::vector<std::vector<std::vector<modular>>> fmem,gmem;
	// fmem[hlen][vert][excl_br] = number of cycles with hlen=hlen, start at vert, does not visit excl_vert
	// gmem[hlen][vert][excl_br] = number of cycles with hlen=hlen, start at vert, does not visit excl_vert,
	// visit vert minimum number of times possible
	//
	// where: excl_vert = ad[vert][excl_br] | NOTE that parent edge are not deleted

	modular f(int hlen,int vert,int excl_br){
		if(hlen==0) return 1;
		auto& out=fmem[hlen][vert][excl_br];
		if(out.val!=-1)return out;

		out.val=0;
		for(int hl1=1;hl1<=hlen;++hl1)
			out+=g(hl1,vert,excl_br)*f(hlen-hl1,vert,excl_br);

		return out;
	}

	modular g(int hlen,int vert,int excl_br){
		if(hlen==0) return 1;
		auto& out=gmem[hlen][vert][excl_br];
		if(out.val!=-1)return out;

		out.val=0;
		assert(excl_br<=(int)ad[vert].size()); // if ==: no exclude
		for(unsigned branchx=0;branchx<ad[vert].size();++branchx){
			if(branchx!=excl_br)
				out+=f(hlen-1,ad[vert][branchx].node,ad[vert][branchx].revind);
		}

		return out;
	}


	auto solve(int hlen){
		std::vector<modular> out(hlen+1); // out[hlen] = number of cycles with half length = hlen
		for(auto mem:{&fmem,&gmem}){
			mem->resize(hlen+1);
			for(auto& memx:*mem){
				memx.clear();memx.resize(ad.size());
				for(unsigned node=0;node<ad.size();++node){
					memx[node].resize(ad[node].size()+1);
					for(auto& memitem:memx[node]) memitem.val=-1; // internal structure hack
				}
			}
		}
		for(unsigned hlen1=0;hlen1<out.size();++hlen1)
			for(unsigned node=0;node<ad.size();++node)
				out[hlen1]+=f(hlen1,node, ad[node].size());
		return out;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode1,nnode2,cyclelen;std::cin>>nnode1>>nnode2>>cyclelen;
	if(cyclelen%2!=0){
		std::cout<<"0\n"; return 0;
	}
	auto const hlen=cyclelen/2;
	Tree t1(nnode1); t1.read();
	Tree t2(nnode2); t2.read();

	std::vector<modular> fac(hlen*2+1);
	std::vector<modular> invf(fac.size());
	{
		fac[0]=1;
		for(unsigned i=1;i<fac.size();++i) fac[i]=fac[i-1]*i;

		invf[0]=invf[1]=1;
		for(unsigned i=2;i<invf.size();++i)
			invf[i]=-invf[MOD%i]*(MOD/i); // now invf array is inv

		for(unsigned i=2;i<invf.size();++i) invf[i]*=invf[i-1];
	}

	auto const binom=[&](int a,int b){ return fac[a]*invf[b]*invf[a-b]; };
	auto out1=t1.solve(hlen);
	auto out2=t2.solve(hlen);
	modular out=0;
	for(int hlen1=0;hlen1<=hlen;++hlen1){
		out+=binom(2*hlen,2*hlen1)*out1[hlen1]*out2[hlen-hlen1];
	}
	std::cout<<(int)out<<'\n';
}