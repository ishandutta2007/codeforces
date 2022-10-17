#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void bad(int s = -1) {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  rep(i,0,n) cin>>v[i];

  int dx[] = {-1,0,1,0};
  int dy[] = {0,1,0,-1};

  auto valid = [&](int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
  };

  vector<vi> vis(n, vi(m,0));
  function<void(int,int)> dfs = [&](int x, int y) {
    if(vis[x][y]++) return;
    rep(d,0,4) {
      int nx = x + dx[d], ny = y + dy[d];
      if(!valid(nx,ny)) continue;
      if(v[nx][ny] == '#') dfs(nx, ny);
    }
  };

  int cnt = 0;
  rep(x,0,n) rep(y,0,m) {
    if(!vis[x][y] && v[x][y] == '#') {
      dfs(x,y);
      ++cnt;
    }
  }

  bool row = false, col = false;
  rep(i,0,n) {
    bool cur = true;
    rep(j,0,m) if(v[i][j] == '#') cur = false;
    if(cur) row = true;
    int s = 0;
    rep(j,1,m) if(v[i][j] != v[i][j-1]) ++s;
    if(s > 2) bad();
    if(s == 2 && v[i][0] == '#') bad();
  }
  rep(j,0,m) {
    bool cur = true;
    rep(i,0,n) if(v[i][j] == '#') cur = false;
    if(cur) col = true;
    int s = 0;
    rep(i,1,n) if(v[i][j] != v[i-1][j]) ++s;
    if(s > 2) bad();
    if(s == 2 && v[0][j] == '#') bad();
  }
  if(row ^ col) bad();
  cout << cnt << endl;
}