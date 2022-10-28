#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + M : a;
}

vector<int> zfunc(const string& s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		z[i] = i >= r ? 0 : min(z[i - l], r - i);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			++z[i];
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

int cmp(string& a, string& b, vector<int>& zarr, int off) {
	int m = b.size();
	int lcp = zarr[m + 1 + off];
	if (lcp == m) {
		return 2;
	}
	return a[off + lcp] < b[lcp];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string a, l, r;
	cin >> a >> l >> r;
	int n = a.size();

	vector<int> zl = zfunc(l + '#' + a);
	vector<int> zr = zfunc(r + '#' + a);

	vector<int> dp(n + 1), ss(n + 2);
	dp[n] = ss[n] = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == '0') {
			dp[i] = l[0] == '0' ? dp[i + 1] : 0;
			ss[i] = add(ss[i + 1], dp[i]);
			continue;
		}

		int left = i + (int)l.size() + (cmp(a, l, zl, i) == 1);
		int right = i + (int)r.size() - 1 + !!cmp(a, r, zr, i);

		if (left <= n) {
			dp[i] = sub(ss[left], ss[min(n, right) + 1]);
		}
		ss[i] = add(ss[i + 1], dp[i]);
	}
	cout << dp[0] << '\n';
}