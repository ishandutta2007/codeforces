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

const int INF = 1e9 + 10;

signed main() {
  ios_base::sync_with_stdio(0);
  int q;
  cin >> q;
  while (q--) {
    int b, w;
    cin >> b >> w;
    if (b == w) {
      cout << "YES\n";
      for (int i = 1; i <= 2 * b; i++) {
        cout << 1 << ' ' << i << '\n';
      }
      continue;
    }
    pair<int, int> start;
    if (b < w) {
      start = {2, 3};
      swap(b, w);
    }
    else {
      start = {2, 2};
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < 2 * w; i++) {
      ans.pb({start.F + i, start.S});
    }
    b -= w;
    if (b > 0) {
      ans.pb({start.F - 1, start.S});
      b--;
    }
    for (int i = 0; i < w; i++) {
      if (b > 0) {
        ans.pb({start.F + 2 * i, start.S + 1});
        b--;
      }
      if (b > 0) {
        ans.pb({start.F + 2 * i, start.S - 1});
        b--;
      }
    }
    if (b > 0) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
      for (auto it : ans) {
        cout << it.F << ' ' << it.S << '\n';
      }
    }
  }  
}