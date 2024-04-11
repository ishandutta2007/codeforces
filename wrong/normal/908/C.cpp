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

int PX[1024];
double PY[1024];

int main() {
  int N = in();
  int R = in();

  for (int i = 0; i < N; ++i) {
    int X = in();
    double Y = R;
    for (int j = 0; j < i; ++j) {
      if (PX[j] - 2 * R <= X && X <= PX[j] + 2 * R) {
        chmax(Y, sqrt(4.0 * R * R - (PX[j] - X) * (PX[j] - X)) + PY[j]);
      }
    }
    PX[i] = X;
    PY[i] = Y;
    printf("%.12f%c", PY[i], i+1==N ? '\n' : ' ');
  }

  return 0;
}