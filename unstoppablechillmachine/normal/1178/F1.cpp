#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const int MOD = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int sum(int a, int b) {
  return (a + b) % MOD;
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

const int N = 510;
int dp[N][N], s1[N][N], s2[N][N], pos[N];

signed main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    pos[c] = i;
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      dp[i][j] = 1;
    }
  }
  for (int color = n; color >= 1; color--) {
    for (int l = 1; l <= pos[color]; l++) {
      for (int l2 = l; l2 <= pos[color]; l2++) {
        add(s1[color][l], mult(dp[l2][pos[color] - 1], dp[l][l2 - 1]));
      }  
    }
    for (int r = pos[color]; r <= n; r++) {
      for (int r2 = pos[color]; r2 <= r; r2++) {
        add(s2[color][r], mult(dp[pos[color] + 1][r2], dp[r2 + 1][r]));
      }
    }
    for (int l = 1; l <= n; l++) {
      for (int r = 1; r <= n; r++) {
        if (l > r) {
          dp[l][r] = 1;
        }
        else if (pos[color] >= l && pos[color] <= r) {
          dp[l][r] = mult(s1[color][l], s2[color][r]);
        }
      }
    }
  }
  cout << dp[1][n] << '\n';
}