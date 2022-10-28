#include <bits/stdc++.h>
using namespace std;

const int A = 1e5;

multiset<int> above[2];
multiset<int> below[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 2>> points(n);
  for (auto& [x, y] : points) {
    cin >> x >> y;
    int k = abs(x + y) % 2;
    above[k].insert(y - x);
  }

  sort(points.begin(), points.end(), [](array<int, 2> a, array<int, 2> b){
    return a[0] + a[1] < b[0] + b[1];
  });

  int ptr = 0;
  int64_t ans = 0;

  for (int i = -2 * A; i <= 2 * A; ++i) {
    int k = abs(i) % 2;

    while (ptr < n && points[ptr][0] + points[ptr][1] <= i) {
      int diagonal = points[ptr][1] - points[ptr][0];
      above[k].erase(above[k].find(diagonal));
      below[k].insert(diagonal);
      ++ptr;
    }

    if (!above[k ^ 1].empty() && !below[k ^ 1].empty()) {
      int lo = max(*above[k ^ 1].begin(), *below[k ^ 1].begin());
      int hi = min(*(--above[k ^ 1].end()), *(--below[k ^ 1].end()));
      if (lo <= hi) {
        ans += (hi - lo) / 2;
      }
    }
  }

  cout << ans << "\n";
}