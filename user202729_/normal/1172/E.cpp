/*
Out = sum {color c} (n**2 - sum {connected component without color c} (size**2))
Idea: segment tree, divide by time, join (
??? Is this okay? Number of split is small, but number of join is huge.
	-> for each color only consider the affected nodes.
), persistent.
Problem: node with large degree.
Idea: square root decomposition.
...
hld. no need for square root decomposition? But why is the time limit so large...
not easy to implement at all.

====

I really should prepare some template for test generation.

This is the (???)'th time I implement iterative segment tree, and I **still** get it wrong...

====

Forgot to turn off debugging. (???)
The program won't be slow unless the tree is (approximately) a line anyway, so
it isn't trivial to generate test cases.
*/

#ifndef LOCAL
#define NDEBUG
#endif
#include<iostream>
#include<vector>
#include<cassert>
#include<unordered_set>
#include<numeric>
#include<algorithm>

int64_t sqr(int x){ return (int64_t)x*x; }

template<class T>
struct undo_entry{
	T* source;
	T val;
};

template<class T>
std::vector<undo_entry<T>> undostack;

#define SET(A, OP, B) ([&]{\
	auto& _a=(A);\
	using T=std::decay_t<decltype(_a)>;\
	static_assert(std::is_same_v<T, int> or std::is_same_v<T, int64_t>, "");\
	auto _old_a=_a;\
	_a OP (B);\
	if(_a!=_old_a) /* optimization */ \
		undostack<T>.push_back({&_a, std::move(_old_a)});\
}())


template<class T>
void undostack_reset(){
	while(not undostack<T>.empty()){
		*undostack<T>.back().source = std::move(undostack<T>.back().val);
		undostack<T>.pop_back();
	}
}

struct Tree{
	std::vector<std::vector<int>> ad;
	Tree(int n):ad(n){
	}

	std::vector<int> subtreesize;
	//std::vector<int> depth;
	int dfs(int x){
		int subtreesize_x=1;
		//int const nextdt=depth[x]+1;
		for(int y:ad[x]){
			//depth[y]=nextdt;
			ad[y].erase(std::find(begin(ad[y]),end(ad[y]),x));
			subtreesize_x+=dfs(y);
		}
		return subtreesize[x]=subtreesize_x;
	}

	struct HLDPath{
		struct node{
			int lazy,min; // lazy does not affect min of this node
		};
		std::vector<node> d; // segment tree data
		std::vector<int> verts;

		auto offset()const{ return (int)d.size()/2; };

		auto verify()const{
			for(int x=1;x<offset();++x)
				assert(d[x].min==d[x].lazy+std::min(d[x*2].min,d[x*2+1].min));
			for(int x=offset();x<(int)d.size();++x)
				assert(d[x].min==d[x].lazy);
		}

		// add value int segment (NOTE: l & r are node indices)
		void add(int l,int r,int delta){
			verify();

			assert(offset()<=l and l<r and r<=(int)d.size());
			assert(d.size()==verts.size()*2);
			//l+=offset();
			//r+=offset();
			std::array<int,2> const endpts={l,r-1};
			auto const process=[&](int node){
				SET(d[node].min,+=,delta);
				SET(d[node].lazy,+=,delta);
			};
			while(l<r){
				if(l&1) process(l++);
				if(r&1) process(--r);
				l>>=1;r>>=1;
			}
			for(int x:endpts){
				for(x>>=1;x;x>>=1)
					SET(d[x].min,=,d[x].lazy+std::min(d[x*2].min,d[x*2+1].min));
			}

			verify();
		}

		// val(node x) = number of reachable node from node x downward (0 if x is blocked)
		int get(int node)const{
			assert(offset()<=node and node<=(int)d.size());
			assert(d.size()==verts.size()*2);
			// = sum of all ancestors of corresponding node on segment tree
			//x+=offset();
			int out=0;
			for(;node;node>>=1) out+=d[node].lazy;
			assert(out>=0);
			return out;
		}

		void push(int y){
			SET(d[y*2].lazy  ,+=,d[y].lazy);
			SET(d[y*2].min   ,+=,d[y].lazy);
			SET(d[y*2+1].lazy,+=,d[y].lazy);
			SET(d[y*2+1].min ,+=,d[y].lazy);
			SET(d[y].lazy    ,= ,0);
		}

