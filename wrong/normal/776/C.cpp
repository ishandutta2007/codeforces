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

Int S[100050];

int main() {
  Int N = in();
  Int K = in();

  vector<Int> ks;
  ks.push_back(1);
  while (true) {
    Int nxt = ks.back() * K;
    if (nxt > N * INF || nxt < -N * INF) {
      break;
    }
    if (K == 1) {
      break;
    }
    ks.push_back(nxt);
    if (K == -1) {
      break;
    }
  }

  S[0] = 0;
  for (int i = 1; i <= N; ++i) {
    S[i] = in();
    S[i] += S[i - 1];
  }

  map<Int, int> X;
  Int res = 0;
  for (int i = N; i >= 0; --i) {
    for (const Int k : ks) {
      if (X.count(S[i] + k)) {
        res += X[S[i] + k];
      }
    }
    X[S[i]]++;
  }

  printf("%lld\n", res);

  return 0;
}