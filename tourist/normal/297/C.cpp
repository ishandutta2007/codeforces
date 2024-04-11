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

pair <int, int> a[444444];
int x[444444], y[444444];

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0;i<n;i++) {
    scanf("%d", &(a[i].first));
    a[i].second = i;
  }
  sort(a, a+n);
  int need = n - (n+2) / 3;
  int z = 0;
  for (int i=n-need;i<n;i++) {
    if (z % 2 == 0) {
      x[a[i].second] = z/2;
      y[a[i].second] = a[i].first-z/2;
    } else {
      x[a[i].second] = a[i].first-z/2;
      y[a[i].second] = z/2;
    }
    z++;
  }
  for (int i=0;i<n-need;i++) {
    x[a[i].second] = 0;
    y[a[i].second] = a[i].first;
  }
  printf("YES\n");
  for (int i=0;i<n-1;i++) printf("%d ", x[i]);
  printf("%d\n", x[n-1]);
  for (int i=0;i<n-1;i++) printf("%d ", y[i]);
  printf("%d\n", y[n-1]);
  return 0;
}