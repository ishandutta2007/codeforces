#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;

    assert(q == 0);

    long long plus = 0;
    long long minus = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      minus = max(minus, plus + a);
      plus = max(plus, minus - a);
    }

    cout << max(minus, plus) << "\n";
  }
}