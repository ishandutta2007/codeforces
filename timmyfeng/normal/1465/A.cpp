#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    int n, m = 0;
    cin >> n >> s;
    while (n > 0 && s.back() == ')') {
      s.pop_back();
      ++m, --n;
    }
    cout << (m > n ? "Yes" : "No") << "\n";
  }
}