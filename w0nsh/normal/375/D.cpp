#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
std::less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
//X.find_by_order(k); - zwraca iterator na k-ty element (numeracja od zerowego)
//X.order_of_key(k); - zwraca liczb elementw ostro mniejszych ni k

std::vector<VI> g;
std::vector<std::vector<PII>> que;
VI ans;
VI A;

struct S{
	ordered_set<PII> set;
	std::map<int, int> map;

	void add(int v, int cnt){
		auto it = map.find(v);
		if(it == map.end()){
			map[v] = cnt;
			set.insert(MP(cnt, v));
		}else{
			set.erase(MP(it->Y, it->X));
			it->Y += cnt;
			set.insert(MP(it->Y, it->X));
		}
	}
};

S* merge(S* a, S* b){
	if(!a) return b;
	if(!b) return a;
	if(a->set.size() < b->set.size()) std::swap(a, b);
	TRAV(pr, b->map){
		a->add(pr.X, pr.Y);
	}
	delete b;
	return a;
}

S* dfs(int v, int par=-1){
	S* cur = nullptr;
	TRAV(ch, g[v]) if(ch != par){
		cur = merge(cur, dfs(ch, v));
	}
	if(!cur) cur = new S();
	cur->add(A[v], 1);

	TRAV(q, que[v]){
		ans[q.X] = cur->set.size() - cur->set.order_of_key(MP(q.Y, -100));
	}

	return cur;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	que.resize(n);
	ans.resize(m);
	FOR(i, m){
		int v, k;
		std::cin >> v >> k;
		v--;
		que[v].push_back(MP(i, k));
	}

	delete dfs(0);

	FOR(i, m) std::cout << ans[i] << "\n";

	return 0;
}