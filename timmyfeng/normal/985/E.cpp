#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 5;

int ft[MX], n;

void upd(int a, int val) {
	for (++a; a <= n + 1; a += a & -a) {
		ft[a] += val;
	}
}

int qry(int a) {
	int res = 0;
	for (++a; a; a -= a & -a) {
		res += ft[a];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, d;
	cin >> n >> k >> d;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());

	upd(0, 1);
	upd(1, -1);
	for (int i = 0; i < n; ++i) {
		if (!qry(i))
			continue;
		int last = upper_bound(a.begin(), a.end(), a[i] + d) - a.begin();
		if (i + k <= last) {
			upd(i + k, 1);
			upd(last + 1, -1);	
		}
	}

	cout << (qry(n) ? "YES" : "NO") << '\n';
}