#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int a[N], b[N], c[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }

    cin >> a[0];
    for (int i = 0; i < n - 1; ++i) {
      cin >> a[i];
    }

    cin >> b[0];
    for (int i = 0; i < n - 1; ++i) {
      cin >> b[i];
    }

    long long mini = LLONG_MAX, ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += c[i] + 1 - abs(a[i] - b[i]);
      ans = max(ans, sum - mini + abs(a[i] - b[i]));
      if (a[i] == b[i]) {
        mini = LLONG_MAX;
      }
      mini = min(mini, sum - abs(a[i] - b[i]));
    }

    cout << ans << "\n";
  }
}