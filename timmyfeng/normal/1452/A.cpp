#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int x, y;
    cin >> x >> y;
    cout << max(x, y) * 2 - (x != y) << "\n";
  }
}