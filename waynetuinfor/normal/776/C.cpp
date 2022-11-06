#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, k, a[maxn];
long long ans;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long v = 1LL;
  while (v <= 100000000000000LL) {
    map<long long, int> m;
    long long sum = 0;
    ++m[0];
    for (int i = 0; i < n; ++i) {
      sum += a[i];
      ++m[sum];
      if (m.find(sum - v) != m.end()) ans += m[sum - v];
    }
    v *= k;
    if (v == 1) break;
  }
  cout << ans << '\n';
  return 0;
}