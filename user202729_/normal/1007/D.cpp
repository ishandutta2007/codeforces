// [I didn't read the editorial or see any failed test cases]
// Optimal solution use unique_ptr (instead of shared_ptr), but let's see how fast can shared_ptr be...
// CHANGELOG: Added some missing std::move + use_count check. (essentially emulate unique_ptr when possible)
// In this particular case, because persistent is not necessary, the code runs very fast.
#ifndef LOCAL
#define NDEBUG
#endif
#include<random>
#include<memory>
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>

struct twosat_t{
	// 2SAT | variable (x) : true = node 2*x, false = node 2*x+1
	// true <-> ant (x) use path 1
	std::vector<std::vector<int>> ad;
	std::vector<int8_t> val;

	void addedge(int x,int y){
		ad[x].push_back(y);
		ad[y^1].push_back(x^1);
	}

	private:
	std::vector<std::vector<int>> rad;

	std::vector<int> postorder;
	std::vector<char> visited;
	void dd(int x){
		if(visited[x])return;
		visited[x]=true;
		for(int y:ad[x])
			dd(y);
		postorder.push_back(x);
	}

	void fill(int x){ // throws 0 if 
		if(val[x]==false)
			return;
		if(val[x]==true)
			throw 0;
		val[x]=false;
		val[x^1]=true;
		for(int y:rad[x])
			fill(y);
	}

	public:
	void run(){ // fill (val). val is empty if not assignable
		assert(not ad.empty());
		assert(rad.empty());
		{
			std::vector<int> rdeg(ad.size());
			for(auto const& adx:ad)
				for(int y:adx)
					++rdeg[y];

			rad.resize(ad.size());
			for(auto y=ad.size();y--;)
				rad[y].reserve(rdeg[y]);

			for(int x=(int)ad.size();x--;)
				for(int y:ad[x])
					rad[y].push_back(x);
		}

		postorder.clear();
		postorder.reserve(ad.size());
		visited.assign(ad.size(),false);
		for(int i=(int)ad.size();i--;){
			for(int x:ad[i])
				assert(std::find(begin(ad[x^1]),end(ad[x^1]),i^1)!=end(ad[x^1])); // (i=>x) => (x^1=>i^1)
			dd(i);
		}

		val.assign(ad.size(),-1);
		try{
			for(auto i=postorder.size();i--;)if(val[postorder[i]]<0){
				fill(postorder[i]);
			}
			assert(std::all_of(begin(val),end(val),[](int8_t x){return x==0 or x==1;}));
		}catch(int){
			val.clear();
		}
	}
} twosat;

std::vector<std::vector<int>> ad;

struct pd_type{
	std::vector<int> add,sub;
};
std::vector<pd_type> path_delta; // node -> what to + or - at this node
// specifically: for [x],
// * sub = path indices int (x..par[x]) not int (par[x]..par[par[x]])
// * add = path indices int (x..par[x]) not int (x..child of x)

