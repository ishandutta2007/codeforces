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

const int N = 510;
int gr[N][N], vt[N][N];
char c[N][N];

int get1(int a, int b, int a2, int b2) {
  return gr[a2][b2] - gr[a - 1][b2] - gr[a2][b - 1] + gr[a - 1][b - 1];
}

int get2(int a, int b, int a2, int b2) {
  return vt[a2][b2] - vt[a - 1][b2] - vt[a2][b - 1] + vt[a - 1][b - 1];
}

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
    for (int j = 2; j <= m; j++) {
      gr[i][j] = gr[i][j - 1];
      if (c[i][j] == '.' && c[i][j - 1] == '.') {
        gr[i][j]++;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 2; i <= n; i++) {
      vt[i][j] = vt[i][j - 1];
      if (c[i][j] == '.' && c[i - 1][j] == '.')  {
        vt[i][j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      gr[i][j] += gr[i - 1][j];
      vt[i][j] += vt[i - 1][j];
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    int rez = 0;
    if (y < y2) {
      rez += get1(x, y + 1, x2, y2);
    }
    if (x < x2) {
      rez += get2(x + 1, y, x2, y2);
    }
    cout << rez << '\n';
  }
}