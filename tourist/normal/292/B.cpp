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

const int N = 555555;

int ss[N], ff[N], deg[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i=1;i<=n;i++) deg[i] = 0;
  for (int i=0;i<m;i++) {
    scanf("%d %d", ss+i, ff+i);
    deg[ss[i]]++;
    deg[ff[i]]++;
  }
  string ans = "unknown topology";
  if (m == n) {
    int ok = 1;
    for (int i=1;i<=n;i++)
      if (deg[i] != 2) ok = 0;
    if (ok) ans = "ring topology";
  }
  if (m == n-1) {
    int ok = 0;
    for (int i=1;i<=n;i++)
      if (deg[i] == n-1) ok = 1;
    if (ok) ans = "star topology"; else {
      int cnt = 0;
      for (int i=1;i<=n;i++)
        if (deg[i] != 2) cnt++;
      if (cnt == 2) ans = "bus topology";
    }
  }
  cout << ans << endl;
  return 0;
}