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

    int prv = INT_MAX;
    bool ans = false;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      ans |= (a >= prv);
      prv = a;
    }

    cout << (ans ? "YES": "NO") << "\n";
  }
}