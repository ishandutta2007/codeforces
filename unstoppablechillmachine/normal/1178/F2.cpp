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

const int N = 1010;
vector<int> have[N];  
int dp[N][N], s1[N][N], s2[N][N], L[N], R[N], arr[N], n;

signed main() {
  ios_base::sync_with_stdio(0);
  int m;
  cin >> n >> m;
  int sz = 0;
    for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    if (!sz || arr[sz] != x) {
      arr[++sz] = x;
      if (sz > 1000) {
        cout << 0 << '\n';
        exit(0);
      }
    }
  }
  for (int i = 1; i <= sz; i++) {
    if (!L[arr[i]]) {
      L[arr[i]] = i;
    }
    R[arr[i]] = i;
    have[arr[i]].pb(i);
  }
  for (int l = 0; l <= sz + 1; l++) {
    for (int r = 0; r <= sz + 1; r++) {
      dp[l][r] = 1;
    }
  }
  for (int color = n; color >= 1; color--) {
    for (int l = 1; l <= L[color]; l++) {
      for (int l2 = l; l2 <= L[color]; l2++) {
        add(s1[color][l], mult(dp[l2][L[color] - 1], dp[l][l2 - 1]));
      }
    }
    for (int r = R[color]; r <= sz; r++) {
      for (int r2 = R[color]; r2 <= r; r2++) {
        add(s2[color][r], mult(dp[R[color] + 1][r2], dp[r2 + 1][r]));
      }
    }
    int sm = 1;
    for (int i = 0; i + 1 < SZ(have[color]); i++) {
      sm = mult(sm, dp[have[color][i] + 1][have[color][i + 1] - 1]);
    }
    for (int l = 1; l <= sz; l++) {
      for (int r = l; r <= sz; r++) {
        if (l > R[color] || r < L[color]) {
          continue;
        }      
        else if (max(l, L[color]) != L[color] || min(r, R[color]) != R[color]) {
          dp[l][r] = 0;
        }
        else {
          dp[l][r] = mult(sm, mult(s1[color][l], s2[color][r]));  
        }
      }
    }  
  }
  cout << dp[1][sz] << '\n';  
}