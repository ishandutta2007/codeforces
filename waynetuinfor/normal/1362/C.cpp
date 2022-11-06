#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    int64_t res = 0;
    for (int i = 0; i <= 60; ++i) res += n / (1LL << i);
    cout << res << "\n";
  }
}