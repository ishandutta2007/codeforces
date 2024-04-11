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
#include <stack>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

char S[1<<20];
int N, A[21][1<<20];

int cnt_rec(int L, int R, int V, int d, int l, int r) {
  if (l == L && r == R) {
    return upper_bound(A[d] + l, A[d] + r, V) - (A[d] + l);
  }
  int mid = (l + r) / 2, res = 0;
  if (L < mid) res += cnt_rec(L, min(mid, R), V, d - 1, l, mid);
  if (R > mid) res += cnt_rec(max(mid, L), R, V, d - 1, mid, r);
  return res;
}

int cnt(int L, int R, int V) {
  return cnt_rec(L, R, V, 20, 0, 1<<20);
}

int main()
{
  scanf("%s", S);
  N = strlen(S);

  stack<int> P;
  for (int i = 0; i < N; ++i) {
    A[0][i] = INF;
    if (S[i] == '(') {
      P.push(i);
    } else if (!P.empty()) {
      A[0][P.top()] = i;
      P.pop();
    }
  }

  for (int i = 1; i <= 20; ++i) {
    int sz = 1 << i;
    for (int j = 0; j < N; j += sz) {
      int to = min(j + sz, N);
      if (to == j + sz) {
        merge(A[i - 1] + j, A[i - 1] + j + sz / 2, A[i - 1] + j + sz / 2, A[i - 1] + j + sz, A[i] + j);      
      } else if (to > j + sz / 2) {
        merge(A[i - 1] + j, A[i - 1] + j + sz / 2, A[i - 1] + j + sz / 2, A[i - 1] + to, A[i] + j);
      } else {
        copy(A[i - 1] + j, A[i - 1] + to, A[i] + j);
      }
    }
  }

  int M;
  scanf("%d", &M);

  for (int i = 0; i < M; ++i) {
    int L, R;
    scanf("%d%d", &L, &R);
    --L; --R;
    printf("%d\n", 2 * cnt(L, R + 1, R));
  }

  return 0;
}