#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

const int N = 2e5 + 10;

int n, p[N], vis[N];
vector<int> heads;
vector<pair<int, int>> res;

void gao(int a, int b) {
	res.emplace_back(a, b);
	swap(p[a], p[b]);
}

void solve2(int u, int v) {
	gao(u, v);
	rep(r, 0, 2) {
		while (p[u] != v) 
			gao(u, p[u]);
		swap(u, v);
	}
	gao(u, v);
}

int main() {
	cin >> n;
	rep(i, 1, n + 1) 
		cin >> p[i];
	rep(i, 1, n + 1) {
		if (vis[i]) 
			continue;
		heads.push_back(i);
		int j = i;
		while (!vis[j]) {
			vis[j] = 1;
			j = p[j];
		}
	}
	if (sz(heads) == 1) {
		int u = p[1];
		gao(1, u);
		while (p[p[1]] != 1) 
			gao(1, p[1]);
		int w = p[1];
		gao(u, w);
		gao(1, w);
		gao(1, u);
	}
	else {
		for (int i = 0; i + 1 < sz(heads); i += 2)
			solve2(heads[i], heads[i + 1]);
		if (sz(heads) & 1) {
			int j = 1;
			while (p[j] != j) j++;
			solve2(j, heads.back());
		}
	}
	rep(i, 1, n + 1)
		assert(p[i] == i);
	cout << sz(res) << endl;
	for (auto [a, b] : res)
		cout << a << " " << b << endl;
	return 0;
}