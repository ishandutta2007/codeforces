#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int MOD = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> l(m), r(m), vl(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> vl[i];
  }
  int ans = 1;
  for (int bit = 0; bit < k; bit++) {
    vector<int> mx(n + 1), ban(n + 2, 0);
    for (int i = 0; i < m; i++) {
      int cur = (vl[i] >> bit) & 1;
      if (cur == 1) {
        ban[l[i]]++;
        ban[r[i] + 1]--;
      }
      else {
        mx[r[i]] = max(mx[r[i]], l[i]);
      }
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
      cur += ban[i];
      ban[i] = !!cur;
    }
    for (int i = 1; i <= n; i++) {
      mx[i] = max(mx[i], mx[i - 1]);
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      if (ban[i]) {
        pref[i] = pref[i - 1];
        continue;
      }
      int vl = 0;
      if (!mx[i - 1]) {
        vl++;
      }
      vl += pref[i - 1] - pref[max(0, mx[i - 1] - 1)];
      if (vl < 0) {
        vl += MOD;
      }
      if (vl >= MOD) {
        vl -= MOD;
      }
      pref[i] = pref[i - 1] + vl;
      if (pref[i] >= MOD) {
        pref[i] -= MOD;
      }
    }
    int vl = 0;
    if (!mx[n]) {
      vl++;
    }
    vl += pref[n] - pref[max(0, mx[n] - 1)];
    if (vl < 0) {
      vl += MOD;
    }
    if (vl >= MOD) {
      vl -= MOD;
    }
    ans = mult(ans, vl);
  }
  cout << ans << '\n';
}