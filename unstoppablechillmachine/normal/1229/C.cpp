#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
vector<int> in[N];
int cnt[N];
ll ans;
inline void sub(int v) {
  ans -= (cnt[v] - SZ(in[v])) * 1ll * SZ(in[v]);
}

inline void add(int v) {
  ans += (cnt[v] - SZ(in[v])) * 1ll * SZ(in[v]);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u < v) {
      swap(u, v);
    }
    in[v].pb(u);
    cnt[v]++;
    cnt[u]++;
  }  
  for (int i = 1; i <= n; i++) {
    add(i);
  }
  cout << ans << '\n';
  int q;
  cin >> q;
  while (q--) {
    int v;
    cin >> v;
    sub(v);
    for (auto it : in[v]) {
      sub(it);
      in[it].pb(v);
      add(it);
    }
    in[v] = {};
    cout << ans << '\n';
  }
}