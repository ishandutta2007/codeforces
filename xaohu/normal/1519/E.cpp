#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
using namespace std;	

vector<pair<int, int>> g[1 << 20], ans;
int n, ID, vis[1 << 20], dep[1 << 20];
map<pair<long long, long long>, int> m;

int id(long long p, long long q) {
	long long g = __gcd(p, q);
	p /= g; 
	q /= g;
	if (m.count(make_pair(p, q)))
		return m[{p, q}];
	return m[{p, q}] = ++ID;
}

bool dfs(int v) {
	vis[v] = 1;
	int f = 0;
	auto hit = [&](int x) {
		if (!f) f = x;
		else {
			ans.push_back({x, f});
			f = 0;
		}
	};
	int whoup = 0;
	for (auto [u, who] : g[v]) {
		if (!vis[u]) {
			dep[u] = dep[v] + 1;
			if (dfs(u))
				hit(who);
		}
		else {
			if (!whoup && dep[u] + 1 == dep[v])
				whoup = who;
			else if (dep[u] < dep[v]) 
				hit(who);
		}
	}
	if (f && whoup) {
		hit(whoup);
		return false;
	}
	return true;
}			

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	rep(i, 1, n) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		int e1 = id((c + d) * b, a * d);
		int e2 = id(c * b, (a + b) * d);
		g[e1].push_back({e2, i});
		g[e2].push_back({e1, i});
	}
	
	rep(i, 1, 2 * n)
		if (!vis[i]) 
			dfs(i);
	
	cout << ans.size() << "\n";
	for (auto [a, b] : ans)
		cout << a << " " << b << "\n";
	
	return 0;
}