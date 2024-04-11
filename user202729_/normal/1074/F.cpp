/*
 * <s>Implementation-heavy problem.</s>
 *
 * ONCE AGAIN!? (related: 1007d)
 * Wrong algorithm because I dnt read sample test case 2 or cr the mid-subtrees.
 * the correct algorithm doesn't need HLD. Just pre-order traversal + ST + LCA.
 * Total impl time: ??? min *with HLD template*. (without making the mistake: unknown)
 */
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> ad;

std::vector<int> depth,par,first,last;
int firstunused;

void dd(int x,int parx){ // erase edge to parent
	par[x]=parx;
	first[x]=firstunused++;
	for(int y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));

		depth[y]=depth[x]+1;
		dd(y,x);
	}
	last[x]=firstunused;
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

struct ST{
	using lazy_t=int; // add operation
	struct data_t{
		int min,nmin;
		data_t(): min(0),nmin(1) {}
		data_t(data_t l,data_t r): min(std::min(l.min,r.min)), nmin(
				(min==l.min ? l.nmin : 0)+
				(min==r.min ? r.nmin : 0)) {};
	};

	struct node{
		lazy_t lazy;
		data_t data;
		// lazy does **not** affect val of the same node
	};
	std::vector<node> d;

	void reset(int n){
		d.resize(n*2);
		for(auto z=n;--z;){
			assert(d[z+n].data.min==0);
			d[z+n].data.nmin=1;
		}
		for(auto z=n;--z;)
			d[z].data.nmin=d[z<<1].data.nmin+d[z<<1|1].data.nmin;
	}

	private:
	static bool evaluates_to_true(auto const& fn){ // fn is evaluated in any case
		if constexpr(std::is_same_v<decltype(fn()),void>){
			fn(); return false;
		}else{
			return fn();
		}
	}
#define IS_TRUE(expr...) evaluates_to_true([&]{ return (expr); })

	public:
	static void foreach_strict_ancestors_down(int x,auto const& fn){ // fn returns true to break loop
		for(int shift=31^__builtin_clz(x);shift;--shift)
			if(IS_TRUE(fn(x>>shift))) break;
	}

	static void foreach_strict_ancestors_up(int x,auto const& fn){
		for(int y=x>>1;y;y>>=1)
			if(IS_TRUE(fn(y))) break;
	}

	static void foreach_range(int l,int r,auto const& leftfn,auto const& rightfn){
		// leftfn is called from left to right on left nodes
		// rightfn is called from right to left on right nodes
		while(l<r){
			if(l&1) if(IS_TRUE(leftfn(l++))) break;
			if(r&1) if(IS_TRUE(rightfn(--r))) break;
			l>>=1;r>>=1;
		}
	}

	int offset()const{ return int(d.size()/2u); }

	void foreach_range(int l,int r,auto const& fn){
		foreach_range(l,r,fn,fn);
	}

	void add_range(int l,int r,int delta){ // add (delta) to node range (l..r)
		assert(l<=r); if(l==r) return;
		l+=offset();r+=offset();

		// pushdown is not necessary because + is commutative
		foreach_range(l,r,[&](int node){
			d[node].lazy+=delta;
			d[node].data.min+=delta;
		});
		for(auto node:{l,r-1}){
			foreach_strict_ancestors_up(node,[&](int anc){
				d[anc].data=data_t(d[anc<<1].data,d[anc<<1|1].data);
				d[anc].data.min+=d[anc].lazy;
			});
		}
	}

	int cnt_zero() const{
		// NOTE merge operation is commutative
		assert(d[1].data.min>=0);
		assert(d[1].data.nmin>0);
		assert(d[1].data.nmin<=offset());
		return d[1].data.min==0 ? d[1].data.nmin : 0;
	}
} st;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode,nquery;std::cin>>nnode>>nquery;

	ad.resize(nnode);
	for(int z=nnode-1;z--;){
		int u,v;
		std::cin>>u>>v;
		--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	first.resize(nnode);
	last.resize(nnode);
	depth.resize(nnode);
	par.resize(nnode);
#ifdef LOCAL
	dd(1,-1);
#else
	dd(0,-1);
#endif
	init_jt();

	st.reset(nnode);
	assert(st.cnt_zero()==nnode);

	std::vector<std::set<int>> otheredges(nnode); // [x] = {elements > x}
	for(int z=nquery;z--;){
		int a,b;std::cin>>a>>b;
		--a;--b;
		if(a>b) std::swap(a,b);
		assert(a<b);
		auto [iter,inserted]=otheredges[a].insert(b);
		int delta;
		if (inserted){
			delta=1;
		}else{
			otheredges[a].erase(iter);
			delta=-1;
		}

		auto [u1,v1,w]=lca(a,b);
		if(w==b) std::swap(a,b);
		if(w==a){
			assert(u1==v1);
			st.add_range(first[u1],last[u1],delta);
			st.add_range(first[b],last[b],-delta);
		}else{
			assert(w!=a and w!=b);
			st.add_range(0,nnode,delta);
			st.add_range(first[a],last[a],-delta);
			st.add_range(first[b],last[b],-delta);
		}

		std::cout<<st.cnt_zero()<<'\n';
	}
}