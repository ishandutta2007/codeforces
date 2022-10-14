#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;

ll n, t, k, x, y, m;
ll a[100500], b[100500];
ll dp[105][20050];
string s;

int main() {
  cin >> t;
  for (int ii = 0; ii < t; ii++){
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    for (int i = 0; i <= n * 101 + 5; i++) {
      for (int j = 0; j <= n; j++) {
        dp[j][i] = -(ll)1e+18;
      }
    }
    dp[0][0] = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= sum; j++) {
        dp[i + 1][j + a[i]] = max(dp[i + 1][j + a[i]], dp[i][j] + j * b[i] + (sum - j) * a[i]);
        dp[i + 1][j + b[i]] = max(dp[i + 1][j + b[i]], dp[i][j] + j * a[i] + (sum - j) * b[i]);
      }
      sum += a[i] + b[i];
    }
    ll ans = 0;
    for (int j = 0; j <= sum; j++) {
      ans = max(ans, dp[n][j]);
    }
    ll tmp = 0;
    for (int i = 0; i < n; i++) {
      tmp += a[i] * a[i] * (n - 1);
      tmp += b[i] * b[i] * (n - 1);
    }
    ll dob = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
          dob += a[i] * b[j];
          dob += a[i] * a[j];
          dob += b[i] * a[j];
          dob += b[i] * b[j];
      }
    }
    cout << tmp + (dob - ans) * 2 << "\n";
  }
  return 0;
}