#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& i : a) {
      cin >> i;
    }

    cout << (accumulate(a.begin(), a.end(), 0) == m ? "YES": "NO") << "\n";
  }
}