#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n;
    int sum = 0, max_a = 0, max_b = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      sum += a;
      max_a = max(max_a, sum);
    }
    cin >> m;
    sum = 0;
    for (int i = 0; i < m; ++i) {
      int b;
      cin >> b;
      sum += b;
      max_b = max(max_b, sum);
    }
    cout << max_a + max_b << "\n";
  }
}