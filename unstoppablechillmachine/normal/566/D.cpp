#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

struct DSU {
  vector<int> p;
  DSU(int n) {
    p.resize(n + 1);
    iota(all(p), 0);
  }
  int find(int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  }
  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
      return;
    }
    p[a] = b;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  DSU A(n);
  set<int> kek;
  for (int i = 1; i < n; i++) {
    kek.insert(i);
  }
  for (int i = 0; i < m; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int a, b;
      cin >> a >> b;
      A.merge(a, b);
    }
    else if (type == 2) {
      int l, r;
      cin >> l >> r;
      for (;;) {
        auto it = kek.lower_bound(l);
        if (it == kek.end() || *it >= r) {
          break;
        }
        A.merge(*it, *it + 1);
        kek.erase(*it);
      }
    }
    else {
      int u, v;
      cin >> u >> v;
      if (A.find(u) == A.find(v)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
}