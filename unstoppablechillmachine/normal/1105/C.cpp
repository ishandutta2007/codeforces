#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;

const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * b) % MOD;
}

void source() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> c = {r / 3 - (l - 1) / 3, (r + 2) / 3 - (l + 1) / 3, (r + 1) / 3 - l / 3};
  vector<vector<int>> dp(n + 1, vector<int>(3));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int ost = 0; ost < 3; ost++) {
      for (int ost2 = 0; ost2 < 3; ost2++) {
        add(dp[i + 1][(ost + ost2) % 3], mult(dp[i][ost], c[ost2]));
      }
    }
  }
  cout << dp[n][0];
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}