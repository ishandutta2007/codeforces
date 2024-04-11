#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1000;
const int LOGN = 10;
const ll INF = 1e18;

ll dp[MX][MX], suf_sum[MX][MX];
int sparse[LOGN][MX], key[MX];
array<int, 3> suf_arr[MX];
int n, logn;
string s;

ll add(ll a, ll b) {
	a += b;
	return a > INF ? INF + 1 : a;
}

int lcp(int a, int b) {
	if (a == b)
		return n - a;

	a = key[a];
	b = key[b];
	if (a > b) {
		swap(a, b);
	}

	int l = 31 - __builtin_clz(b - a);
	return min(sparse[l][a], sparse[l][b - (1 << l)]);
}

bool cmp(array<int, 2> a, array<int, 2> b) {
	int len = lcp(a[0], b[0]);
	if (len >= a[1] || len >= b[1]) {
		return a[1] > b[1];
	}
	return s[a[0] + len] > s[b[0] + len];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll k;
	int m;
	cin >> n >> m >> k >> s;

	for (int i = 0; i < n; ++i) {
		key[i] = s[i] - 'a';
	}

	for (int len = 1; ; len *= 2) {
		for (int i = 0; i < n; ++i) {
			suf_arr[i][0] = key[i];
			suf_arr[i][1] = i + len < n ? key[i + len] : -1;
			suf_arr[i][2] = i;
		}
		sort(suf_arr, suf_arr + n);

		int cur = 0;
		for (int i = 0; i < n; ++i) {
			cur += (i && (suf_arr[i][0] != suf_arr[i - 1][0] || suf_arr[i][1] != suf_arr[i - 1][1]));
			key[suf_arr[i][2]] = cur;
		}
		if (cur == n - 1)
			break;
	}

	for (int i = 0, k = 0; i < n; ++i) {
		if (key[i] == n - 1) {
			k = 0;
			continue;
		}

		int j = suf_arr[key[i] + 1][2];
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
			++k;
		}
		sparse[0][key[i]] = k;

		if (k) {
			--k;
		}
	}

	for (logn = 1; (1 << logn) < 2 * n; ++logn) {
		int len = 1 << (logn - 1);
		for (int i = 0; i + len < n; ++i) {
			sparse[logn][i] = min(sparse[logn - 1][i], sparse[logn - 1][i + len]);
		}
	}

	vector<array<int, 2>> substrings;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; i + j - 1 < n; ++j) {
			substrings.push_back({i, j});
		}
	}
	sort(substrings.begin(), substrings.end(), cmp);


	int lb = 0, rb = substrings.size() - 1u;
	while (lb < rb) {
		int mb = (lb + rb + 1) / 2;
		auto cur = substrings[mb];

		memset(suf_sum, 0, sizeof suf_sum);
		memset(dp, 0, sizeof dp);
		suf_sum[n][0] = 1;
		dp[n][0] = 1;

		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j <= m; ++j) {
				suf_sum[i][j] = suf_sum[i + 1][j];
			}

			if (!cmp({i, n - i}, cur))
				continue;

			int len = min(cur[1], lcp(cur[0], i)) + 1;
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = suf_sum[i + len][j - 1];
				suf_sum[i][j] = add(suf_sum[i][j], dp[i][j]);
			}
		}

		if (dp[0][m] < k) {
			lb = mb;
		} else {
			rb = mb - 1;
		}
	}

	for (int i = 0; i < substrings[lb][1]; ++i) {
		cout << s[substrings[lb][0] + i];
	}
	cout << '\n';
}