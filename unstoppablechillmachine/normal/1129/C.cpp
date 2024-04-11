#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
//#define int ll
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

const int root = 1;
int cnt = 1;
const int N = 1e7 + 10;
int go[N][2];

void source() {
  int n;
  cin >> n;
  vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  vector<string> bad = {"0011", "0101", "1110", "1111"};
  vector<bool> can(n + 1, true);
  for (int i = 1; i <= n; i++) {
    if (i + 3 > n) {
      can[i] = false;
      continue;
    }
    string s;
    for (int j = i; j <= i + 3; j++) {
      if (c[j]) {
        s += "1";
      }
      else {
        s += "0";
      }
    }
    for (auto it : bad) {
      if (s == it) {
        can[i] = false;
        break;
      }
    }
  }
  /*for (int i = 1; i <= n; i++) {
    cout << can[i] << ' ';
  }
  cout << '\n';*/
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int l = 1; l <= n; l++) {
    dp[l][l - 1] = 1;
    dp[l][l] = 1;
    for (int r = l + 1; r <= n; r++) {
      for (int f = max(r - 3, l - 1); f < r; f++) {
        add(dp[l][r], dp[l][f]);
      }
      if (r - 4 >= l - 1 && can[r - 3]) {
        add(dp[l][r], dp[l][r - 4]);
      }
    }
  }
  /*for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      cout << dp[l][r] << ' ';
    }
    cout << '\n';
  }*/
  vector<int> calc(n + 1);
  for (int l = 1; l <= n; l++) {
    int v = root;
    for (int r = l; r <= n; r++) {
      if (!go[v][c[r]]) {
        go[v][c[r]] = ++cnt;
        add(calc[r], dp[l][r]);
      }
      v = go[v][c[r]];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    add(ans, calc[i]);
    cout << ans << '\n';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopenpen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}