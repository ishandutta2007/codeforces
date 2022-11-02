#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

char field[512][512];
static int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

int deg[512][512];
vector<int> conn[512][512];
int U[512*512];

void init(int n) {
  for (int i = 0; i < n; ++i) {
    U[i] = i;
  }
}
int find(int x) {
  if (U[x] != x) {
    return U[x] = find(U[x]);
  }
  return U[x];
}
void uni(int x, int y) {
  U[find(x)] = find(y);
}

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 0; i < n; ++i) {
    cin >> field[i];
  }

  init(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == '.') {
        if (i + 1 < n && field[i + 1][j] == '.') {
          int u = i*m + j, v = (i+1)*m + j;
          if (find(u) != find(v)) {
            uni(u, v);
            conn[i][j].push_back(0);
            conn[i + 1][j].push_back(2);
          }
        }
        if (j + 1 < m && field[i][j + 1] == '.') {
          int u = i*m + j, v = i*m + j+1;
          if (find(u) != find(v)) {
            uni(u, v);
            conn[i][j].push_back(1);
            conn[i][j + 1].push_back(3);
          }
        }
      }
    }
  }

  priority_queue<pair<int, pair<int, int>>> Q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == '.') {
        deg[i][j] = conn[i][j].size();
        Q.push(make_pair(-deg[i][j], make_pair(i, j)));
      }
    }
  }

  int filled = 0;
  while (filled < k) {
    pair<int, pair<int, int>> qq = Q.top(); Q.pop();
    int d = -qq.first, r = qq.second.first, c = qq.second.second;

    if (d != deg[r][c] || field[r][c] != '.') {
      continue;
    }

    ++filled;
    field[r][c] = 'X';
    for (int i = 0; i < conn[r][c].size(); ++i) {
      int rr = r + dr[conn[r][c][i]], cc = c + dc[conn[r][c][i]];
      if (field[rr][cc] == '.') {
        --deg[rr][cc];
        Q.push(make_pair(-deg[rr][cc], make_pair(rr, cc)));
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << field[i] << endl;
  }

  return 0;
}