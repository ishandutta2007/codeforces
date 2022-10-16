#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 5e5 + 5;

int n, ans = 0;
vector<int> vec;
vector<int> g[maxn];

inline void dfs(int u, int p, int d){
	if(g[u].size() == 1){
		vec.PB(d);
	}
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(v == p)
			continue;
		dfs(v, u, d + 1);
	}
	return;
}

int main(){
	scanf("%d", &n);
	FOR(i, 1, n){
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		g[u].PB(v);
		g[v].PB(u);
	}
	FOR(i, 0, g[0].size()){
		vec.clear();
		dfs(g[0][i], 0, 1);
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		FOR(j, 0, vec.size())
			ans = max(ans, j + vec[j]);
	}
	printf("%d\n", ans);
	return 0;
}