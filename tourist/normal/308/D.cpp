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

using namespace std;

int res[33333];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int lg = m+1, rg = n-m;
  long long ans = 0;
  for (int b=lg;b<=rg;b++) {
    int bb = n+1-b;
    if (bb < b) res[b] = res[bb]; else {
      int cur = 0;
      int u = 3*b*bb - 1;
      int lc = lg + bb, rc = rg + bb;
      int la = lg + b, ra = rg + b;
      int st = u / rc - 3;
      if (st > la) {
        cur += (st - la) * (rc-lc+1);
        la = st;
      }
      for (int a=la;a<=ra;a++) {
        int mx = u / a;
        if (mx >= rc) cur += rc-lc+1; else
        if (mx >= lc) cur += mx-lc+1;
        else break;
      }
      res[b] = cur;
    }
    ans += res[b];
  }
  printf("%I64d\n", 3*ans);
  return 0;
}