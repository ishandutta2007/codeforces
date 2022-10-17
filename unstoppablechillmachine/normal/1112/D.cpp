#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

vector<int> z_function(string &s) {
  int n = SZ(s), l = 0, r = 1;
  vector<int> z(n);
  for (int i = 1; i < n; i++) {
    z[i] = min(z[i - l], max(r - i, 0));
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

const int N = 5010;
int dp[N], calc[N];

void source() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  vector<int> arr;
  for (int i = 1; i <= n; i++) {
    arr = z_function(s);
    s.erase(s.begin());
    for (int j = 1; j < SZ(arr); j++) {
      calc[i + j] = max(calc[i + j], min(arr[j], j));
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + a;
    for (int from = 1; from < i; from++) {
      if (calc[from + 1] >= i - from) {
        dp[i] = min(dp[i], dp[from] + b);
      }
    }
  }
  cout << dp[n];
}
signed main() {
#ifdef extraterrestrial_
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}