#include <bits/stdc++.h>
using namespace std;

const int N = 3e5;

int d[N];

void solve() {
  int n, k, l;
  cin >> n >> k >> l;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (d[i] > l) {
      cout << "No\n";
      return;
    }
    if (d[i] + k <= l) {
      t = 0;
      continue;
    }

    if (t < k) {
      t = max(t + 1, d[i] + k - l);
    } else {
      if (d[i] + t - k + 1 <= l) {
        t = (t + 1) % (2 * k);
      } else {
        cout << "No\n";
        return;
      }
    }
  }
  cout << "Yes\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}