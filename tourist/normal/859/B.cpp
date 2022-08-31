/**
 *    author:  tourist
 *    created: 16.09.2017 20:35:44       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = (int) 1e9;
  for (int a = 1; a <= n; a++) {
    int b = (n + a - 1) / a;
    ans = min(ans, 2 * (a + b));
  }
  printf("%d\n", ans);
  return 0;
}