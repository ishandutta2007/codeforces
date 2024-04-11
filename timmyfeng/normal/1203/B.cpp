#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[N * 4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < 4 * n; ++i) {
      cin >> a[i];
    }
    sort(a, a + 4 * n);

    bool ok = true;
    int area = a[0] * a[4 * n - 1];
    for (int i = 0; i < n; ++i) {
      ok &= (a[2 * i] == a[2 * i + 1]);
      ok &= (a[4 * n - 1 - 2 * i] == a[4 * n - 2 - 2 * i]);
      ok &= (a[2 * i] * a[4 * n - 1 - 2 * i] == area);
    }

    cout << (ok ? "YES" : "NO") << "\n";
  }
}