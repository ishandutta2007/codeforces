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

int main()
{
  ios::sync_with_stdio(false);

  int m;
  cin >> m;

  vector<int> t(m), a(m), b(m);
  for (int i = 0; i < m; ++i) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> a[i];
    } else {
      cin >> a[i] >> b[i];
    }
  }

  int n;
  cin >> n;

  vector<Int> q(n);
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
    --q[i];
  }

  Int len = 0;
  int ptr = 0;
  vector<int> sol(n), first;
  for (int i = 0; i < m; ++i) {
    if (t[i] == 1) {
      if (ptr < n && q[ptr] == len) {
        sol[ptr++] = a[i];
      }
      if (first.size() <= 100050) {
        first.push_back(a[i]);
      }
      ++len;
    } else {
      Int nextlen = len + a[i] * (Int)b[i];
      for (; ptr < n && len <= q[ptr] && q[ptr] < nextlen; ++ptr) {
        Int ni = q[ptr] - len;
        sol[ptr] = first[ni % a[i]];
      }
      for (int c = 0; first.size() <= 100050 && c < b[i]; ++c) {
        for (int j = 0; first.size() <= 100050 && j < a[i]; ++j) {
          first.push_back(first[j]);
        }
      }
      len = nextlen;
    }
  }

  for (int i = 0; i < sol.size(); ++i) {
    cout << sol[i];
    if (i + 1 == sol.size()) cout << endl;
    else cout << ' ';
  }

  return 0;
}