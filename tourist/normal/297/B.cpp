#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

int a[4444444], b[4444444];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i=0;i<n;i++) scanf("%d", a+i);
  for (int i=0;i<m;i++) scanf("%d", b+i);
  sort(a, a+n);
  sort(b, b+m);
  int ok = 0;
  if (n > m) ok = 1; else {
    for (int i=0;i<n;i++)
      if (a[i] > b[m-n+i]) ok = 1;
  }
  if (ok) printf("YES\n");
  else printf("NO\n");
  return 0;
}