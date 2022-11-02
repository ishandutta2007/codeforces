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

int A[128][128], E[128], C[128];
int P[128];

int main() {
  int N = in();
  for (int i = 0; i < N; ++i) {
    char S[128];
    scanf("%s", S);
    for (int j = 0; j < N; ++j) {
      A[i][j] = S[j] - '0';
    }
  }

  for (int i = 0; i < N; ++i) {
    E[i] = in();
    P[i] = C[i] = 0;
  }

  while (true) {
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      ok &= E[i] != C[i];
      if (E[i] == C[i]) {
        ok = false;
        P[i] = 1;
        for (int j = 0; j < N; ++j) {
          C[j] += A[i][j];
        }
        break;
      }
    }
    if (ok) break;
  }

  int num = 0;
  for (int i = 0; i < N; ++i) {
    num += P[i];
  }
  printf("%d\n", num);
  if (num == 0) {
    puts("");
  }
  for (int i = 0; i < N; ++i) {
    if (P[i]) {
      printf("%d%c", i + 1, --num == 0 ? '\n' : ' ');
    }
  }

  return 0;
}