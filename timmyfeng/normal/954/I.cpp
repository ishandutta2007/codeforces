#include <bits/stdc++.h> 
using namespace std;

const int AL = 6;
const int LOGN = 19;
const int M = (119 << 23) + 1;

vector<int> cnt_edge[AL][AL], adj[AL], w[LOGN];
bool vstd[AL];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + M : a;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int mod_pow(int b, int e) {
	int res = 1;
	for ( ; e; e /= 2) {
		if (e % 2) {
			res = mul(res, b);
		}
		b = mul(b, b);
	}
	return res;
}

void fft(vector<int>& a) {
	int n = a.size();
	int logn = __builtin_ctz(n);

	for (int i = 0; i < n; ++i) {
		int rev = 0;
		for (int j = 0; j < logn; ++j) {
			if (i & (1 << j)) {
				rev ^= 1 << (logn - 1 - j);
			}
		}
		
		if (rev > i) {
			swap(a[i], a[rev]);
		}
	}

	for (int i = 0; i < logn; ++i) {
		int len = 1 << i;
		for (int j = 0; j < n; j += len * 2) {
			for (int k = 0; k < len; ++k) {
				int l = a[j + k];
				int r = mul(a[j + k + len], w[i][k]);
				a[j + k] = add(l, r);
				a[j + k + len] = sub(l, r);
			}
		}
	}
}

vector<int> mul(vector<int>& a, vector<int>& b) {
	int n = 1;
	for ( ; n < (int)(a.size() + b.size()); n *= 2);
	a.resize(n);
	b.resize(n);
	fft(a);
	fft(b);
	
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		res[i] = mul(a[i], b[i]);
	}

	fft(res);
	reverse(res.begin() + 1, res.end());	
	int den = mod_pow(n, M - 2);
	for (auto& i : res) {
		i = mul(i, den);
	}
	return res;
}

void dfs(int u) {
	vstd[u] = true;
	for (auto v : adj[u]) {
		if (!vstd[v]) {
			dfs(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();

	for (int i = 0; i < LOGN; ++i) {
		w[i].resize(1 << i);
		w[i][0] = 1;
		int delta = mod_pow(3, (M - 1) >> (i + 1));
		for (int j = 1; j < (1 << i); ++j) {
			w[i][j] = mul(w[i][j - 1], delta);
		}
	}

	reverse(t.begin(), t.end());
	for (int i = 0; i < AL; ++i) {
		for (int j = 0; j < AL; ++j) {
			vector<int> a(n), b(m);
			for (int k = 0; k < n; ++k) {
				a[k] = (s[k] == 'a' + i);
			}
			for (int k = 0; k < m; ++k) {
				b[k] = (t[k] == 'a' + j);
			}

			cnt_edge[i][j] = mul(a, b);
			cnt_edge[i][j].resize(n);
		}
	}

	for (int i = m - 1; i < n; ++i) {
		fill(adj, adj + AL, vector<int>());
		fill(vstd, vstd + AL, false);
		for (int j = 0; j < AL; ++j) {
			for (int k = 0; k < AL; ++k) {
				if (cnt_edge[j][k][i]) {
					adj[j].push_back(k);
					adj[k].push_back(j);
				}
			}
		}

		int ans = AL;
		for (int i = 0; i < AL; ++i) {
			if (!vstd[i]) {
				dfs(i);
				--ans;
			}
		}
		cout << ans << ' ';
	}
	cout << '\n';
}