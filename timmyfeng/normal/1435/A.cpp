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
    for (int i = 0; i < n; i += 2) {
      int a, b;
      cin >> a >> b;
      cout << -b << " " << a << " ";
    }
    cout << "\n";
  }
}