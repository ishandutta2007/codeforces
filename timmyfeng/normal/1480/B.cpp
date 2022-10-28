#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int ha, n;
    long long hb;
    cin >> ha >> hb >> n;

    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    for (int i = 0; i < n; ++i) {
      int b;
      cin >> b;
      hb -= (long long) a[i] * ((b + ha - 1) / ha);
    }

    cout << (hb + *max_element(a.begin(), a.end()) > 0 ? "YES" : "NO") << "\n";
  }
}