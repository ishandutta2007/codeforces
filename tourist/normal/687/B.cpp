#include <bits/stdc++.h>

using namespace std;

inline int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

inline int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int l = 1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    int g = gcd(x, k);
    l = lcm(l, g);
  }
  puts(l == k ? "Yes" : "No");
  return 0;
}