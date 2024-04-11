#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s1, s2;
  cin >> n >> s1 >> s2;

  vector<int> x(n);
  for (auto& i : x) {
    cin >> i;
  }

  int lo = abs(s2 - s1);
  int hi = *max_element(x.begin(), x.end());

  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    bool ok = true;
    set<int> pivots = {s1, s2};
    for (auto i : x) {
      while (!pivots.empty() && *pivots.begin() < i - mid) {
        pivots.erase(pivots.begin());
      }
      while (!pivots.empty() && *(--pivots.end()) > i + mid) {
        pivots.erase(--pivots.end());
      }

      if (pivots.empty()) {
        ok = false;
        break;
      }
      pivots.insert(i);
    }

    if (ok) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << "\n";
}