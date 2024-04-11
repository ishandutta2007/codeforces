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

const int BINF = int(1e18) + 10;
const int N = 1010;
int upd[N][N];
char c[N][N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, Q;
  cin >> n >> m >> Q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
      upd[i][j] = BINF;
    }
  }
  //cout << upd[1][1] << '\n';
  queue<pair<int, int>> q;
  vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (auto it : delta) {
        int i2 = i + it.F, j2 = j + it.S;
        if (i2 >= 1 && i2 <= n && j2 >= 1 && j2 <= m && c[i2][j2] == c[i][j]) {
          upd[i][j] = 1;
          q.push({i, j});
        }
      }
    }
  }
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (auto it : delta) {
      pair<int, int> to = {cur.F + it.F, cur.S + it.S};
      if (to.F >= 1 && to.F <= n && to.S >= 1 && to.S <= m && upd[to.F][to.S] == BINF) {
        upd[to.F][to.S] = upd[cur.F][cur.S] + 1;
        q.push(to);
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    int a, b, tt;
    cin >> a >> b >> tt;
    if (tt < upd[a][b]) {
      cout << c[a][b] << '\n';
    }
    else {
      if ((tt - upd[a][b]) % 2 == 0) {
        cout << char('0' + (c[a][b] - '0') ^ 1) << '\n';
      }
      else {
        cout << c[a][b] << '\n';
      }
    }
  }
}