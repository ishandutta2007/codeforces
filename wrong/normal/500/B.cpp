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

int P[333], V[333];
int A[333][333];

int main() {
  int N = in();
  for (int i = 0; i < N; ++i) {
    P[i] = in();
  }
  for (int i = 0; i < N; ++i) {
    char a[333];
    scanf("%s", a);
    for (int j = 0; j < N; ++j) {
      A[i][j] = a[j] - '0';
    }
    A[i][i] = 1;
  }

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        A[i][j] |= A[i][k] & A[k][j];
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    vector<int> v, r;
    if (V[i]) {
      continue;
    }
    for (int j = 0; j < N; ++j) {
      if (A[i][j]) {
        v.push_back(j);
        r.push_back(P[j]);
      }
    }
    sort(r.begin(), r.end());
    for (int j = 0; j < v.size(); ++j) {
      P[v[j]] = r[j];
    }
  }

  for (int i = 0; i < N; ++i) {
    printf("%d%c", P[i], i + 1 == N ? '\n' : ' ');
  }

  return 0;
}