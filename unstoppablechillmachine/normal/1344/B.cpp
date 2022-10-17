#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 1010;
char c[N][N];
bool have_u[N][N], have_d[N][N], have_r[N][N], have_l[N][N], used[N][N];
vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void dfs(int a, int b) {
  used[a][b] = true;
  for (auto it : delta) {
    int a2 = a + it.F, b2 = b + it.S;
    if (c[a2][b2] == '#' && !used[a2][b2]) {
      dfs(a2, b2);
    }
  } 
}

bool can1[N], can2[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      have_r[i][j] = have_r[i][j - 1];
      if (c[i][j] == '#' && c[i][j + 1] == '.') {
        have_r[i][j] = true;
      }
    }
    for (int j = m; j >= 1; j--) {
      have_l[i][j] = have_l[i][j + 1];
      if (c[i][j] == '#' && c[i][j - 1] == '.') {
        have_l[i][j] = true;
      }
    }
  }

  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      have_d[i][j] = have_d[i - 1][j];
      if (c[i][j] == '#' && c[i + 1][j] == '.') {
        have_d[i][j] = true;
      }
    }
    for (int i = n; i >= 1; i--) {
      have_u[i][j] = have_u[i + 1][j];
      if (c[i][j] == '#' && c[i - 1][j] == '.') {
        have_u[i][j] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!have_r[i][j - 1] && !have_l[i][j + 1] && !have_d[i - 1][j] && !have_u[i + 1][j]) {
        can1[i] = true;
        can2[j] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!can1[i]) {
      cout << -1 << '\n';
      exit(0);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!can2[i]) {
      cout << -1 << '\n';
      exit(0);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!used[i][j] && c[i][j] == '#') {
        ans++;
        dfs(i, j);
      }
    }
  }
  cout << ans << '\n';
}