#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    cout << (sum % 9 == 0 && min({a, b, c}) >= sum / 9 ? "YES" : "NO") << "\n";
  }
}