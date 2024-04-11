#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);

  long long ans = abs(s - a[n / 2]);
  for (int i = 0; i < n / 2; ++i) {
    ans += max(0, a[i] - s);
  }
  for (int i = n / 2 + 1; i < n; ++i) {
    ans += max(0, s - a[i]);
  }

  cout << ans << "\n";
}