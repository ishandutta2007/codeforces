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

    multiset<int> a;
    for (int i = 0; i < n; ++i) {
      int b;
      cin >> b;
      a.insert(b);
    }

    int cur = 0;
    for (int i = 0; i < n; ++i) {
      int best = 1;
      for (auto i : a) {
        if (__gcd(i, cur) >= __gcd(best, cur)) {
          best = i;
        }
      }
      a.erase(a.find(best));
      cur = __gcd(best, cur);
      cout << best << " ";
    }
    cout << "\n";
  }
}