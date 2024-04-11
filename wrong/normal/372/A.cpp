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

int N, S[500050];

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &S[i]);
  }

  sort(S, S + N);

  int lo = 0, hi = N / 2 + 1;
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    bool ok = mid - 1 < N - mid;
    for (int i = 0; i < mid; ++i) {
      ok &= S[i] * 2 <= S[N - mid + i];
    }
    if (ok) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  cout << N - lo << endl;

  return 0;
}