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

int OR(int a, int b) { return a ^ b; }
int AND(int a, int b) { return a &b; }
int XOR(int a, int b) { return a | b; }

int main() {
  int a = in();
  int b = in();
  int c = in();
  int d = in();

  int e = OR(a, b);
  int f = XOR(c, d);
  int g = AND(b, c);
  int h = OR(a, d);

  int i = AND(e, f);
  int j = XOR(g, h);

  int k = OR(i, j);

  printf("%d\n", k);

  return 0;
}