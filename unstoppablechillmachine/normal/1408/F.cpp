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
  int n;
  cin >> n;
  int mx = 0;
  for (int i = 0; i < 20; i++) {
    if ((n >> i) & 1) {
      mx = (1 << i);
    }
  }
  int ost = n - mx;
  int len1 = 1;
  while (len1 < ost) {
    len1 *= 2;
  }
  vector<pair<int, int>> ans;
  for (int i = 0; (1 << i) <= len1; i++) {
    vector<bool> used(n + 1);
    for (int j = 1; j + (1 << i) <= len1; j++) {
      if (!used[j]) {
        used[j] = true;
        used[j + (1 << i)] = true;
        ans.pb({j, j + (1 << i)});
      }
    }
  }
  for (int i = 0; (1 << i) <= mx; i++) {
    vector<bool> used(n + 1);
    for (int j = n; j - (1 << i) >= n - mx + 1; j--) {
      if (!used[j]) {
        used[j] = true;
        used[j - (1 << i)] = true;
        ans.pb({j, j - (1 << i)});
      }
    }
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it.F << ' ' << it.S << '\n';
  }
}