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

const int N = 1010;

struct DSU {
  vector<int> p, sz;
  DSU(int n) {
    p.resize(n + 1);
    iota(all(p), 0);
    sz.resize(n + 1, 1);
  }
  int find(int v) {
    return p[v] == v ? v : p[v] = find(p[v]);
  }

  bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
      return false;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    sz[a] += sz[b];
    p[b] = a;
    return true;
  }  
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  DSU A(n), B(n);
  for (int i = 0; i < m1; i++) {
    int u, v;
    cin >> u >> v;
    A.merge(u, v);
  }
  for (int i = 0; i < m2; i++) {
    int u, v;
    cin >> u >> v;
    B.merge(u, v);
  }
  vector<pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (A.find(i) != A.find(j) && B.find(i) != B.find(j)) {
        ans.pb({i, j});
        A.merge(i, j);
        B.merge(i, j);
      }
    }
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it.F << ' ' << it.S << '\n';
  }
}