#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    cout << (b < 2 * a ? "YES" : "NO") << "\n";
  }
}