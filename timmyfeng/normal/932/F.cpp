#include <bits/stdc++.h>
using namespace std;

// line container
// source: kactl

struct Line {
	mutable long long k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(long long x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const long long inf = LLONG_MAX;
	long long div(long long a, long long b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(long long k, long long m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	long long query(long long x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

const int N = 100000 + 1;

long long a[N], b[N], cost[N];
vector<int> adj[N];

LineContainer dfs(int u, int p = 0) {
  LineContainer sub;
  for (auto c : adj[u]) {
    if (c != p) {
      LineContainer child = dfs(c, u);
      if (child.size() > sub.size()) {
        swap(child, sub);
      }

      for (auto l : child) {
        sub.add(l.k, l.m);
      }
    }
  }

  if (!sub.empty()) {
    cost[u] = -sub.query(a[u]);
  }
  sub.add(-b[u], -cost[u]);
  return sub;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  for (int i = 1; i <= n; ++i) {
    cout << cost[i] << " ";
  }
  cout << "\n";
}