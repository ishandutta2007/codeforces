#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> todo;
  vector<array<int, 2>> points;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points.push_back({x, y});
    for (int j = x - k - 1; j <= x; ++j) {
      todo.push_back(j);
    }
  }

  sort(all(todo));
  sort(all(points));
  todo.erase(unique(all(todo)), todo.end());

  int l = 0, r = 0;
  vector<long long> ans(n + 1);
  vector<array<int, 2>> events;

  for (auto x : todo) {
    vector<array<int, 2>> tmp, add, sub;
    for ( ; r < n && points[r][0] < x + k; ++r) {
      add.push_back({points[r][1] - k, 1});
      add.push_back({points[r][1], -1});
    }
    for ( ; l < n && points[l][0] < x; ++l) {
      sub.push_back({points[l][1] - k, 1});
      sub.push_back({points[l][1], -1});
    }

    if (!add.empty() || !sub.empty()) {
      sort(all(add));
      sort(all(sub));
      merge(all(events), all(add), back_inserter(tmp));
      events.clear();
      set_difference(all(tmp), all(sub), back_inserter(events));
    }

    int prv = INT_MIN, count = 0;
    for (auto [cur, t] : events) {
      ans[count] += cur - prv;
      count += t;
      prv = cur;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}