		// returns max node1 < node such that get(node1)==0 or -1
		int prevzero(int node){
			assert(offset()<=node and node<=(int)d.size());
			if(node==offset()) return -1;
			assert(d[1].min>=0);
			for(int x:{offset(),node-1}){
				for(int sh=31^__builtin_clz(x);sh;--sh) push(x>>sh);
			}
			
			int l=offset(),r=node;
			int out=-1;
			while(l<r){
				if(l&1){
					if(d[l].min==0) out=l;
					++l;
				}
				if(r&1){
					--r;
					if(d[r].min==0){ out=r; break; }
				}
				l>>=1;r>>=1;
			}
			if(out<0) return out;
			for(int x=out;x>>=1;) assert(d[x].lazy==0);
			assert(d[out].min==0);
			
			while(out<offset()){
				push(out);

				assert(d[out].min==0);
				assert(d[out].lazy==0);
				assert(d[out].min==d[out].lazy+std::min(d[out*2].min,d[out*2+1].min));

				out*=2;
				if(d[out+1].min==0) ++out;
				else assert(d[out].min==0);
			}

			for(int x=out;x>>=1;) assert(d[x].lazy==0);
			assert(d[out].min==0);
			return out;
		}

		int par,depth /* chain depth, not node depth */;
	};
	std::vector<HLDPath> paths;

	struct Index{
		int path,node;
	};
	std::vector<Index> vertex_index;

	void dfs2(int x,Index i){
		vertex_index[x]=i;
		paths[i.path].verts.push_back(x);
		if(ad[x].empty())
			return;
		int y=*std::max_element(begin(ad[x]),end(ad[x]),[&](int x,int y){
				return subtreesize[x]<subtreesize[y];
				});
		dfs2(y,{i.path,i.node+1});
		for(int z:ad[x])
			if(z!=y){
				int pathid=(int) paths.size();
				paths.push_back({{},{},x,paths[i.path].depth+1});
				dfs2(z,{pathid,0});
			}
	}

	void hld(){
		subtreesize.resize(ad.size());
		{
			//depth[0]=1;
			unsigned n_=dfs(0);
			assert(n_==ad.size());
		}

		paths.push_back({{},{},-1,0});
		vertex_index.resize(ad.size());
		dfs2(0,{0,0});

		// fix intermediate (inconsistent) state: p.d.size() = 0
		// vertex_index.node = index
		for(unsigned i=0;i<ad.size();++i)
			vertex_index[i].node+=(int) paths[vertex_index[i].path].verts.size();
		for(auto& p:paths)
			p.d.resize(p.verts.size()*2);
	}

	// sum( val(y)^2 if y does not have unblocked parent )
	int64_t total_value=0;

	// [y] = sum( val(y)^2 for y in children(x) if y is int different chain )
	std::vector<int64_t> sqr_light_size;

	// same as above, but without ^2
	std::vector<int> light_size;

