/**
 *    author:  tourist
 *    created: 16.09.2017 20:34:23       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    mx = max(mx, a);
  }
  printf("%d\n", max(mx - 25, 0));
  return 0;
}