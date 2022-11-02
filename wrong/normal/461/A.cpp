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

Int N, A[300050];

int main()
{
  N = in();
  for (int i = 0; i < N; ++i) {
    A[i] = in();
  }
  sort(A, A + N);

  Int res = 0;
  for (int i = 0; i < N; ++i) {
    res += (i == N - 1 ? i + 1 : i + 2) * A[i];
  }
  cout << (N == 1 ? A[0] : res) << endl;

  return 0;
}