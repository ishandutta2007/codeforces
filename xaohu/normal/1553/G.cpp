#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;

const int N = 1 << 20;

int n, q, p[N], r[N], a[N], lst[N];
map<pair<int, int>, int> m;

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

vector<int> fact(int x) {
	vector<int> res;
	for (int i = 2; i * i <= x; i++)
		while (x % i == 0) {
			res.push_back(i);
			x /= i;
		}
	if (x > 1)
		res.push_back(x);
	return res;
}


int main() {
	ios_base::sync_with_stdio(0);

	iota(p, p + N, 0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		auto v = fact(a[i]);
		assert(v.size());
		r[i] = v[0];
		for (int j = 0; j + 1 < v.size(); j++)
			p[find(v[j])] = find(v[j + 1]);
	}

	for (int i = 1; i <= n; i++) {
		auto v = fact(a[i] + 1);
		v.push_back(r[i]);
		vector<int> f;
		for (auto x : v) {
			int a = find(x);
			if (lst[a] != i)
				f.push_back(a);
			lst[a] = i;
		}
		for (auto a : f)
			for (auto b : f)
				m[make_pair(a, b)] = 1;
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		a = find(r[a]);
		b = find(r[b]);
		if (a == b)
			cout << 0 << endl;
		else if (m.count(make_pair(a, b)))
			cout << 1 << endl;
		else 
			cout << 2 << endl;
	}

	return 0;
}