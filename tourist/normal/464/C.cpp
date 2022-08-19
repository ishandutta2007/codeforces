#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long)a * b % md;
}

const int N = 400010;

char s[N];

char foo[N];

char dig[N];
vector <char> to[N];

int pw[N], val[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", foo);
    dig[i] = foo[0];
    to[i].clear();
    for (int j = 3; foo[j]; j++) {
      to[i].push_back(foo[j]);
    }
  }
  for (int d = 0; d < 10; d++) {
    pw[d] = 10;
    val[d] = d;
  }
  for (int i = m - 1; i >= 0; i--) {
    int d = dig[i] - '0';
    int n_pw = 1;
    int n_val = 0;
    int sz = to[i].size();
    for (int j = 0; j < sz; j++) {
      int t = to[i][j] - '0';
      n_val = mul(n_val, pw[t]);
      add(n_val, val[t]);
      n_pw = mul(n_pw, pw[t]);
    }
    pw[d] = n_pw;
    val[d] = n_val;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    int t = s[i] - '0';
    res = mul(res, pw[t]);
    add(res, val[t]);
  }
  printf("%d\n", res);
  return 0;
}