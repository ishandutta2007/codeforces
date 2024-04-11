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

    cout << 2 << "\n";
    int back = n;
    for (int i = n - 1; i > 0; --i) {
      cout << back << " " << i << "\n";
      back = (back + i + 1) / 2;
    }
  }
}