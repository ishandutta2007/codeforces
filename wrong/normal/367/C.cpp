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

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int N, M;
struct coupon {
  int Q, W;
} C[100050];
bool operator < (const coupon& a, const coupon& b) {
  return a.W < b.W;
}

int main()
{
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &C[i].Q, &C[i].W);
  }
  sort(C, C + M);
  reverse(C, C + M);

  Int sol = 0, sum = 0;
  for (int i = 0; i < M; ++i) {
    sum += C[i].W;
    Int req = (Int)i * (i + 1) / 2;
    if ((i + 1) % 2 == 0) {
      req += i / 2;
    }
    if (req <= N - 1) {
      chmax(sol, sum);
    }
  }

  cout << sol << endl;
  return 0;
}