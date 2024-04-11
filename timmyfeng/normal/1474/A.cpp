#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int prv = -1;
    for (int i = 0; i < n; ++i) {
      cout << (s[i] - '0' + 1 != prv);
      prv = (s[i] - '0' + 1 == prv) ? s[i] - '0' : s[i] - '0' + 1;
    }
    cout << "\n";
  }
}