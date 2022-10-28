#include <bits/stdc++.h>
using namespace std;

bool permutation(vector<int> p) {
  int n = p.size();
  vector<int> c(n);
  for (auto i : p) {
    if (i > n) {
      return false;
    }
    ++c[i - 1];
  }
  return count(c.begin(), c.end(), 0) == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    int lo = 2, hi = n + 1;
    while (lo < hi) {
      int k = (lo + hi) / 2;

      vector<int> p;
      deque<array<int, 2>> mono;
      for (int i = 0; i < n; ++i) {
        while (!mono.empty() && mono.back()[0] >= a[i]) {
          mono.pop_back();
        }
        mono.push_back({a[i], i});
        if (i >= k - 1) {
          p.push_back(mono.front()[0]);
          if (mono.front()[1] == i - k + 1) {
            mono.pop_front();
          }
        }
      }

      if (permutation(p)) {
        hi = k;
      } else {
        lo = k + 1;
      }
    }

    cout << permutation(a);
    cout << string(lo - 2, '0');
    cout << string(n - lo + 1, '1') << "\n";
  }
}