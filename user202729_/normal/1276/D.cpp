// Related: https://codeforces.com/contest/1254/problem/E
//
// Wrong idea:
// * Given edge -> remove token -> split into x subtrees.
// * DP on subtree.
// ==> exponential.
//
// Random ideas:
// * only the order of edges with common endpoint matters.
// * result(n) <= Fib(n)
// * equality happens when for all ways to remove points, the graph remains connected
// <=> two halves  of the tree when rooted at last removed edge has parent removed after child.
//
// * tree with radius 1: answer = number of nodes.
//
// * consider some special cases:
//   - tree with parent removed after child
//   - tree with parent removed before child: top down DP.
//   - line tree.
//
// * more ideas: consider the set of edges/vertices to be selected.
//
// Correct idea: the order of edges with no common point is *not important*.
// => *direct* the edges. Necessary & sufficient conditions are *vertex-local*.
// => Obvious DP.
//
// [I solved the problem by myself without viewing any failed test cases]

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

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

struct edge{
	int node,time /* edges with larger time are removed later */;
	bool operator<(edge e)const{ return time<e.time; }
};
std::vector<std::vector<edge>> ad;

struct solve_t{
	modular none,down,nonedown;
	/* number of ways to "direct" the edges with >= 1 endpoint in subtree of node (node)
	 * s.t. all -ft vertex-local conditions int all nodes in the subtree are saefd
	 * and the edge (par..node) has direction (the token removed when processing that edge) [up|down|none]
	 * ("nonedown" = the node below the edge is empty when the edge is processed;
	 * "none" = ^^ (not empty) ...
	 *
	 * # {up} == # {none} (according to the table below)
	 */
};
solve_t solve(int node,int par){
	std::sort(begin(ad[node]),end(ad[node]));
	// up            none/nonedown none/nonedown none/nonedown ... |nonedown| {to par => reversed} ...
	// down/nonedown up            none/nonedown none/nonedown ... |nonedown| ...
	// down/nonedown down/nonedown up            none/nonedown ... |nonedown| ...
	// ...
	// down/nonedown down/nonedown down/nonedown ... up            |nonedown| ...
	// down/nonedown down/nonedown down/nonedown ... down/nonedown |down    | ...
	// down/nonedown down/nonedown down/nonedown ... down/nonedown |up/none | up            none/nonedown ...
	// down/nonedown down/nonedown down/nonedown ... down/nonedown |up/none | down/nonedown up            ...
	// ...
	// down/nonedown down/nonedown down/nonedown ... down/nonedown |up/none | down/nonedown down/nonedown ... up
	// down/nonedown down/nonedown down/nonedown ... down/nonedown |up/none | down/nonedown down/nonedown ... down/nonedown


	struct item{
		solve_t child_solve;
		modular prod_down_plus_nd_before,prod_none_plus_nd_after;
	};
	std::vector<item> d(ad[node].size());
	std::transform(begin(ad[node]),end(ad[node]),begin(d),[&](auto e)->item{
		if (e.node==par) return {{0,0,1},0,0}; // so that down+nd & none+nd = 1
		else return {solve(e.node,node),0,0};
	});


	modular prod_down_plus_nd_before=1;
	for(auto& i:d){
		i.prod_down_plus_nd_before=prod_down_plus_nd_before;
		prod_down_plus_nd_before*=i.child_solve.down+i.child_solve.nonedown;
	}

	modular prod_none_plus_nd_after=1;
	std::for_each(d.rbegin(),d.rend(),[&](item& i){
		i.prod_none_plus_nd_after=prod_none_plus_nd_after;
		prod_none_plus_nd_after*=i.child_solve.none+i.child_solve.nonedown;
	});


	int i=0; while(ad[node][i].node!=par) ++i;
	if (i+1!=(int)d.size())
		assert(d[i].prod_down_plus_nd_before == d[i+1].prod_down_plus_nd_before);
	if (i!=0)
		assert(d[i].prod_none_plus_nd_after == d[i-1].prod_none_plus_nd_after);

	solve_t out{};
	out.down=d[i].prod_down_plus_nd_before*d[i].prod_none_plus_nd_after;
	for(int j=0;j<i;++j)
		out.nonedown+=d[j].prod_down_plus_nd_before*d[j].child_solve. /* up */ none *d[j].prod_none_plus_nd_after;
	for(int j=i+1;j<(int)d.size();++j)
		out. /* up & */ none +=d[j].prod_down_plus_nd_before*d[j].child_solve. /* up */ none *d[j].prod_none_plus_nd_after;

	// Use *j* not *i* here! how to prevent mistakes like this?
	// `for(int j:range(i+1,d.size()))` ? ...

	out. /* up & */ none +=prod_down_plus_nd_before;
	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	ad.resize(n);
	for(int time=0;time<n-1;++time){
		int a,b;
		std::cin>>a>>b; --a; --b; assert(a!=b);
		ad[a].push_back({b,time}); ad[b].push_back({a,time});
	}

	ad[0].push_back({-1,n});
	auto tmp=solve(0,-1);
	std::cout<<int(tmp.nonedown+tmp. /* up */ none)<<'\n';
}