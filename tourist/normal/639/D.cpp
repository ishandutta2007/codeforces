#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int t[N], r[N], cost[N], nt[N];

int main() {
  int n, k, B, C;
  scanf("%d %d %d %d", &n, &k, &B, &C);
  B = min(B, 5 * C);
  for (int i = 0; i < n; i++) {
    scanf("%d", t + i);
  }
  sort(t, t + n);
  for (int i = 0; i < n; i++) {
    r[i] = (t[i] % 5 + 5) % 5;
  }
  long long ans = (long long) 9e18;
  for (int rot = 0; rot < 5; rot++) {
    for (int i = 0; i < n; i++) {
      int shift = (rot - r[i] + 5) % 5;
      cost[i] = C * shift;
      nt[i] = t[i] + shift;
    }
    long long add = 0;
    long long total = 0;
    multiset <long long> s;
    for (int i = 0; i < n; i++) {
      if (i > 0 && nt[i] > nt[i - 1]) {
        long long value = ((nt[i] - nt[i - 1]) / 5) * 1LL * B;
        add += value;
        total += value * (long long) s.size();
      }
      s.insert(cost[i] - add);
      total += cost[i];
      while ((int) s.size() > k) {
        long long z = *(--s.end());
        total -= (z + add);
        s.erase(--s.end());
      }
      if (s.size() == k) {
        ans = min(ans, total);
      }
    }
  }
  cout << ans << endl;
  return 0;
}