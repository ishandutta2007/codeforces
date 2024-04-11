#include <bits/stdc++.h> 
using namespace std;

const int M = (119 << 23) + 1;
const int LOG = 18;

int w[LOG][1 << LOG], rev[1 << LOG];

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

void init() {
	int base = 3;
	for (int i = 0; i < LOG; ++i) {
		w[i][0] = 1;
		w[i][1] = modpow(base, (M - 1) >> (i + 1));
		for (int j = 2; j < (1 << i); ++j) {
			w[i][j] = mul(w[i][j - 1], w[i][1]);
		}
	}

	for (int i = 0; i < (1 << LOG); ++i) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (LOG - 1));
	}
}

void fft(vector<int>& a, bool inverse) {
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
				int r = mul(w[i][k], a[j + k + len]);
				a[j + k] = add(l, r);
				a[j + k + len] = sub(l, r);
			}
		}
	}

	if (inverse) {
		int tmp = inv(n);
		for (auto& i : a) {
			i = mul(i, tmp);
		}
		reverse(a.begin() + 1, a.end());
	}
}

vector<int> mul(vector<int>& a, vector<int>& b) {
	int n = 1;
	while (n < int(a.size() + b.size())) {
		n *= 2;
	}
	a.resize(n);
	b.resize(n);
	fft(a, false);
	fft(b, false);

	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = mul(a[i], b[i]);
	}

	fft(c, true);
	while (!c.back()) {
		c.pop_back();
	}
	return move(c);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int n;
	cin >> n;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++mp[a];
	}
	
	vector<vector<int>> poly;
	for (auto [a, b] : mp) {
		poly.emplace_back(b + 1, 1);
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < (int)poly.size(); ++i) {
		pq.emplace(poly[i].size(), i);
	}
	while (pq.size() > 1u) {
		int a = pq.top().second;
		pq.pop();
		int b = pq.top().second;
		pq.pop();
		poly[a] = mul(poly[a], poly[b]);
		pq.emplace(poly[a].size(), a);
	}

	int fin = pq.top().second;
	cout << poly[fin][n / 2] << '\n';
}