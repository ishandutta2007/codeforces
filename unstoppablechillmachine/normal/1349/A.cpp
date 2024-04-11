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

const int N = 2e5 + 10;
int mn1[N], mn2[N];

inline void upd(int id, int vl) {
  //cout << id << ' ' << vl << '\n';
  if (vl < mn1[id]) {
    mn2[id] = mn1[id];
    mn1[id] = vl;
  }
  else if (vl < mn2[id]) {
    mn2[id] = vl;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int lim = 2e5;
  for (int i = 1; i <= lim; i++) {
    mn1[i] = 1e9;
    mn2[i] = 1e9;
  }
  int n;
  cin >> n;
  vector<int> al(lim + 1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        al[j]++;
        int cnt = 0;
        while (x % j == 0) {
          x /= j;
          cnt++;
        }
        upd(j, cnt);
      }
    }
    if (x > 1) {
      upd(x, 1);
      al[x]++;
    }
  }
  int ans = 1;
  for (int i = 2; i <= lim; i++) {
    if (al[i] == n) {
      for (int j = 0; j < mn2[i]; j++) {
        ans *= i;
      }
    }
    else if (al[i] == n - 1) {
      for (int j = 0; j < mn1[i]; j++) {
        ans *= i;
      }
    }
  }
  cout << ans << '\n';
}