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
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> inline void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> inline void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }

struct item {
  int C, H, T;
  item() { }
  item(int c, int h, int t) : C(c), H(h), T(t) {}
} I[4096];
bool operator < (const item& a, const item& b) {
  return a.T < b.T;
}

struct query {
  int A, B, X, Y;
  query() { }
  query(int a, int b) : A(a), B(b) { }
} Q[20050];
int ans[20050];

vector<int> app[20050], del[20050], queries[20050];

int start[1<<16], cnt[1<<16], mid[1<<16];
vector<int> qs[1<<16];

void maket(int x, int s, int k) {
  start[x] = s;
  cnt[x] = k;
  mid[x] = s + k / 2;
  if (k <= 2) {
    return;
  }
  maket(2 * x + 0, s, k / 2);
  maket(2 * x + 1, s + k / 2, k - k / 2);
}

void inst(int x, int qi) {
  if (Q[qi].X < mid[x] && mid[x] <= Q[qi].Y) {
    qs[x].push_back(qi);
    return;
  }
  if (Q[qi].Y < mid[x]) inst(2 * x + 0, qi);
  else                  inst(2 * x + 1, qi);
}

int dp[4096][4096];

void solve(int x) {
  if (!qs[x].empty()) {
    for (int b = 0; b < I[mid[x]].C; ++b) {
      dp[mid[x]][b] = 0;
    }
    for (int b = I[mid[x]].C; b <= 4000; ++b) {
      dp[mid[x]][b] = I[mid[x]].H;
    }
    for (int i = mid[x] + 1; i < start[x] + cnt[x]; ++i) {
      memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
      for (int b = 4000 - I[i].C; b >= 0; --b) {
        chmax(dp[i][b + I[i].C], dp[i - 1][b] + I[i].H);
      }
    }
    for (int b = 0; b < I[mid[x] - 1].C; ++b) {
      dp[mid[x] - 1][b] = 0;
    }
    for (int b = I[mid[x] - 1].C; b <= 4000; ++b) {
      dp[mid[x] - 1][b] = I[mid[x] - 1].H;
    }
    for (int i = mid[x] - 2; i >= start[x]; --i) {
      memcpy(dp[i], dp[i + 1], sizeof(dp[i]));
      for (int b = 4000 - I[i].C; b >= 0; --b) {
        chmax(dp[i][b + I[i].C], dp[i + 1][b] + I[i].H);
      }
    }
    for (const int q : qs[x]) {
      ans[q] = 0;
      for (int b = 0; b <= Q[q].B; ++b) {
        chmax(ans[q], dp[Q[q].X][b] + dp[Q[q].Y][Q[q].B - b]);
      }
    }
  }
  if (cnt[x] > 2) {
    solve(2 * x + 0);
    solve(2 * x + 1);
  }
}

int main() {
  int N = in();
  int P = in();

  for (int i = 0; i < N; ++i) {
    I[i].C = in();
    I[i].H = in();
    I[i].T = in();
  }
  sort(I, I + N);
  for (int i = 0; i < N; ++i) {
    app[I[i].T].push_back(i);
    del[I[i].T + P].push_back(i);
  }

  int K = in();
  for (int i = 0; i < K; ++i) {
    Q[i].A = in();
    Q[i].B = in();
    queries[Q[i].A].push_back(i);
  }

  set<int> items;
  for (int t = 0; t <= 20000; ++t) {
    for (const int d : del[t]) {
      items.erase(d);
    }
    for (const int a : app[t]) {
      items.insert(a);
    }
    for (const int q : queries[t]) {
      if (items.empty()) {
        Q[q].X = Q[q].Y = -1;
      } else {
        Q[q].X = *items.begin();
        Q[q].Y = *items.rbegin();
      }
    }
  }

  maket(1, 0, N);
  for (int i = 0; i < K; ++i) {
    if (Q[i].X < 0) {
      ans[i] = 0;
    } else if (Q[i].X == Q[i].Y) {
      ans[i] = Q[i].B < I[Q[i].X].C ? 0 : I[Q[i].X].H;
    } else {
      inst(1, i);
    }
  }

  solve(1);

  for (int i = 0; i < K; ++i) {
    printf("%d\n", ans[i]);
  }

  return 0;
}