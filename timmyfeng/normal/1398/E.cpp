#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  set<pair<int, int>> big, small;

  int k = 0;
  int cnt = 0;
  long long sum = 0;
  long long ext = 0;
  while (n--) {
    int t, d;
    cin >> t >> d;
    pair<int, int> s = {abs(d), t};

    if (d > 0) {
      k += t;
      if (!big.empty() && s > *big.begin()) {
        big.insert(s);
        ext += d;
        cnt += t;
      } else {
        small.insert(s);
      }
    } else {
      k -= t;
      if (big.count(s) == 1) {
        big.erase(s);
        ext += d;
        cnt -= t;
      } else {
        small.erase(s);
      }
    }
    sum += d;

    while (int(big.size()) > k) {
      small.insert(*big.begin());
      ext -= big.begin()->first;
      cnt -= big.begin()->second;
      big.erase(big.begin());
    }

    while (int(big.size()) < k) {
      big.insert(*--small.end());
      ext += big.begin()->first;
      cnt += big.begin()->second;
      small.erase(--small.end());
    }

    if (cnt == k && k != 0) {
      cout << sum + ext - big.begin()->first + (small.empty() ? 0 : (--small.end())->first) << "\n";
    } else {
      cout << sum + ext << "\n";
    }
  }
}