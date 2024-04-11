#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5;

int n, k;
int par[N];
vi adj[N];
int a[N];

int b[N];

void dfs(int u){
	Fora(v, adj[u]){
		b[v] = b[u] / isz(adj[u]);
		dfs(v);
	}
}

ll dp[N][2];

void dfs_dp(int u){
	ll sum = 0;
	vector <ll> vdp;
	Fora(v, adj[u]){
		dfs_dp(v);
		sum += dp[v][0];
		vdp.emplace_back(dp[v][1] - dp[v][0]);
	}
	if (vdp.empty()){
		dp[u][0] = (ll)b[u] * a[u];
		dp[u][1] = (ll)(b[u] + 1) * a[u];
		return;
	}
	sort(bend(vdp), greater <>());
	{
		int x = b[u] - b[adj[u][0]] * isz(adj[u]);
		dp[u][0] = (ll)b[u] * a[u] + sum;
		For(i, 0, x){
			dp[u][0] += vdp[i];
		}
	}
	{
		int x = b[u] + 1 - b[adj[u][0]] * isz(adj[u]);
		dp[u][1] = (ll)(b[u] + 1) * a[u] + sum;
		For(i, 0, x){
			dp[u][1] += vdp[i];
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("KEK.inp", "r", stdin);
	// freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
	cin >> n >> k;
	ForE(u, 1, n){
		adj[u].clear();
	}
	ForE(u, 2, n){
		cin >> par[u];
		adj[par[u]].emplace_back(u);
	}
	ForE(u, 1, n){
		cin >> a[u];
	}

	b[1] = k;
	dfs(1);
	dfs_dp(1);
	cout << dp[1][0] << endl;
}
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/