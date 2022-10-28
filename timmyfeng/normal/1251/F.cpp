#include <bits/stdc++.h> 
using namespace std;

const int MX = 3e5 + 1;
const int M = (119 << 23) + 1;
const int LOG = 19;

int b[5], freq[MX], ps1[MX], ps2[MX], fact[MX], invfact[MX], pow2[MX], rev[1 << LOG], w[LOG][1 << LOG];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int modpow(int b, int e) {
	if (!e)
		return 1;
	if (e % 2)
		return mul(b, modpow(b, e - 1));
	int tmp = modpow(b, e / 2);
	return mul(tmp, tmp);
}

int inv(int a) {
	return modpow(a, M - 2);
}

int comb(int n, int k) {
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

void init() {
	invfact[0] = invfact[1] = fact[0] = pow2[0] = 1;
	for (int i = 2; i < MX; ++i) {
		invfact[i] = M - mul(M / i, invfact[M % i]);
	}
	for (int i = 1; i < MX; ++i) {
		invfact[i] = mul(invfact[i - 1], invfact[i]);
		fact[i] = mul(fact[i - 1], i);
		pow2[i] = add(pow2[i - 1], pow2[i - 1]);
	}

	for (int i = 0; i < LOG; ++i) {
		w[i][0] = 1;
		w[i][1] = modpow(3, (M - 1) >> (i + 1));
		for (int j = 2; j < (1 << i); ++j) {
			w[i][j] = mul(w[i][j - 1], w[i][1]);
		}
	}

	for (int i = 0; i < (1 << LOG); ++i) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (LOG - 1));
	}
}

void fft(vector<int>& a) {
	int n = a.size();
	int log = __builtin_ctz(n);
	for (int i = 0; i < n; ++i) {
		int ni = rev[i] >> (LOG - log);
		if (i < ni) {
			swap(a[i], a[ni]);
		}
	}

	for (int i = 0; i < log; ++i) {
		int len = 1 << i;
		for (int j = 0; j < n; j += 2 * len) {
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
	while (n < int(a.size() + b.size())) {
		n *= 2;
	}
	a.resize(n);
	b.resize(n);
	fft(a);
	fft(b);

	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = mul(a[i], b[i]);
	}

	fft(c);
	int v = inv(n);
	for (auto& i : c) {
		i = mul(i, v);
	}
	reverse(c.begin() + 1, c.end());
	
	while (!c.back()) {
		c.pop_back();
	}
	return move(c);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (!freq[a]) {
			++ps1[a];
		} else if (freq[a] == 1) {
			--ps1[a];
			++ps2[a];
		}
		++freq[a];
	}
	for (int i = 1; i < MX; ++i) {
		ps1[i] += ps1[i - 1];
		ps2[i] += ps2[i - 1];
	}

	vector<vector<int>> ans;
	for (int i = 0; i < k; ++i) {
		cin >> b[i];
		int cur = b[i] - 1;
		vector<int> u(ps1[cur] + 1);
		for (int j = 0; j <= ps1[cur]; ++j) {
			u[j] = mul(comb(ps1[cur], j), pow2[j]);
		}
		vector<int> v(2 * ps2[cur] + 1);
		for (int j = 0; j <= 2 * ps2[cur]; ++j) {
			v[j] = comb(2 * ps2[cur], j);	
		}
		ans.push_back(move(mul(u, v)));
	}

	int q;
	cin >> q;
	while (q--) {
		int req;
		cin >> req;
		int res = 0;
		for (int i = 0; i < k; ++i) {
			int cnt = req / 2 - b[i] - 1;
			if (cnt >= 0 && cnt < int(ans[i].size())) {
				res = add(res, ans[i][cnt]);
			}
		}
		cout << res << '\n';
	}
}