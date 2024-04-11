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

const int N = 3e5 + 10;
const int L = sqrt(3e5);
int vl[N], a[N], b[N];
vector<pair<int, int>> que[N];
ll ans[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> vl[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    if (b[i] >= L) {
      for (int j = a[i]; j <= n; j += b[i]) {
        ans[i] += vl[j];
      }
    }
    else {
      que[a[i]].pb({b[i], i});
    }
  }
  deque<vector<ll>> calc;
  for (int i = n; i >= 1; i--) {
    vector<ll> cur(L, vl[i]);
    for (int j = 1; j < L; j++) {
      if (SZ(calc) >= j) {
        cur[j] += calc[j - 1][j];
      }
    }
    for (auto it : que[i]) {
      ans[it.S] = cur[it.F];
    }
    calc.push_front(cur);
    if (SZ(calc) > L) {
      calc.pop_back();
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}