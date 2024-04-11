#include <bits/stdc++.h>
#define dbg(x) cerr << ">>> " << x << endl
#define _ << ", " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
const int ms = 100100;

int dp[ms][100];
int pt[100];
int sum[100];

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int n, m, k;
  std::cin >> n >> m >> k;
  if(k == 1) {
    std::cout << "0\n";
    return 0;
  }
  {
    int v;
    std::cin >> v;
    if(v == -1) {
      for(int i = 0; i < m; i++) {
        dp[0][i] = 1;
      }
    } else {
      dp[0][v-1] = 1;
    }
    for(int i = 0; i < m; i++) {
      sum[i] = dp[0][i];
      pt[i] = 0;
    }
  }
  for(int i = 1; i < n; i++) {
    int v;
    std::cin >> v;
    for(int j = 0; j < m; j++) {
      if(i - pt[j] == k) {
        //std::cout << "aumentando pra " << j << '\n';
        sum[j] = (sum[j] - dp[pt[j]][j] + MOD) % MOD;
        pt[j]++;
      }
    }
    if(v == -1) {
      // solve for anything
      // the solution is all previous - current value
      int tot = 0;
      for(int j = 0; j < m; j++) {
        tot = (tot + sum[j]) % MOD;
      }
      for(int j = 0; j < m; j++) {
        dp[i][j] = (tot - sum[j] + MOD) % MOD;
      }
    } else {
      v--;
      for(int j = 0; j < m; j++) {
        if(j != v) {
          dp[i][v] = (dp[i][v] + sum[j]) % MOD;
          sum[j] = 0;
          pt[j] = i + 1;
        }
      }
    }
    for(int j = 0; j < m; j++) {
      sum[j] = (sum[j] + dp[i][j]) % MOD;
    }
  }
  for(int j = 0; j < m; j++) {
    if(n - pt[j] == k) {
      //std::cout << "aumentando pra " << j << '\n';
      sum[j] = (sum[j] - dp[pt[j]][j] + MOD) % MOD;
      pt[j]++;
    }
  }
  int ans = 0;
  for(int i = 0; i < m; i++) {
    ans = (ans + sum[i]) % MOD;
  }
  std::cout << ans << '\n';
  return 0;
}