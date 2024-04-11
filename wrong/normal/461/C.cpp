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

int N, B[100050];

void add(int x, int v) {
  while (x <= N) {
    B[x] += v;
    x += x & -x;
  }
}

int sum(int x) {
  int s = 0;
  while (x > 0) {
    s += B[x];
    x -= x & -x;
  }
  return s;
}

int main()
{
  N = in();
  int Q = in();

  for (int i = 1; i <= N; ++i) {
    add(i, 1);
  }

  int lef = 1, rig = N, wid = N;
  for (int i = 0; i < Q; ++i) {
    int ty = in();

    if (ty == 1) {
      int pos = in();
      if (pos > wid / 2) {
        pos = wid - pos;
        swap(lef, rig);
      }
      if (lef < rig) {
        for (int j = 0; j < pos; ++j) {
          int s = sum(lef + j) - sum(lef + j - 1);
          add(lef + 2 * pos - j - 1, s);
        }
        lef += pos;
      } else {
        for (int j = 0; j < pos; ++j) {
          int s = sum(lef - j) - sum(lef - j - 1);
          add(lef - 2 * pos + j + 1, s);
        }
        lef -= pos;
      }
      wid = abs(rig - lef) + 1;
    } else {
      int a = in();
      int b = in();
      if (lef <= rig) {
        printf("%d\n", sum(lef + b - 1) - sum(lef + a - 1));
      } else {
        printf("%d\n", sum(lef - a) - sum(lef - b));
      }
    }
    // printf("%d %d: ", lef, rig);
    // for (int p = 1; p <= N; ++p) {
    //   printf("%d ", sum(p) - sum(p - 1));
    // }
    // puts("");
  }

  return 0;
}