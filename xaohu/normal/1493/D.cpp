#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, q;
map<int, int> m[200000];
multiset<int> s[200001];
ll res = 1;

int exp(int p) {
	if (s[p].size() < n)
		return 0;
	return *s[p].begin();
}

void add(int a, int p) {
	int old = exp(p);
	if (m[a][p] > 0)
		s[p].erase(s[p].find(m[a][p]));
	s[p].insert(++m[a][p]);
	if (exp(p) > old)
		res = res * p % 1000000007;
}

void upd(int a, int x) {
	for (int i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			add(a, i);
			x /= i;
		}
	}
	if (x > 1)
		add(a, x);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		upd(i, x);
	}
	while (q--) {
		int i, x;
		cin >> i >> x;
		upd(--i, x);
		cout << res << endl;
	}
	return 0;
}