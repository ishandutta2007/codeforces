#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int LOG = 22;
const int M = (119 << 23) + 1;

vector<int> w[LOG];
int rev[1 << LOG];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return ll(a) * b % M;
}

int modpow(int a, int b) {
	if (!b) 
		return 1;
	if (b % 2) 
		return mul(a, modpow(a, b - 1));
	int tmp = modpow(a, b / 2);
	return mul(tmp, tmp);
}

int inv(int a) {
	return modpow(a, M - 2);
}

void init(int log) {
	for (int i = 0; i < log; ++i) {
		w[i].resize(1 << i);
		w[i][0] = 1;
		int delta = modpow(3, (M - 1) >> (i + 1));
		for (int j = 1; j < (1 << i); ++j) {
			w[i][j] = mul(w[i][j - 1], delta);
		}
	}

	for (int i = 0; i < (1 << log); ++i) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (log - 1));
	}
}

void fft(vector<int>& p) {
	int n = p.size();
	int log = __builtin_ctz(n);
	for (int i = 0; i < n; ++i) {
		if (i < rev[i]) {
			swap(p[i], p[rev[i]]);
		}
	}

	for (int i = 0; i < log; ++i) {
		int len = 1 << i;
		for (int j = 0; j < n; j += len * 2) {
			for (int k = 0; k < len; ++k) {
				int l = p[j + k];
				int r = mul(p[j + k + len], w[i][k]);
				p[j + k] = add(l, r);
				p[j + k + len] = sub(l, r);
			}
		}
	}
}

void polypol(vector<int>& p, int e) {
	int log = 32 - __builtin_clz(p.size() - 1u);
	p.resize(1 << log);
	init(log);
	fft(p);

	for (auto& i : p) {
		i = modpow(i, e);
	}

	fft(p);
	int in = inv(1 << log);
	for (auto& i : p) {
		i = mul(i, in);
	}
	reverse(p.begin() + 1, p.end());
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int mx = 9 * n / 2;
	vector<int> p(mx + 1);
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		p[a] = 1;
	}

	polypol(p, n / 2);
	int ans = 0;
	for (int i = 0; i <= mx; ++i) {
		ans = add(ans, mul(p[i], p[i]));	
	}
	cout << ans << '\n';
}