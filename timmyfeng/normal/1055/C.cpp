#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long la, ra, ta, lb, rb, tb;
  cin >> la >> ra >> ta >> lb >> rb >> tb;

  long long gcd = __gcd(ta, tb);

  if (la > lb) {
    swap(la, lb);
    swap(ra, rb);
  }

  long long ans = 0;
  for (auto j : {(lb - la) / gcd, 1LL}) {
    la += j * gcd;
    ra += j * gcd;
    ans = max(ans, min(ra, rb) - max(la, lb) + 1);
  }

  cout << ans << "\n";
}