#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;
    cout << ((n & (n - 1)) == 0 ? "NO" : "YES") << "\n";
  }
}