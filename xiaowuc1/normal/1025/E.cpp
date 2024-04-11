#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> state;

int g[55][55];

int dp[55][55];
pii par[55][55];

int dx[4]{-1,0,1,0};
int dy[4]{0,1,0,-1};

inline string genMove(int fromx, int fromy, int tox, int toy, bool rev) {
  if(!rev) {
    return to_string(fromx) + " " + to_string(fromy) + " " + to_string(tox) + " " + to_string(toy);
  }
  return to_string(tox) + " " + to_string(toy) + " " + to_string(fromx) + " " + to_string(fromy);
}

void move(int sx, int sy, int ex, int ey, int n, vector<string>& ret, bool rev) {
  if(sx == ex && sy == ey) return;
  if(g[ex][ey]) return;
  memset(dp, 1, sizeof(dp));
  dp[sx][sy] = 0;
  queue<pii> q;
  q.push({sx, sy});
  while(sz(q) && dp[ex][ey] > 1e6) {
    pii curr = q.front(); q.pop();
    for(int k = 0; k < 4; k++) {
      int nx = curr.first + dx[k];
      int ny = curr.second + dy[k];
      if(nx <= 0 || nx > n || ny <= 0 || ny > n || g[nx][ny]) continue;
      if(dp[nx][ny] > 1 + dp[curr.first][curr.second]) {
        dp[nx][ny] = 1 + dp[curr.first][curr.second];
        q.push({nx, ny});
        par[nx][ny] = curr;
      }
    }
  }
  if(dp[ex][ey] > 1e6) return;
  g[ex][ey] = g[sx][sy];
  g[sx][sy] = 0;
  stack<string> ans;
  while(ex != sx || ey != sy) {
    pii orig = par[ex][ey];
    ans.push(genMove(orig.first, orig.second, ex, ey, rev));
    ex = orig.first;
    ey = orig.second;
  }
  while(sz(ans)) {
    ret.push_back(ans.top()); ans.pop();
  }
}

vector<string> force(int n, vector<pii>& v, bool rev) {
  memset(g, 0, sizeof(g));
  for(int i = 0; i < sz(v); i++) {
    g[v[i].first][v[i].second] = i+1;
  }
  vector<string> ret;
  // step 1 - get distinct x coordinates
  while(true) {
    bool done = true;
    for(int i = 1; i <= sz(v); i++) {
      if(g[i][i] == 0) {
        done = false;
        break;
      }
    }
    if(done) break;
    int cand = 1;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n && cand <= n; j++) {
        if(g[i][j]) {
          move(i, j, cand, cand, n, ret, rev);
          cand++;
        }
      }
    }
  }
  // step 2 - push to correct col
  for(int i = 1; i <= sz(v); i++) {
    int j = i;
    while(j > g[i][j]) {
      swap(g[i][j], g[i][j-1]);
      ret.push_back(genMove(i, j, i, j-1, rev));
      j--;
    }
    while(j < g[i][j]) {
      swap(g[i][j], g[i][j+1]);
      ret.push_back(genMove(i, j, i, j+1, rev));
      j++;
    }
  }
  // step 3 - push to correct row
  for(int j = 1; j <= sz(v); j++) {
    int i = 1;
    while(g[i][j] == 0) i++;
    while(i > g[i][j]) {
      swap(g[i][j], g[i-1][j]);
      ret.push_back(genMove(i, j, i-1, j, rev));
      i--;
    }
    while(i < g[i][j]) {
      swap(g[i][j], g[i+1][j]);
      ret.push_back(genMove(i, j, i+1, j, rev));
      i++;
    }
  }
  return ret;
}

void read(vector<pii>& v, int m) {
  v.resize(m);
  for(int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pii> u, v;
  read(u, m);
  read(v, m);
  vector<string> x = force(n, u, false);
  vector<string> y = force(n, v, true);
  reverse(all(y));
  cout << sz(x) + sz(y) << "\n";
  for(string out: x) cout << out << "\n";
  for(string out: y) cout << out << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}