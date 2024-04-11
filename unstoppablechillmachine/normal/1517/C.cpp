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
 
mt19937 rnd(time(0));

const int N = 510;
int ans[N][N], n;

void dfs(int a, int b, int &ost, int color) {
  ans[a][b] = color;
  ost--;
  if (ost == 0) {
    return;
  }
  if (b - 1 > 0 && !ans[a][b - 1]) {
    dfs(a, b - 1, ost, color);
    if (ost == 0) {
      return;
    }
  }
  if (a + 1 <= n && !ans[a + 1][b]) {
    dfs(a + 1, b, ost, color);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    //cout << x << endl;
    cin >> x;
    int ost = x;
    dfs(i, i, ost, x);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}