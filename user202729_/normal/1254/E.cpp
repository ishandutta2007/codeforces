// [I didn't read the editorial or see any failed test cases]
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>

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

std::vector<std::vector<int>> ad;

std::vector<int> depth,par,preorder;
void dd(int x){ // dfs compute depth, par, prepare for init_jt
	preorder.push_back(x);
	for(int y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		par[y]=x;
		depth[y]=depth[x]+1;
		dd(y);
	}
}

std::vector<std::vector<int>> jt;
void init_jt(){
	jt.push_back(par);
	for(;;){
		bool useful=false;
		auto const& a=jt.back();
		auto b=a;
		for(auto& x:b)if(x>=0){
			if((x=a[x])>=0)
				useful=true;
		}
		if(useful)
			jt.push_back(std::move(b));
		else
			break;
	}
}

struct lca_result {
	int u1,v1,lca; // u1,v1: child of lca int the direction of u/v resp.
	// int case lca is u or v, both u1 and v1 are int the direction of the node != lca
};
lca_result lca(int u,int v){
	assert(u!=v);

	bool swapped;
	if((swapped=(depth[u]<depth[v])))std::swap(u,v);

	int ddepth=depth[u]-depth[v];
	if(ddepth){
		--ddepth;
		for(;ddepth;ddepth^=ddepth&-ddepth){
			u=jt[__builtin_ctz(ddepth)][u];
		}
		assert(depth[u]-1==depth[v]);
		if(jt[0][u]==v)return {u,u,v};
		u=jt[0][u];
	}
	assert(u!=v);
	for(auto layer=jt.size();layer--;){
		if(jt[layer][u]!=jt[layer][v])
			std::tie(u,v)=std::make_pair(jt[layer][u],jt[layer][v]);
	}
	assert(jt[0][u]==jt[0][v]);
	if(swapped)std::swap(u,v);
	assert(u!=v);
	return {u,v,jt[0][u]};
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ad.resize(n);
	for(int z=n;--z;){
		int u,v;std::cin>>u>>v;
		ad[--u].push_back(--v);
		ad[v].push_back(u);
	}
	preorder.reserve(n);
	depth.resize(n);
	par.resize(n);
	par[0]=-1;
	dd(0);
	init_jt();
	for(int i=1;i<n;++i) ad[i].push_back(par[i]);

	int const BEFOREFIRST=-1,AFTERLAST=-2;

	// restriction on edge order adjacent to node i:
	std::vector<std::map<int,int>> adc(n);
	// {u,v} in adc[i]: edge i..u is right before edge i..v

	// can this work without map?
	
	if(false){
failed:
		std::cout<<"0\n";
		return 0;
	}

	int sumdist=0;
	for(int u_=0;u_<n;++u_){
		int u=u_;
		int v;std::cin>>v;
		if(v==0)continue;
		--v;

		if(u==v)goto failed;

		int ulast=BEFOREFIRST,vlast=AFTERLAST;
		bool flipped=false;
		while(u!=v){
			if(depth[v]>depth[u]){ std::swap(u,v); std::swap(ulast,vlast); flipped^=1; continue; }

			// shrink u towards par[u]
			{
				int x=ulast,y=par[u];
				assert(par[u]>=0);
				if(flipped) std::swap(x,y);
				assert(y!=BEFOREFIRST and x!=AFTERLAST);
				auto [iter,success]=adc[u].insert({x,y});
				assert(iter->first==x);
				if(not success and iter->second!=y)goto failed;
			}
			ulast=u;
			u=par[u];

			++sumdist;
			if(sumdist>2*(n-1))goto failed;
		}

		{
			int x=ulast,y=vlast;
			if(flipped) std::swap(x,y);
			assert(y!=BEFOREFIRST and x!=AFTERLAST);
			auto [iter,success]=adc[u].insert({x,y});
			assert(iter->first==x);
			if(not success and iter->second!=y)goto failed;
		}
	}

	modular out=1;

	std::vector<int> indeg(n);
	std::vector<char> vis(n); // visited

	for(int x=0;x<n;++x){
		for(auto a:ad[x]){ indeg[a]=0; vis[a]=false; }
		int indeg_afterlast=0;
		for(auto [a,b]:adc[x]){
			assert(b!=BEFOREFIRST);
			if(b<0){
				assert(b==AFTERLAST);
				++indeg_afterlast;
			}else
				++indeg[b];
		}

		if(indeg_afterlast>=2)goto failed;
		for(auto a:ad[x])
			if(indeg[a]>=2)goto failed;

		bool fixed_order=false;
		{
			auto iter=adc[x].find(BEFOREFIRST);
			if(iter!=end(adc[x])){
				assert(indeg[iter->second]==1);

				int const a=iter->second;
				int b=a;
				while(true){
					if(b==AFTERLAST){
						fixed_order=true;
						break;
					}

					assert(not vis[b]);
					vis[b]=true;
					auto iter=adc[x].find(b);
					if(iter==end(adc[x]))break;

					b=iter->second;
					if(b==a)goto failed;
				}
			}
		}

		if(not fixed_order)
		for(auto a:ad[x])if(indeg[a]==0){
			int b=a;
			while(true){
				if(b==AFTERLAST)break;

				assert(not vis[b]);
				vis[b]=true;
				auto iter=adc[x].find(b);
				if(iter==end(adc[x]))break;

				b=iter->second;
				if(b==a)goto failed;
			}
		}

		for(auto a:ad[x])if(not vis[a]){
			assert(std::cout<<"");
			goto failed;
		}

		int ncomp=(int)ad[x].size()+2 /* BEFOREFIRST, AFTERLAST */ -(int)adc[x].size();
		if(ncomp>3)
			for(int i=ncomp-2;i;--i) out*=i;
	}
	std::cout<<(int)out<<'\n';
}