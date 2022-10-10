#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 3002;

int seg[2*MAX][2*MAX], N;

void build() {
  for (int x = 2*N; x; x--) for (int y = 2*N; y; y--) {
    if (x < N) seg[x][y] = min(seg[2*x][y], seg[2*x+1][y]);
    if (y < N) seg[x][y] = min(seg[x][2*y], seg[x][2*y+1]);
  }
}

int query(int x1, int y1, int x2, int y2) {
  int y3 = y1 + N, y4 = y2 + N;
  int ret = INF;
  for (x1 += N, x2 += N; x1 <= x2; ++x1 /= 2, --x2 /= 2)
    for (y1 = y3, y2 = y4; y1 <= y2; ++y1 /= 2, --y2 /= 2) {
      if ((x1&1) == 1 and (y1&1) == 1) ret = min(ret, seg[x1][y1]);
      if ((x1&1) == 1 and (y2&1) == 0) ret = min(ret, seg[x1][y2]);
      if ((x2&1) == 0 and (y1&1) == 1) ret = min(ret, seg[x2][y1]);
      if ((x2&1) == 0 and (y2&1) == 0) ret = min(ret, seg[x2][y2]);
    }
  return ret;
}

int main(){ _
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  N = max(n, m);
  ll g0, x, y, z; cin >> g0 >> x >> y >> z;
  vector<ll> g(n*m+1);
  g[0] = g0;
  for (int i = 1; i <= n*m; i++)
    g[i] = (g[i-1]*x + y)%z;

  vector<vector<int>> h(n+1, vector<int>(m+1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      h[i][j] = g[(i-1)*m+j-1];

//for (int i = 0; i < 2*MAX; i++)
//	for (int j = 0; j < 2*MAX; j++)asd
//		seg[i][j] = INF;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      seg[i+N][j+N] = h[i][j];

  build();

  ll ans = 0;
  for (int i = 1; i <= n-a+1; i++){
    for (int j = 1; j <= m-b+1; j++){
      ans += query(i, j, i+a-1, j+b-1);
    }
  }
  cout << ans << endl;

  exit(0);
}