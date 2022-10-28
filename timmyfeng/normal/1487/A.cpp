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

    cout << n - count(a.begin(), a.end(), *min_element(a.begin(), a.end())) << "\n";
  }
}