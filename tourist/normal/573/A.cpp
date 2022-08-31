#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int res = -1;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    while (a % 2 == 0) a /= 2;
    while (a % 3 == 0) a /= 3;
    if (res == -1) res = a; else
    if (res != a) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}