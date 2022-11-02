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

int W[512], B[1024], V[512];

int main() {
  int N = in();
  int M = in();

  for (int i = 0; i < N; ++i) {
    W[i] = in();
  }

  vector<int> ord;
  for (int i = 0; i < M; ++i) {
    B[i] = in() - 1;
    if (!V[B[i]]) {
      ord.push_back(B[i]);
      V[B[i]] = 1;
    }
  }
  reverse(ord.begin(), ord.end());

  stack<int> S;
  for (int i = 0; i < ord.size(); ++i) {
    S.push(ord[i]);
  }

  int res = 0;
  for (int i = 0; i < M; ++i) {
    stack<int> T;
    while (S.top() != B[i]) {
      int u = S.top();
      S.pop();
      res += W[u];
      T.push(u);
    }
    S.pop();
    while (!T.empty()) {
      S.push(T.top());
      T.pop();
    }
    S.push(B[i]);
  }

  printf("%d\n", res);

  return 0;
}