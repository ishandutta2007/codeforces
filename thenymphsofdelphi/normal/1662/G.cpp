/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e6 + 5;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int n, sum[N], par[N], val[N];
int64_t cnt[N], res;

// sum[u] -> sum in subtree u
// cnt[u] -> all pairs in subtree u

vector<int> adj[N];

void pre_dfs(int u, int p) {
	sum[u] = 1;
	for (int &v : adj[u]) if (v != p) {
		pre_dfs(v, u);

		cnt[u] += cnt[v] + sum[v];
		sum[u] += sum[v];
	}
}

void Hollwo_Pelw() {
	cin >> n;

	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		adj[par[i]].push_back(i);
		adj[i].push_back(par[i]);
	}

	fill(sum + 1, sum + n + 1, 1);
	for (int i = n; i >= 2; i--) {
		sum[par[i]] += sum[i];
	}

	int u = n;
	while (sum[u] < (n + 1) / 2)
		u --;

	pre_dfs(u, 0);

	int64_t cur = n - 1;
	
	bitset<N> dp;
	dp[0] = 1;

	for (int v : adj[u]) {
		cur += cnt[v];
		val[sum[v]] ++;
	}

	for (int i = 1; i <= n; i++) if (val[i]) {
		int x = (val[i] - 1) / 2;
		if (x) val[i] -= x * 2, val[i * 2] += x;
	}

	for (int i = 1; i <= n; i++)
		while (val[i] --) dp |= dp << i;

	int64_t maxval = 0;

	for (int i = 1; i < n - 1; i++)
		if (dp[i]) maxval = max(maxval, (int64_t) (n - 1 - i) * i);

	cur += maxval;
	res = max(res, cur);

	cout << res + n << endl;
}