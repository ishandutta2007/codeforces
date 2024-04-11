#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void solve(int tc) {
  int n, m;
  cin >> n >> m;
  vector<vi> v(n, vi(m));

  int dx[] = {-1,-1,-1,0,1,1,1,0};
  int dy[] = {-1,0,1,1,1,0,-1,-1};

  auto valid = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };


  auto go = [&](int x, int y) {
    rep(d,0,8) {
      int nx = x + dx[d], ny = y + dy[d];
      if(!valid(nx,ny)) continue;
      if(v[nx][ny]) return;
    }
    v[x][y] = 1;
  };

  rep(i,0,n) rep(j,0,m) if(i == 0 || j == 0 || i == n-1 || j == m-1) go(i,j);

  rep(i,0,n) {
    rep(j,0,m) cout << v[i][j];
    cout << "\n";
  }
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}