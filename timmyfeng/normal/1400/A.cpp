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

    cout << string(n, s[n - 1]) << "\n";
  }
}