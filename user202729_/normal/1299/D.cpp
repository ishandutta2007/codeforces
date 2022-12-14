#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

using State=std::array<int8_t,5>;
using StateIndex=int;

struct state_hash{ std::size_t operator()(State x)const{
	std::size_t a=43;
	for(auto& xi:x) a=a<<6|xi;
	return a;
}};
std::unordered_map<State,StateIndex,state_hash> stateindex;
std::vector<State> states;
std::vector<std::array<StateIndex,32>> nextst;

std::vector<StateIndex> pendproc;

StateIndex sindex(State st){
	auto newindex=(StateIndex)states.size();
	assert(states.size()==nextst.size() and states.size()==stateindex.size());
	auto [iter,inserted]=stateindex.emplace(st,newindex);
	if(inserted){
		states.push_back(st);
		nextst.push_back({});
		pendproc.push_back(newindex);
		return newindex;
	}
	else return iter->second;
}

void proc(StateIndex i){
	auto const st=states[i];
	auto n=int(std::find(begin(st),end(st),-1)-begin(st));
	if(n==(int)st.size()) return;

	assert(nextst[i][0]==0);
	for(int8_t nxt=1;nxt<32;++nxt){
		auto st1=st;
		st1[n]=nxt;
		int proc=0;
		for(int bit=0;bit<5;++bit){
			int i=proc;
			while(true){
				if(i>n) break;
				if(st1[i]>>bit&1){
					std::swap(st1[proc],st1[i]);
					for(int j=0;j<=n;++j) if(j!=proc and st1[j]>>bit&1) st1[j]^=st1[proc];
					++proc;
					break;
				}
				++i;
			}
		}
		auto nxtindex=proc<=n ? (assert(st1[proc]==0), 0) : sindex(st1);
		nextst[i][nxt]=nxtindex;
	}
}

StateIndex statemerge(StateIndex a,StateIndex b){
	for(auto mask:states[b]){
		if(mask<0){ assert(mask==-1); break; }
		a=nextst[a][mask];
	}
	return a;
}


std::vector<std::vector<int>> ad;
struct edge2{
#if LOCAL
	int a,b;
#endif
	int a_xor_b;
	int val;
	edge2(int a,int b,int val):
#if LOCAL
		a(a),b(b),
#endif
		a_xor_b(a xor b),
		val(val){}
	int other(int x)const{
#if LOCAL
		assert(x==a or x==b);
#endif
		return a_xor_b xor x;
	}
};
std::vector<edge2> edges;

std::vector<char> vis;
std::vector<int> par,val; // xor of some path
std::vector<std::vector<int>> branches; // of the dfs tree. Indexed by the root of that branch.

void for_ad(int node,auto const& f /* (int other_node, int | int const& | int& val)->void */){
	for(int edgeindex:ad[node])
		f(edges[edgeindex].other(node),edges[edgeindex].val);
}

void dd(int x,int valx,int branch){
	assert(not vis[x]);
	vis[x]=true;
	val[x]=valx;
	if(branch>=0) branches[branch].push_back(x);
	for_ad(x,[&](auto y,auto edgeval){
		if(not vis[y]){
			par[y]=x;
			dd(y,valx xor edgeval,
					branch<0 ? (assert(x==0),y) : branch);
		}
	});
}

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

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	StateIndex constexpr EMPTY_STATE=1;
	{
		states.resize(2);
		stateindex[states[0]]=0; // the special state with index [0] is for the "contains 0" states

		states[EMPTY_STATE].fill(-1); // -1: empty
		// TIL C++ std::array has this member function
		stateindex[states[EMPTY_STATE]]=EMPTY_STATE;

		nextst.resize(2);
	}

	nextst[0].fill(0);
	pendproc.push_back(EMPTY_STATE);
	while(not pendproc.empty()){
		auto x=pendproc.back(); pendproc.pop_back();
		proc(x);
	}

	assert(states.size()==375);

	int nnode,nedge;std::cin>>nnode>>nedge;
	ad.resize(nnode);
	edges.reserve(nedge);
	for(int edgeindex=0;edgeindex<nedge;++edgeindex) {
		int a,b,w;std::cin>>a>>b>>w;
		--a;--b;
		ad[a].push_back(edgeindex);
		ad[b].push_back(edgeindex);
		edges.push_back({a,b,w});
	}
	assert((int)edges.size()==nedge);

	vis.resize(nnode);
	val.resize(nnode);
	par.assign(nnode,-1);
	branches.resize(nnode);
	dd(0,0,-1);

	for(int node=0;node<nnode;++node) if(vis[node]){
		for_ad(node,[&](auto,auto& edgeval){
			edgeval^=val[node];
		});
	}

	std::vector<modular> dp(states.size()),nxt /* temporary, to avoid reallocation */;
	dp[EMPTY_STATE]=1;
	for(int branch=0;branch<nnode;++branch) if(not branches[branch].empty()){
		int other=-1;
		int8_t other_edgeval;
		StateIndex branchstate_without_other=EMPTY_STATE;

		for(auto node:branches[branch])
			for_ad(node,[&](auto adnode,auto val){
				if(par[adnode]==node or par[node]==adnode) return;
				if(adnode==0){
					assert(other<0);
					other=node;
					other_edgeval=val;
				}else{
					assert(node!=adnode);
					if(node<adnode) // each undirected edge should only be added once
						branchstate_without_other=nextst[branchstate_without_other][val];
				}
			});

		if(other>=0){
			// 4 cases: remove or not remove (each edge)
			nxt=dp; // remove both
			StateIndex const branchstate_with_other=nextst[branchstate_without_other][other_edgeval];
			for(auto old_state=(int)states.size();old_state--;){
				// remove either edge will have the same result
				nxt[statemerge(old_state,branchstate_without_other)]+=dp[old_state]+dp[old_state];
				// doesn't remove any edge
				nxt[statemerge(old_state,branchstate_with_other)]+=dp[old_state];
			}
		}else{
			// 2 cases
			nxt=dp; // remove the edge
			for(auto old_state=(int)states.size();old_state--;){
				nxt[statemerge(old_state,branchstate_without_other)]+=dp[old_state];
			}
		}
		std::swap(dp,nxt);
	}

	std::cout<<int(std::accumulate(begin(dp)+1,end(dp),modular(0)))<<'\n';
}