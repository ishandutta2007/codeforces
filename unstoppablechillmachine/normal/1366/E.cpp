#pragma GCC optimize("O3")
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
inline int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int mn = 1e9 + 10;
  vector<int> srt;
  map<int, int> lst;
  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    lst[a[i]] = i;
    mn = min(mn, a[i]);
    srt.pb(a[i]);
  }  
  sort(all(srt));
  srt.resize(unique(all(srt)) - srt.begin());
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    if (lst.find(b[i]) == lst.end()) {
      cout << 0 << '\n';
      exit(0);
    }
  }
  if (mn < b[1]) {
    cout << 0 << '\n';
    exit(0);
  }
  int ptr = 0, ans = 1;
  for (int i = 1; i < m; i++) {
    int cmax = 0;
    while (srt[ptr] < b[i + 1]) {
      cmax = max(cmax, lst[srt[ptr]]);
      ptr++;
    }
    if (cmax > lst[srt[ptr]]) {
      cout << 0 << '\n';
      exit(0);
    }
    ans = mult(ans, lst[srt[ptr]] - cmax);
  }
  cout << ans << '\n';
}