	void set(int const node,bool newblock){
		int delta;

		auto const upd_totalvalue_child_node=[&](int node,int mult){
			auto& path=paths[vertex_index[node].path];
			total_value+=mult*sqr_light_size[node];
			if(vertex_index[node].node!=(int)path.d.size()-1)
				total_value+=mult*sqr(path.get(vertex_index[node].node+1));
		};

		{
			auto& path=paths[vertex_index[node].path];
			int val=path.get(vertex_index[node].node);
			if(newblock){
				assert(val>0);
				delta=-val;
			}else{
				assert(val==0);
				delta=1; // this node
				delta+=light_size[node]; // light childz
				if(not ad[node].empty())
					delta+=path.get(vertex_index[node].node+1); // heavy child

				upd_totalvalue_child_node(node,-1);
			}
		}

		// node a = nearest ancestor of node (including node) such that par(a) is blocked/-1
		int a=node;
		while(true){ // traverse the HLD path twice, once to find a and once to update (NOTE inefficient)
			auto& path=paths[vertex_index[a].path];
			int l=path.prevzero(vertex_index[a].node);
			if(l<0){
				a=path.verts[0];
				if(path.par<0) break; // root reached 

				auto& nxtpath=paths[vertex_index[path.par].path];
				if(nxtpath.get(vertex_index[path.par].node)==0) break;

				a=path.par;
				continue;
			}else{
				a=path.verts[l-path.offset()+1];
				break;
			}
		}

		int size_a=paths[vertex_index[a].path].get(vertex_index[a].node);
		total_value-=sqr(size_a);
		total_value+=sqr(size_a+delta);

		{ // upd value of nodes on path (from node to a, inclusively)
			// and light_size & sqr_light_size of nodes from par(node) to par(a), inclusively, if not -1
			int y=node;
			while(true){
				// now nodes int [node..y[ have value updated & light_size of par updated
				auto& path=paths[vertex_index[y].path];
				int const l=vertex_index[a].path==vertex_index[y].path ? vertex_index[a].node : path.offset();
				int const r=vertex_index[y].node+1;

				int size;
				if(l==path.offset() and path.par>=0){
					size=path.get(path.offset());
					SET(sqr_light_size[path.par], -=, sqr(size));
					SET(light_size[path.par],     -=, size);
				}

				path.add(l,r,delta);

				if(l==path.offset() and path.par>=0){
					size+=delta;
					assert(size==path.get(path.offset()));
					SET(sqr_light_size[path.par], +=, sqr(size));
					SET(light_size[path.par],     +=, size);
				}

				if(vertex_index[a].path==vertex_index[y].path)
					break;
				else
					y=path.par;
			}
		}

		assert(size_a+delta==paths[vertex_index[a].path].get(vertex_index[a].node));
		if(newblock) upd_totalvalue_child_node(node,+1);
	}

};

int main(){
	int nnode,ntime;std::cin>>nnode>>ntime;
	Tree t(nnode);

	struct event{
		int time,node;
		bool addblock;
	};
	std::vector<std::vector<event>> evs(nnode); // by color

	std::vector<int> col(nnode);
	for(int node=0;node<nnode;++node){
		int& colnode=col[node];std::cin>>colnode;
		--colnode;
		evs[colnode].push_back({0,node,true});
	}

	for(int z=nnode,u,v;--z;){
		std::cin>>u>>v;
		t.ad[--u].push_back(--v);
		t.ad[v].push_back(u);
	}

	t.hld();

	for(int t=1;t<=ntime;++t){
		int node,newcol;std::cin>>node>>newcol;
		--node;--newcol;
		if(col[node]!=newcol){
			evs[col[node]].push_back({t,node,false});
			evs[col[node]=newcol].push_back({t,node,true});
		}
	}

	std::vector<int64_t> val(ntime+1);

	{ // initialize t values
		t.light_size.assign(nnode,0);
		t.sqr_light_size.assign(nnode,0);
		for(int node=0;node<nnode;++node){
			for(int x:t.ad[node])
				if(t.vertex_index[node].path!=t.vertex_index[x].path){
					t.light_size[node]    +=t.subtreesize[x];
					t.sqr_light_size[node]+=sqr(t.subtreesize[x]);
				}
		}
		for(auto& path:t.paths){
			//path.d.assign(path.d.size(),{});
			for(unsigned i=0;i<path.verts.size();++i) // NOTE O(n log n); could be O(n)
				path.add(i+path.offset(),i+1+path.offset(),
						t.subtreesize[path.verts[i]]);
		}
	}

	undostack<int>.clear();
	undostack<int64_t>.clear();

	for(auto const& evcol:evs){
		// reset t
		t.total_value=sqr(nnode);

		undostack_reset<int>();
		undostack_reset<int64_t>();

		int lastt=0;
		for(auto [time,node,addblock]:evcol){
			assert(time>=lastt);

			auto cur_val=sqr(nnode)-t.total_value;
			val[lastt]+=cur_val;
			val[time]-=cur_val;
			lastt=time;

			t.set(node,addblock);
		}
		val[lastt]+=sqr(nnode)-t.total_value;

	}

	std::partial_sum(begin(val),end(val),begin(val));
	for(auto x:val) std::cout<<x<<'\n';
}