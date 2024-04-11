#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    sort(a.begin(), a.end());

    if (a.back() <= d) {
      cout << "YES\n";
    } else if (a[0] + a[1] <= d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}