#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("J.inp", "r"))
		assert(freopen("J.inp", "r", stdin)), assert(freopen("J.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

const int N = 205;

#define int long long

int n, a[N][N], dp[N][N], opt[N][N], res[N];

inline int sum(int l, int r) {
	return (a[n][r] - a[n][l - 1]) - (a[r][r] - a[l - 1][r] - a[r][l - 1] + a[l - 1][l - 1]);
}

inline bool chkmin(int &a, int b) {
	return a > b ? a = b, 1 : 0;
}

inline void solve(int l, int r, int p = 0) {
	if (l > r) return ;
	int m = opt[l][r];

	res[m] = p;
	solve(l, m - 1, m), solve(m + 1, r, m);
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		cin >> a[i][j];
		a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	}

	memset(dp, 0x3f, sizeof dp);

	for (int i = 0; i <= n; i++)
		dp[i + 1][i] = 0;

	for (int len = 1; len <= n; len++) {
		for (int l = 1, r = len; r <= n; l ++, r ++) {
			for (int m = l; m <= r; m++)
				if (chkmin(dp[l][r], dp[l][m - 1] + dp[m + 1][r] + sum(l, r)))
					opt[l][r] = m;
		}
	}

	solve(1, n);

	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}