std::vector<int> depth,par,subtree_size;
int dd(int x){ // dfs compute depth, par and subtree_size, prepare for init_jt
	subtree_size[x]=1;
	for(int y:ad[x]){
		ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
		par[y]=x;
		depth[y]=depth[x]+1;
		subtree_size[x]+=dd(y);
	}
	return subtree_size[x];
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

int merge(int x,int y){ // return node n such that forall a, a => n is equivalent to a => x and a => y
	assert(x>=0);
	assert(y>=0);
	int n=(int)twosat.ad.size();
	twosat.ad.push_back({x,y});
	twosat.ad.emplace_back(); // node n^1
	twosat.ad[x^1].push_back(n^1);
	twosat.ad[y^1].push_back(n^1);
	return n;
}

std::mt19937 engine(123456);

// TODO implement DSU on tree without dynamic tree

struct Treapd;
using Treap=std::shared_ptr<Treapd>;
// NOTE: do not modify members (except int implementation) + not thread safe (check use_count)
// NOTE: missing std::move can have large performance penalty

Treap newtreap(int x);
Treap add(Treap t,int val);
Treap remove(Treap t,int val);
void for_each(Treap const& t,auto const fn);

struct Treapd{
	std::array<Treap,2> c;
	int key;
	decltype(engine()) pri;

	Treapd(int key):c{},key(key),pri(engine()),nodeval(key){}

	int node()const{
		if(nodeval<0){
			nodeval=key;
			for(Treap const& t:c)if(t)
				nodeval=merge(nodeval,t->node());
		}
		return nodeval;
	}

	void c_modified()const{
		nodeval=-1;
	}

	friend Treap merge(Treap a,Treap b){
		if(not a)return std::move(b);
		if(not b)return std::move(a);
		assert(a->key<b->key);
		if(a->pri>b->pri){
			if(a.use_count()>1) a=std::make_shared<Treapd>(*a);
			a->c[1]=merge(std::move(a->c[1]),std::move(b));
			a->c_modified();
			return a;
		}else{
			if(b.use_count()>1) b=std::make_shared<Treapd>(*b);
			b->c[0]=merge(std::move(a),std::move(b->c[0]));
			b->c_modified();
			return b;
		}
	}

	friend std::pair<Treap,Treap> split(Treap a,int key){
		if(not a) return {};
		if(a.use_count()>1) a=std::make_shared<Treapd>(*a);
		if(a->key>=key){
			auto [x,y]=split(std::move(a->c[0]),key);
			a->c[0]=std::move(y);
			a->c_modified();
			return {std::move(x),std::move(a)};
		}else{
			auto [x,y]=split(std::move(a->c[1]),key);
			a->c[1]=std::move(x);
			a->c_modified();
			return {std::move(a),std::move(y)};
		}
	}

	friend Treap newtreap(int x){
		return std::make_shared<Treapd>(x);
	}

	friend Treap add(Treap t,int val){
		auto [x,y]=split(std::move(t),val);
		return merge(std::move(x),merge(newtreap(val),std::move(y)));
	}

	friend Treap remove(Treap t,int val){
		auto [x,y]=split(std::move(t),val);
		auto [z,u]=split(std::move(y),val+1);
		assert(z);
		return merge(std::move(x),std::move(u));
	}

	friend void for_each(Treap const& t,auto const fn){
		if(not t) return;
		if(t->c[0]) for_each(t->c[0],fn);
		fn(t->key);
		if(t->c[1]) for_each(t->c[1],fn);
	}

private:
	Treapd(Treap left,int key,Treap right): c({std::move(left),std::move(right)}),
		key(key),pri(engine()),nodeval(-1){};

	mutable int nodeval; // merge of all keys int the treap, or -1
};


// "DSU on tree" - inefficient solution
struct negated_path_indices{
	Treap t;int size=0;
	void add(int negated_pathind){ // also add condition to twosat
		++size;
		if(t)
			twosat.addedge(negated_pathind^1, t->node());
		t=::add(std::move(t),negated_pathind);

	}

	void add(negated_path_indices const& zz){
		if(zz.size ==0)return;
		assert(size>=zz.size);

		int const x=t->node();
		int const y=zz.t->node();

		twosat.addedge(x^1, y);

		for_each(zz.t, [this](int negated_pathind){
			t=::add(std::move(t),negated_pathind);
			});
		size+=zz.size;
	}

	void remove(int negated_pathind){
		t=::remove(std::move(t),negated_pathind);
		--size;
		assert(size>=0);
	}
};

negated_path_indices de(int x){ // return negation of pathind values intersects edge x..par[x]
	negated_path_indices out;
	for(int y:ad[x]){
		negated_path_indices cur=de(y);
		for(int z:path_delta[y].sub)
			cur.remove(z^1);

		if(out.size<cur.size)
			std::swap(out,cur);

		out.add(cur);
	}

	for(auto x:path_delta[x].add) out.add(x^1);

	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode;std::cin>>nnode;
	ad.resize(nnode);
	for(int z=nnode,u,v;--z;){
		std::cin>>u>>v;
		--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	depth.resize(nnode);par.resize(nnode);
	depth[0]=0;par[0]=-1;
	subtree_size.resize(nnode);
	dd(0);

	init_jt();

	int nant;std::cin>>nant;
	path_delta.resize(ad.size());
	for(int pathind=0;pathind<2*nant;++pathind){
		int u,v;std::cin>>u>>v;--u;--v;
		auto [u1,v1,w]=lca(u,v);
		if(u1==v1){
			path_delta[u1].sub.push_back(pathind);
			path_delta[u^v^w].add.push_back(pathind);
		}else{
			path_delta[u1].sub.push_back(pathind);
			path_delta[v1].sub.push_back(pathind);
			path_delta[u].add.push_back(pathind);
			path_delta[v].add.push_back(pathind);
		}
	}

	assert(path_delta[0].sub.empty());
	twosat.ad.resize(2*nant);
	de(0);
	twosat.run();

	if(twosat.val.empty()){
		std::cout<<"NO\n";
	}else{
		std::cout<<"YES\n";
		for(int i=0;i<nant;++i)
			std::cout<<(twosat.val[i*2]?'1':'2')<<'\n';
	}
}