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
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      if (c == '+') {
        a[i] = 1;
      }
      else {
        a[i] = 0;
      }
    }
    struct node {
      int max_pref, min_pref, sum;
      node() : max_pref(0), min_pref(0), sum(0) {};
      node(int a, int b, int c) : max_pref(a), min_pref(b), sum(c) {};
    };
    vector<node> pref(n + 1), suf(n + 2);
    auto merge = [&](node lhs, node rhs) {
      node res;
      res.sum = lhs.sum + rhs.sum;
      res.min_pref = min(lhs.min_pref, lhs.sum + rhs.min_pref);
      res.max_pref = max(lhs.max_pref, lhs.sum + rhs.max_pref);
      return res;
    };
    vector<node> basis = {node(0, -1, -1), node(1, 0, 1)};
    for (int i = 1; i <= n; i++) {
      pref[i] = merge(pref[i - 1], basis[a[i]]);
    }
    for (int i = n; i >= 1; i--) {
      suf[i] = merge(basis[a[i]], suf[i + 1]);
    }
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      node cur = merge(pref[l - 1], suf[r + 1]);
      cout << cur.max_pref - cur.min_pref + 1 << '\n';
    }
  }
}