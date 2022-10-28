#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

set<int> where[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int v = 0;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    where[--a].insert(i);
    if (where[a].size() > where[v].size()) {
      v = a;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i == v) {
      continue;
    }

    map<int, int> events;
    for (auto j : where[i]) {
      events[j] = 1;
      for (int k = 0; k < 2; ++k) {
        auto nxt = where[v].lower_bound(j);
        auto prv = nxt;
        if (prv != where[v].begin()) {
          --prv;
          events[*prv] = -1;
          where[v].erase(prv);
        }
        if (nxt != where[v].end()) {
          events[*nxt] = -1;
          where[v].erase(nxt);
        }
      }
    }

    for (auto it = events.begin(); it != events.end(); ++it) {
      if (events.count(it->first - 1) == 0) {
        events[it->first - 1] = 0;
      }
    }
    if (events.count(n) == 0) {
      events[n] = 0;
    }

    map<int, int> first;
    first[0] = 0;
    int sum = 0;
    int prv = 0;

    for (auto [a, b] : events) {
      sum += b;
      if (first.count(sum) > 0) {
        if (first[sum] != prv) {
          ans = max(ans, a - first[sum]);
        }
      } else {
        first[sum] = a;
      }
      prv = a;

      if (b == -1) {
        where[v].insert(a);
      }
    }
  }

  cout << ans << "\n";
}