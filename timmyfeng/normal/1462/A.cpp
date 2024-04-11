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
    for (auto &i : a) {
      cin >> i;
    }

    for (int i = 0; i < n / 2; ++i) {
      cout << a[i] << " " << a[n - 1 - i] << " ";
    }

    if (n % 2 == 1) {
      cout << a[n / 2];
    }
    cout << "\n";
  }
}