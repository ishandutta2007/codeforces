#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld PI = acos(-1);
const int AL = 26;
const int MX = 2e5;

int p[AL], col[AL], pi[2 * MX + 1];
vector<vector<int>> cyc;
bool ans[MX];

struct comp {
	ld x, y;
	comp operator*(comp a) {
		return {x * a.x - y * a.y, x * a.y + y * a.x};
	}
	comp operator+(comp a) {
		return {x + a.x, y + a.y};
	}
	comp operator-(comp a) {
		return {x - a.x, y - a.y};
	}
	comp operator/(ld a) {
		return {x / a, y / a};
	}
	comp conj() {
		return {x, -y};
	}
} datt[AL], dats[AL];

void fft(vector<comp>& a, bool inv) {
	int n = a.size();
	if (n == 1) return;
	comp wn = {cosl(2 * PI / n), sinl(2 * PI / n)}, w = {1, 0};
	if (inv) {
		wn = wn.conj();
	}
	vector<comp> even, odd;
	for (int i = 0; i < n; ++i) {
		if (i % 2) {
			odd.push_back(a[i]);
		} else {
			even.push_back(a[i]);
		}
	}

	fft(even, inv);
	fft(odd, inv);

	for (int i = 0; i < n / 2; ++i) {
		auto t = w * odd[i];
		a[i] = even[i] + t;
		a[i + n / 2] = even[i] - t;
		w = w * wn;
	}
}

vector<comp> mul(vector<comp>& a, vector<comp>& b) {
	int n = 1;
	for ( ; n < a.size() || n < b.size(); n *= 2);
	a.resize(n);
	b.resize(n);
	fft(a, false);
	fft(b, false);

	vector<comp> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = a[i] * b[i];
	}

	fft(c, true);
	for (auto& i : c) {
		i = i / n;
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < AL; ++i) {
		cin >> p[i];
		--p[i];
	}
	string s, t;
	cin >> s >> t;
	int n = t.size();
	int m = s.size();

	for (int i = 0, j = 0; i < AL; ++i) {
		if (col[i]) continue;
		++j;
		cyc.emplace_back();
		int cur = i;
		while (!col[cur]) {
			cyc.back().push_back(cur);
			col[cur] = j;
			cur = p[cur];
		}
	}

	string u = s + '#' + t;
	for (int i = 1, j = 0; i < n + m + 1; ++i) {
		while (j && col[u[j] - 'a'] != col[u[i] - 'a']) {
			j = pi[j - 1];
		}
		if (col[u[j] - 'a'] == col[u[i] - 'a']) {
			++j;
		}
		pi[i] = j;
		if (pi[i] == m) {
			ans[i - 2 * m] = true;
		}
	}

	for (auto& i : cyc) {
		int len = i.size();
		for (int j = 0; j < len; ++j) {
			ld a = 2 * PI * j / len;
			ld b = (PI - 2 * PI * j) / len;
			dats[i[j]] = {cosl(a), sinl(a)};
			datt[i[j]] = {cosl(b), sinl(b)};
		}
	}
	vector<comp> a, b;
	for (auto i : s) {
		a.push_back(dats[i - 'a']);
	}
	for (auto i : t) {
		b.push_back(datt[i - 'a']);
	}
	reverse(a.begin(), a.end());
	vector<comp> c = mul(a, b);

	ld goal = 0.0;
	for (auto i : s) {
		goal += (dats[i - 'a'] * datt[i - 'a']).x;
	}
	for (int i = 0; i < n - m + 1; ++i) {
		if (abs(goal - c[i + m - 1].x) > 0.01) {
			cout << false;
		} else {
			cout << ans[i];
		}
	}
	cout << '\n';
}