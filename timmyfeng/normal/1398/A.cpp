#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
      cin >> i;
    }

    if (a[0] + a[1] <= a.back()) {
      cout << 1 << " " << 2 << " " << n << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}