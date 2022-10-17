#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
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

int n;
VI A;
VI pre;
VI post;
VI good;
std::vector<VI> g;
std::vector<ordered_set<int>> cols;

int ans;
int tick;
void dfs(int v, int par=-1){
	pre[v] = tick++;
	TRAV(ch, g[v]) if(ch != par){
		dfs(ch, v);
	}
	post[v] = tick++;
	cols[A[v]].insert(pre[v]);
	cols[A[v]].insert(post[v]);
}

void set_except(int a, int b){
	good[0]++;
	good[a]--;
	good[b+1]++;
}

void set(int a, int b){
	good[a]++;
	good[b+1]--;
}

int are(int c, int a, int b){
	return cols[c].order_of_key(b+1) - cols[c].order_of_key(a);
}

int are_except(int c, int a, int b){
	return SZ(cols[c]) - are(c, a, b);
}

void dfs2(int v, int par=-1){
	int c = A[v];
	TRAV(ch, g[v]) if(ch != par){
		if(are(c, pre[ch], post[ch])){
			set_except(pre[ch], post[ch]);
		}
	}
	if(are_except(c, pre[v], post[v])){
		set(pre[v], post[v]);
	}

	TRAV(ch, g[v]) if(ch != par){
		dfs2(ch, v);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	auto vals = A;
	std::sort(vals.begin(), vals.end());
	auto kto = [&](int siema){
		return (int)(std::lower_bound(vals.begin(), vals.end(), siema) - vals.begin());
	};
	FOR(i, n) A[i] = kto(A[i]);

	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	post.resize(n);
	pre.resize(n);
	cols.resize(n);
	dfs(0);

	good.resize(2*n+1);
	assert(tick == 2*n);

	dfs2(0);
	int have = 0;
	FOR(i, 2*n){
		have += good[i];
		if(have == 0) ans++;
	}
	assert(ans%2 == 0);
	std::cout << ans/2;

	return 0;
}