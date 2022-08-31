#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  for (int x = 0; a * x <= c; x++) {
    int y = c - a * x;
    if (y % b != 0) {
      continue;
    }
    puts("Yes");
    return 0;
  }
  puts("No");
  return 0;
}