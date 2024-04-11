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

int a[444444];

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0;i<n;i++) scanf("%d", a+i);
  sort(a, a+n);
  int ans = 0;
  for (int i=0;i<n-2;i++)
    if (a[i] != 0 && a[i] == a[i+2]) ans = -1;
  if (ans != -1)
    for (int i=0;i<n-1;i++)
      if (a[i] != 0 && a[i] == a[i+1]) ans++;
  printf("%d\n", ans);
  return 0;
}