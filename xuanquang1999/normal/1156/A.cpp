#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, a[MAXN];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  int ans = 0;
  for(int i = 1; i < n; ++i) {
    int x = a[i-1], y = a[i];
    if (x > y)
      swap(x, y);

    if (x == 2 && y == 3) {
      puts("Infinite");
      return 0;
    } else if (x == 1 && y == 3) {
      ans += 4;
    } else {
      ans += 3;
    }

    if (i >= 2 && a[i] == 2 && a[i-1] == 1 && a[i-2] == 3) 
      --ans;
  }

  puts("Finite");
  printf("%d\n", ans);

  return 0;
}