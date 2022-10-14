#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  const int MAX = (int) 1e6 + 5;
  vector<int> cnt(MAX);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x] = 1;
  }
  int ans = 0;
  for (int i = MAX - 1; i >= 1; i--) {
    int g = 0;
    for (int j = i + i; j < MAX; j += i) {
      if (cnt[j] == 1) {
        g = __gcd(g, j);
      }
    }
    if (g == i && cnt[i] == 0) {
      ans += 1;
      cnt[i] = 1;
    }
  }
  cout << ans << '\n';
  return 0;
}