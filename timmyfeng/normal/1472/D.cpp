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
    sort(a.rbegin(), a.rend());

    long long balance = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == a[i] % 2) {
        balance += (i % 2 == 1) ? -a[i] : a[i];
      }
    }

    if (balance < 0) {
      cout << "Bob\n";
    } else if (balance == 0) {
      cout << "Tie\n";
    } else {
      cout << "Alice\n";
    }
  }
}