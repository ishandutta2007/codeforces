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

const int B = 320;

int freq[320][100050];
deque<int> X[320];

int main()
{
  int n = in();
  for (int i = 0; i < n; ++i) {
    int a = in();
    X[i / B].push_back(a);
    ++freq[i / B][a];
  }

  int lastans = 0;
  int q = in();
  for (int i = 0; i < q; ++i) {
    int typ = in();
    int l = in();
    int r = in();
    int k;
    if (typ == 2) {
      k = in();
    }

    l = (l + lastans - 1) % n;
    r = (r + lastans - 1) % n;
    if (l > r) {
      swap(l, r);
    }
    if (typ == 2) {
      k = (k + lastans - 1) % n + 1;
    }

    if (typ == 1) {
      if (l / B == r / B) {
        int bi = l / B;
        int v = X[bi][r % B];
        X[bi].erase(X[bi].begin() + r % B);
        X[bi].insert(X[bi].begin() + l % B, v);
      } else {
        int v = X[r / B][r % B];
        --freq[r / B][v];
        X[r / B].erase(X[r / B].begin() + r % B);
        ++freq[l / B][v];
        X[l / B].insert(X[l / B].begin() + l % B, v);

        int bi = l / B, bto = r / B;
        while (bi < bto) {
          int w = X[bi].back();
          --freq[bi][w];
          X[bi].pop_back();
          ++bi;
          ++freq[bi][w];
          X[bi].push_front(w);
        }
      }
    } else {
      int res = 0;
      if (l / B == r / B) {
        int bi = l / B, fr = l % B, to = r % B;
        for (int j = fr; j <= to; ++j) {
          if (X[bi][j] == k) {
            ++res;
          }
        }
      } else {
        while (l % B != 0) {
          if (X[l / B][l % B] == k) {
            ++res;
          }
          ++l;
        }
        while (r % B != B - 1) {
          if (X[r / B][r % B] == k) {
            ++res;
          }
          --r;
        }
        while (l < r) {
          res += freq[l / B][k];
          l += B;
        }
      }
      printf("%d\n", lastans = res);
    }
  }

  return 0;
}