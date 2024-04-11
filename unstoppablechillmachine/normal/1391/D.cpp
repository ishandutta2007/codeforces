#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll    

const int N = 1e6 + 10;

int c[4][N];
int dp3[N][2][2][2];
int dp2[N][2][2];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n >= 4) {
    cout << -1 << '\n';
    exit(0);
  }  
  if (n <= 1 || m <= 1) {
    cout << 0 << '\n';
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char x;
      cin >> x;
      c[i][j] = x - '0';  
    }
  }
  for (int i = 0; i <= m; i++) {
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        for (int c = 0; c < 2; c++) {
          dp2[i][a][b] = 1e9;
          dp3[i][a][b][c] = 1e9;
        }
      }
    }
  }
  if (n == 2) {
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        dp2[1][a][b] = (c[1][1] != a) + (c[2][1] != b);
      }
    }
    for (int i = 1; i < m; i++) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          for (int na = 0; na < 2; na++) {
            for (int nb = 0; nb < 2; nb++) {
              if ((a + b + na + nb) % 2 == 1) {
                dp2[i + 1][na][nb] = min(dp2[i + 1][na][nb], dp2[i][a][b] + (c[1][i + 1] != na) + (c[2][i + 1] != nb));
              }
            }
          }
        }
      }
    }
    int ans = 1e9;
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        ans = min(ans, dp2[m][a][b]);
      }
    }
    cout << ans << '\n';
  }
  else {
    assert(n == 3);
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        for (int cc = 0; cc < 2; cc++) {
          dp3[1][a][b][cc] = (c[1][1] != a) + (c[2][1] != b) + (c[3][1] != cc);
        }
      }
    }
    for (int i = 1; i < m; i++) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          for (int cc = 0; cc < 2; cc++) {
            for (int na = 0; na < 2; na++) {
              for (int nb = 0; nb < 2; nb++) {
                for (int nc = 0; nc < 2; nc++) {
                  if ((a + b + na + nb) % 2 == 1 && (b + cc + nb + nc) % 2 == 1) {
                    dp3[i + 1][na][nb][nc] = min(dp3[i + 1][na][nb][nc], dp3[i][a][b][cc] + (c[1][i + 1] != na) + (c[2][i + 1] != nb) + (c[3][i + 1] != nc));
                  }
                }
              }
            }
          }
        }
      }
    }
    int ans = 1e9;
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        for (int c = 0; c < 2; c++) {
          ans = min(ans, dp3[m][a][b][c]);
        }
      }
    }
    cout << ans << '\n';
  }
}