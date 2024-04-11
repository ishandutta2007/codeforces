#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#define DIR 4
using namespace std;

struct P {
  int x, y;
  bool operator<(const P& rhs) const {
    return x == rhs.x ? y < rhs.y : x < rhs.x;
  }
};

const int maxn = 50 + 5;
int n, m, lake, ans, k;
bool v[maxn][maxn], o;
string mp[maxn];
queue<P> q;
short dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
vector<pair<int, vector<P>>> vec;

pair<int, vector<P>> BFS(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> mp[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (v[i][j]) continue;
      o = false;
      pair<int, vector<P>> ret;
      if (mp[i][j] == '.') {
        ret = BFS(i, j);
        if (!o) vec.push_back(ret), lake++;
      }
    }
  }
  sort(vec.begin(), vec.end());
  int vi = 0;
  while (lake > k) {
    ans += vec[vi].first;
    for (auto i : vec[vi].second) mp[i.x][i.y] = '*';
    vi++;
    lake--;
  }
  cout << ans << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << mp[i][j];
    cout << '\n';
  }
  return 0;
}

pair<int, vector<P>> BFS(int x, int y) {
  int sz = 0;
  vector<P> ret;
  while (q.size()) q.pop();
  q.push((P){ x, y });
  while (q.size()) {
    P p = q.front(); q.pop();
    // cout << p.x << ' ' << p.y << '\n';
    if (v[p.x][p.y]) continue;
    if (p.x == 0 || p.x == n - 1 || p.y == 0 || p.y == m - 1) o = true;
    sz++;
    ret.push_back(p);
    v[p.x][p.y] = true;
    for (int i = 0; i < 4; ++i) {
      // cout << "debug: " << p.x + dx[i] << ' ' << p.y + dy[i] << '\n';
      if (p.x + dx[i] >= 0 && p.x + dx[i] < n && p.y + dy[i] >= 0 && p.y + dy[i] < m) {
        // cout << "jizz\n";
        if (mp[p.x + dx[i]][p.y + dy[i]] == '.') q.push((P){ p.x + dx[i], p.y + dy[i] });
      }
    }
  }
  return make_pair(sz, ret);
}