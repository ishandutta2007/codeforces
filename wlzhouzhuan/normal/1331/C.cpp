#include <bits/stdc++.h>
using namespace std;
 
const int b[] = {0, 1, 6, 4, 3, 5, 2};
int a[1005], n;
 
int main() {
  scanf("%d", &n);
  int cnt = 6;
  while (n > 0) {
    a[cnt--] = n % 2;
    n >>= 1;
  }  
  int ans = 0;
  for (int i = 1; i <= 6; i++) {
    if (a[i]) ans += 1 << (6 - b[i]);
  }
  printf("%d\n", ans);
  return 0;
}