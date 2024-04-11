%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
 
const int N = 105;
long long n, m, k;
long long a[N];
int q;
long long x;
 // 
bool check() {
  for (int i = 1; i < n; i++) {
    x = max(0LL, a[i + 1] - k);
    if (a[i] < x) {
      if (x - a[i] > m) return 0;
      m -= x - a[i];
    }
    else {
      m += a[i] - x;
    }
  }
  return 1;
}
 
int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    puts(check() ? "YES" : "NO");
  } 
}