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
 
const int BINF = 1e18 + 10;
 
pair<int, int> get(vector<int> &a, int x) {
  int num = upper_bound(all(a), x) - a.begin();
  pair<int, int> res = {0, 0};
  if (num > 0) {
    res.F = a[num - 1];
  }
  if (num < SZ(a)) {
    res.S = a[num];
  }
  return res;
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<int> srt;
  vector<vector<int>> have(n + 1);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    srt.pb(a);
    have[a].pb(b);
  }  
  sort(all(srt));
  srt.resize(unique(all(srt)) - srt.begin());
  for (int i = 1; i <= n; i++) {
    sort(all(have[i]));
    if (!have[i].empty()) {
      int x = have[i].back();
      have[i].pop_back();
      while (SZ(have[i]) > 1) {
        have[i].pop_back();
      }
      while (SZ(have[i]) < 2) {
        have[i].pb(x);
      }
    }
  }
  vector<int> safe;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    safe.pb(x);
  }
  sort(all(safe));
  int sz = SZ(srt);
  vector<vector<int>> dp(sz + 1, vector<int>(2, BINF));
  int fs = srt[0], l = have[srt[0]][0], r = have[srt[0]][1];
  if (fs == 1) {
    dp[1][0] = r - 1 + r - l;
    dp[1][1] = l - 1 + r - l;
  }
  else {
    pair<int, int> xx = get(safe, l), xx2 = get(safe, r);
    if (xx.F) {
      dp[1][1] = min(dp[1][1], fs - 1 + xx.F - 1 + abs(xx.F - l) + r - l);
    }
    if (xx.S) {
      dp[1][1] = min(dp[1][1], fs - 1 + xx.S - 1 + abs(xx.S - l) + r - l);
    }
    if (xx2.F) {
      dp[1][0] = min(dp[1][0], fs - 1 + xx2.F - 1 + abs(xx2.F - r) + r - l);
    }
    if (xx2.S) {
      dp[1][0] = min(dp[1][0], fs - 1 + xx2.S - 1 + abs(xx2.S - r) + r - l);
    }
  }
  for (int i = 1; i < sz; i++) {
    int up = srt[i] - srt[i - 1];
    for (int j = 0; j < 2; j++) {
      for (int j2 = 0; j2 < 2; j2++) {
        int fx = have[srt[i - 1]][j], tx = have[srt[i]][j2 ^ 1];
        int kek = have[srt[i]][1] - have[srt[i]][0];
        pair<int, int> xx = get(safe, tx);
        if (xx.F) {
          dp[i + 1][j2] = min(dp[i + 1][j2], dp[i][j] + up + abs(xx.F - fx) + abs(xx.F - tx) + kek);
        }
        swap(xx.F, xx.S);
        if (xx.F) {
          dp[i + 1][j2] = min(dp[i + 1][j2], dp[i][j] + up + abs(xx.F - fx) + abs(xx.F - tx) + kek);
        }
      }
    }
  }
  cout << min(dp[sz][0], dp[sz][1]) << '\n';
}