#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 5;
int c[MAXN], n, st, len, ans, nw;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n;
  ans = 1;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) {
    st = i; nw = c[i]; len = 1;
    while (nw != st && len <= n) nw = c[nw], len++;
    if (len > n) { cout << -1 << '\n'; return 0;}
    if (len % 2 == 0) len /= 2;
    ans *= (len / __gcd(ans, len));
  }
  cout << ans << '\n';
  return 0;
}