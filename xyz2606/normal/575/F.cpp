#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5555;
const int MAXM = 11111;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int interval[MAXN][2];
int n, stx, m;
long long f[2][MAXM];
vector<int> axis;

void Init() {
  assert(scanf("%d%d", &n, &stx) == 2);
  axis.push_back(stx);
  for (int i = 1; i <= n; ++i) {
    assert(scanf("%d%d", interval[i] + 0, interval[i] + 1) == 2);
    axis.push_back(interval[i][0]);
    axis.push_back(interval[i][1]);
  }
  sort(axis.begin(), axis.end());
  axis.erase(unique(axis.begin(), axis.end()), axis.end());
  m = axis.size();
}

int Closest(int x, int id) {
  if (interval[id][0] <= x && x <= interval[id][1]) return 0;
  if (x < interval[id][0]) return interval[id][0] - x;
  return x - interval[id][1];
}

void Work() {
  int x = 0, y = 1;
  for (int i = 0; i < m; ++i) {
    f[x][i] = abs(axis[i] - stx);
  }
  // cerr << m << endl;
  for (int i = 1; i <= n; ++i) {
    swap(x, y);
    int k = 0;
    for (int j = 0; j < m; ++j) {
      while (k + 1 < m && f[y][k] + abs(axis[k] - axis[j]) >= f[y][k + 1] + abs(axis[k + 1] - axis[j])) ++k;
      // cerr << i << ' ' << axis[j] << ' ' << axis[k] << endl;
      f[x][j] = f[y][k] + abs(axis[k] - axis[j]) + Closest(axis[j], i);
      // cerr << i << '!' << axis[j] << ' ' << f[x][j] << endl;
    }
  }
  long long ans = f[x][0];
  for (int i = 0; i < m; ++i)
    if (f[x][i] < ans) ans = f[x][i];
  cout << ans << endl;
}

int main() {
  Init();
  Work();
  return 0;
}