#include <bits/stdc++.h>

using namespace std;

long long tri(long long x) {
  return x * (x+1) / 2;
}

int main() {
  int nTest;
  scanf("%d", &nTest);

  while (nTest--) {
    int n, m;
    scanf("%d%d", &n, &m);

    int g = min(m+1, (n+1)/2);
    int x = n - m;

    int s1 = x / g;
    int s2 = s1 + 1;
    int n2 = x % g;
    int n1 = g - n2;

    long long ans = tri(n) - (tri(s1) * n1 + tri(s2) * n2);
    printf("%lld\n", ans);
  }

  return 0;
}