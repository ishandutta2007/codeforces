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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

vector<int> to[100050];
int col[100050];
Int one[100050], zero[100050];
const Int MO = 1000000007;

Int pow(Int x, int e) {
  Int v = 1;
  for (; e > 0; e >>= 1, x = (x * x) % MO) {
    if (e & 1) {
      v = (v * x) % MO;
    }
  }
  return v;
}

Int inv(Int x) {
  return pow(x, MO - 2);
}

void dfs(int u) {
  zero[u] = 1;
  one[u] = 0;
  for (const int& v : to[u]) {
    dfs(v);
    one[u] = (zero[u] * one[v] + one[u] * (zero[v] + one[v])) % MO;
    (zero[u] *= zero[v] + one[v]) %= MO;
  }

  if (col[u]) {
    one[u] = zero[u];
    zero[u] = 0;
  }
}

int main()
{
  int n = in();
  for (int i = 0; i < n - 1; ++i) {
    int p = in();
    to[p].push_back(i + 1);
  }
  for (int i = 0; i < n; ++i) {
    col[i] = in();
  }

  dfs(0);

  cout << one[0] << endl;

  return 0;
}