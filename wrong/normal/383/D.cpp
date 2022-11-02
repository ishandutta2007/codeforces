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

const Int MO = 1000000007;

int A[1024];

struct res {
  int sum;
  Int ans, all_[20050], left_[20050], right_[20050];
  Int *all, *left, *right;
  res() {
    ans = 0;
    memset(all_, 0, sizeof(all_));
    memset(left_, 0, sizeof(left_));
    memset(right_, 0, sizeof(right_));
    all = &all_[10000];
    left = &left_[10000];
    right = &right_[10000];
  }
};

Int tmp[20050];

void expand(int sum, Int* dp, int from, int to, Int* res) {
  int i = from;
  Int *p = dp, *q = &tmp[10000];
  while (true) {
    int v = A[i];
    memset(q - sum - v, 0, sizeof(Int) * ((sum + v) * 2 + 1));
    for (int j = -sum; j <= sum; ++j) {
      if (p[j] > 0) {
        q[j + v] += p[j];
        if (q[j + v] >= MO) q[j + v] -= MO;
        q[j - v] += p[j];
        if (q[j - v] >= MO) q[j - v] -= MO;
      }
    }
    sum += v;
    for (int j = -sum; j <= sum; ++j) {
      res[j] += q[j];
      if (res[j] >= MO) res[j] -= MO;
    }
    swap(p, q);
    if (i == to) break;
    if (i < to) ++i; else --i;
  }
  if (p != dp) {
    memcpy(dp - sum, p - sum, sizeof(Int) * (sum * 2 + 1));
  }
}

res* solve(int lo, int hi) {
  if (hi - lo == 1) {
    res* ret = new res();
    int v = A[lo];
    ret->sum = v;
    ret->all[v] = ret->all[-v] = 1;
    ret->left[v] = ret->left[-v] = 1;
    ret->right[v] = ret->right[-v] = 1;
    ret->ans = 0;  // v > 0
    return ret;
  }
  int mid = (hi + lo) / 2;
  res* lhs = solve(lo, mid);
  res* rhs = solve(mid, hi);
  res* ret = new res();
  ret->ans = (lhs->ans + rhs->ans) % MO;
  for (int s = -lhs->sum; s <= lhs->sum; ++s) {
    ret->ans += lhs->right[s] * rhs->left[s] % MO;
    if (ret->ans >= MO) ret->ans -= MO;
  }

  expand(lhs->sum, lhs->all, mid, hi - 1, ret->left);
  expand(rhs->sum, rhs->all, mid - 1, lo, ret->right);
  for (int s = -lhs->sum; s <= lhs->sum; ++s) {
    ret->left[s] += lhs->left[s];
    if (ret->left[s] >= MO) ret->left[s] -= MO;
  }
  for (int s = -rhs->sum; s <= rhs->sum; ++s) {
    ret->right[s] += rhs->right[s];
    if (ret->right[s] >= MO) ret->right[s] -= MO;
  }

  ret->sum = lhs->sum + rhs->sum;
  for (int s = -ret->sum; s <= ret->sum; ++s) {
    ret->all[s] = lhs->all[s];
  }
  // cout <<lo<<" "<<hi<<": "<<endl;
  // cout <<"  L: "; pv(ret->left - ret->sum, ret->left + ret->sum + 1);
  // cout <<"  R: "; pv(ret->right - ret->sum, ret->right + ret->sum + 1);
  // cout <<"  A: "; pv(ret->all - ret->sum, ret->all + ret->sum + 1);
  delete lhs;
  delete rhs;
  return ret;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }

  printf("%d\n", (int)solve(0, n)->ans);

  return 0;
}