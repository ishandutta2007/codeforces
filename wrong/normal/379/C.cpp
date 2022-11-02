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

pair<int, int> A[300050];
int B[300050];

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    A[i].second = i;
    scanf("%d", &A[i].first);
  }
  sort(A, A + n);

  int last_gave = 0;
  for (int i = 0; i < n; ++i) {
    if (last_gave < A[i].first) {
      B[A[i].second] = A[i].first;
      last_gave = A[i].first;
    } else {
      B[A[i].second] = ++last_gave;
    }
  }

  for (int i = 0; i < n; ++i) {
    printf("%d%c", B[i], i==n-1 ? '\n' : ' ');
  }

  return 0;
}