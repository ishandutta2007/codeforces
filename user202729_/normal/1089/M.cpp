/*input
4 
0 1 0 1 
0 0 1 0 
0 1 0 0 
1 0 0 0
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
const int N = 10;
const int INF = numeric_limits<int>::max() / 2;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

namespace toposort {
vector<int> a[N];
int deg[N];
int n;
int Time = 0;
int nLabel[N];

void run(int _n, vector<pair<int, int>> &e) {
  n = _n;
  for (auto [u, v] : e) {
    a[u].push_back(v);
    deg[v]++;
  }

  queue<int> q;
  loop(i, 0, n - 1) {
    if (deg[i] == 0)
      q.push(i);
  }
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    nLabel[u] = Time++;
    for (auto v : a[u]) {
      deg[v]--;
      if (deg[v] == 0)
        q.push(v);
    }
  }
}
}; // namespace toposort

int n;
vector<vector<int>> a(N);

class SCC {
  void dfs(int u) {
    low[u] = num[u] = Time++;
    st.push(u);
    for (auto v : a[u]) {
      if (num[v] == -1)
        dfs(v);
      if (low[v] != INF)
        low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
      while (true) {
        int v = st.top();
        st.pop();
        in[v] = numcc;
        num[v] = low[v] = INF;
        if (v == u)
          break;
      }
      numcc++;
    }
  }

public:
  int n, Time = 0, numcc = 0;
  vector<int> low, num, in;
  stack<int> st;

  SCC() = default;
  explicit SCC(int n) : n(n), low(n + 5, -1), num(n + 5, -1), in(n + 5, -1){};

  void solve() {
    loop(i, 1, n) if (num[i] == -1) dfs(i);

    vector<pair<int, int>> e;
    loop(u, 1, n) for (auto v : a[u]) if (in[u] != in[v])
        e.push_back({in[u], in[v]});

    sort(e.begin(), e.end());
    e.resize(distance(e.begin(), unique(e.begin(), e.end())));

    toposort::run(numcc, e);
    loop(i, 1, n) in[i] = toposort::nLabel[in[i]];
  }
} con;

vector<pair<int, int>> e;

namespace Platform {
int nPlatform;
#ifdef UncleGrandpa
const int szBoard = 10;
const int maxPlatform = 10;
#else
const int szBoard = 100;
const int maxPlatform = 30;
#endif
char plat[maxPlatform][szBoard][szBoard];
bool used[szBoard][szBoard];

void fillInPlatform() {
  loop(i, 0, maxPlatform - 1) loop(j, 0, szBoard - 1) loop(k, 0, szBoard - 1) {
    if (i % 2 == 0)
      plat[i][j][k] = '.';
    else
      plat[i][j][k] = '#';
  }
  memset(used, 0, sizeof(used));
}

void crop(int lev, int x, int y) {
  assert(plat[lev * 2 + 1][x][y] == '#');
  plat[lev * 2 + 1][x][y] = '.';
}

void block(int lev, int x, int y) {
  loop(k, 0, 3) {
    int ax = x + dx[k];
    int ay = y + dy[k];
    assert(plat[lev * 2][ax][ay] == '.');
    plat[lev * 2][ax][ay] = '#';
  }
}

void buildPipe(int top, int bot, int x, int y) {
  loop(lev, top, bot) {
    if (lev != bot)
      crop(lev, x, y);
    if (lev + 1 != bot)
      block(lev + 1, x, y);
  }
}

void build(int top, int bot) {
  assert(top < bot);
  for (int i = 2; i < szBoard; i += 4) {
    for (int j = 2; j < szBoard; j += 4) {
      if (used[i][j])
        continue;
      used[i][j] = true;
      buildPipe(top, bot, i, j);
      return;
    }
  }
  assert(false);
}

void printBoard() {
  cout << szBoard << sp << szBoard << sp << nPlatform * 2 << endl;
  loop(i, 0, nPlatform * 2 - 1) {
    loop(j, 0, szBoard - 1) {
      loop(k, 0, szBoard - 1) { cout << plat[i][j][k]; }
      cout << endl;
    }
    cout << endl << endl;
  }
}

void run() {
  nPlatform = con.numcc;
  fillInPlatform();
  for (auto &[u, v] : e) {
    build(u, v);
  }
}

void putNumberIn(int lev, int x) {
  loop(i, 0, szBoard - 1) loop(j, 0, szBoard - 1) {
    if (plat[lev * 2][i][j] == '.') {
      plat[lev * 2][i][j] = char(x + '0');
      return;
    }
  }
}
}; // namespace Platform

void remakeE() {
  vector<pair<int, int>> ne;
  for (auto [u, v] : e) {
    u = con.in[u];
    v = con.in[v];
    if (u != v)
      ne.push_back({u, v});
  }
  sort(ne.begin(), ne.end());
  ne.resize(distance(ne.begin(), unique(ne.begin(), ne.end())));
  ne.swap(e);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  loop(i, 1, n) {
    loop(j, 1, n) {
      int t;
      cin >> t;
      if (t == 1) {
        a[i].push_back(j);
        e.push_back({i, j});
      }
    }
  }
  con = SCC(n);
  con.solve();

  remakeE();
  Platform::run();
  loop(i, 1, n) { Platform::putNumberIn(con.in[i], i); }
  Platform::printBoard();
}