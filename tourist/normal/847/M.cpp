/**
 *    author:  tourist
 *    created: 18.09.2017 16:10:42       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  bool ok = true;
  for (int i = 1; i < n - 1; i++) {
    ok &= (2 * a[i] == a[i - 1] + a[i + 1]);
  }
  if (!ok) {
    printf("%d\n", a[n - 1]);
  } else {
    printf("%d\n", 2 * a[n - 1] - a[n - 2]);
  }
  return 0;
}