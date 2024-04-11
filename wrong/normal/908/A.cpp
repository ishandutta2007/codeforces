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
Int lin() { Int x; scanf("%lld", &x); return x; }

bool vowel(char ch) {
  return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

bool odd(char ch) {
  return isdigit(ch) && (ch - '0') % 2 == 1;
}

int main() {
  char S[64];
  scanf("%s", S);

  int res = 0;
  for (int i = 0; S[i]; ++i) {
    if (vowel(S[i]) || odd(S[i])) {
      ++res;
    }
  }

  printf("%d\n", res);

  return 0;
}