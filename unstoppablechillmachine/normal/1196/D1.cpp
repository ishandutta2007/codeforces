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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> pref(3, vector<int>(n));
    vector<char> need = {'R', 'G', 'B'};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 2ll; j++) {
        int cr = (i - j + 3) % 3;
        if (s[i] != need[cr]) {
          pref[j][i]++;
        }
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        pref[j][i] += pref[j][i - 1];
      }
    }
    int ans = INF;
    for (int i = 0; i + k - 1 < n; i++) {
      for (int j = 0; j <= 2ll; j++) {
        int sum = pref[j][i + k - 1];
        if (i) {
          sum -= pref[j][i - 1];
        }
        ans = min(ans, sum);
      }
    }
    cout << ans << '\n';
  }  
}