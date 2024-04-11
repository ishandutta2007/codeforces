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

int last[444444], pr[444444], p[444444], pred[444444];
string s[444444], t;
int ans, n, len;

void go(int v, int K) {
  int j = last[v];
  while (j > 0) {
    int k = K, sz = s[j].length();
    for (int q=0;q<sz;q++) {
      while (k > 0 && s[j][q] != t[k]) k = pr[k];
      if (s[j][q] == t[k]) k++;
      if (k == len) ans++;
    }
    go(j, k);
    j = pred[j];
  }
}

int main() {
  cin >> n;
  for (int i=1;i<=n;i++) last[i] = 0;
  for (int i=2;i<=n;i++) {
    cin >> p[i] >> s[i];
    pred[i] = last[p[i]];
    last[p[i]] = i;
  }
  cin >> t;
  len = t.length();
  t = t+" ";
  pr[1] = 0;
  int k = 0;
  for (int i=2;i<=len;i++) {
    while (k > 0 && t[i-1] != t[k]) k = pr[k];
    if (t[i-1] == t[k]) k++;
    pr[i] = k;
  }
  ans = 0;
  go(1, 0);
  printf("%d\n", ans);
  return 0;
}