#include <bits/stdc++.h> 
using namespace std;

const int MX = 5e5;
const int M = 1e9 + 7;

int ft1[MX + 1], ft2[MX + 1], n;

int add(int a, int b) {
	return a + b >= M ? a + b - M : a + b;
}

int sub(int a, int b) {
	return a - b < 0 ? a - b + M : a - b;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

void upd(int a, int val, int* ft) {
	for ( ; a <= n; a += a & -a) {
		ft[a] = add(ft[a], val);
	}
}

int qry(int a, int* ft) {
	int res = 0;
	for ( ; a; a -= a & -a) {
		res = add(res, ft[a]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<int> b = a;
	map<int, int> key;
	sort(b.begin(), b.end());
	for (int i = 0; i < n; ++i) {
		key[b[i]] = i + 1;
	}

	int ans = 0, cur = 0;
	for (int i = n - 1; i >= 0; --i) {
		int k = key[a[i]];
		upd(k, n - i, ft1);
		upd(k, mul(a[i], (n - i)), ft2);
		cur = add(cur, mul(a[i], qry(k, ft1)));
		cur = add(cur, sub(qry(n, ft2), qry(k, ft2)));
		ans = add(ans, cur);
	}
	cout << ans << '\n';
}