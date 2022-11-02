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
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

char S[222222];

int main() {
  scanf("%s", S);
  int d = 0;
  for (int i = 0; S[i]; ++i) {
    d += (S[i] == '0' ? 1 : -1);
  }
  if (d <= 0) {
    puts("-1");
    return 0;
  }

  vector<vector<int>> res(d);
  queue<int> ks[2];
  for (int i = 0; i < d; ++i) {
    ks[0].push(i);
  }
  for (int i = 0; S[i]; ++i) {
    const int ch = S[i] - '0';
    if (ks[ch].empty()) {
      puts("-1");
      return 0;
    }
    const int k = ks[ch].front(); ks[ch].pop();
    res[k].push_back(i + 1);
    ks[1 - ch].push(k);
  }
  if (!ks[0].empty()) {
    puts("-1");
    return 0;
  }

  printf("%d\n", d);
  for (int i = 0; i < d; ++i) {
    printf("%d", (int)res[i].size());
    for (const int j : res[i]) {
      printf(" %d", j);
    }
    puts("");
  }

  return 0;
}