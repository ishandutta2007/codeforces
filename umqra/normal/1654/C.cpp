#include <bits/stdc++.h>

using namespace std;

bool try_match(uint64_t n, multiset<uint64_t> &x) {
  auto level = vector<uint64_t>();
  level.push_back(n);

  auto next_level = vector<uint64_t>();
  while (level.size() > 0 && level.size() <= (int)x.size()) {
    for (auto v : level) {
      if (x.count(v) > 0) {
        x.erase(x.find(v));
      } else if (v > 1) {
        next_level.push_back(v / 2);
        next_level.push_back(v - v / 2);
      } else {
        return false;
      }
    }
    level.clear();
    swap(level, next_level);
  }
  return level.size() == 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    uint64_t sum = 0;
    auto values = multiset<uint64_t>();
    for (int s = 0; s < n; s++) {
      int x;
      scanf("%d", &x);
      values.insert((uint64_t)x);
      sum += x;
    }
    printf("%s\n", try_match(sum, values) ? "YES" : "NO");
  }
  return 0;
}