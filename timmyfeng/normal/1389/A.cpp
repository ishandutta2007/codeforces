#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r;
    if (l * 2 <= r) {
      cout << l << " " << l * 2 << "\n";
    } else {
      cout << -1 << " " << -1 << "\n";
    }
  }
}