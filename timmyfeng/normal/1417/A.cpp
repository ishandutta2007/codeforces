#include <bits/stdc++.h>
using namespace std;

const int N = 1'000;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    int min_a = INT_MAX;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      min_a = min(min_a, a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += (k - a[i]) / min_a;
    }
    ans -= (k - min_a) / min_a;

    cout << ans << "\n";
  }
}