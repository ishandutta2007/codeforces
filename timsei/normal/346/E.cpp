#include <bits/stdc++.h>
using namespace std;

#define int long long

int get(int a, int n, int p) {
  if(a * n <= p) return max(a, p - a * n);
  return get(p % a, (n * a + p % a + a) / p - 1, a);
}

int a, n, p, h;

main(void) {
  int t;
  for(cin >> t; t --;) {
    scanf("%lld%lld%lld%lld", &a, &n, &p, &h);
    a %= p;
    if(((a * n <= p) ? a : get(a, n, p)) > h) puts("NO");
    else puts("YES");
  }
}