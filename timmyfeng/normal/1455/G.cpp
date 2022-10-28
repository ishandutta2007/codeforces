#include <bits/stdc++.h>
using namespace std;

struct lazy_map {

  map<int, long long> cost;
  multiset<long long> mini;
  long long lazy = 0;

  void apply(long long value) {
    lazy += value;
  }

  void erase(int key) {
    if (cost.count(key) > 0) {
      mini.erase(mini.find(cost[key]));
      cost.erase(key);
    }
  }

  void update(int key, long long value) {
    if (cost.count(key) > 0) {
      mini.erase(mini.find(cost[key]));
    }
    cost[key] = value - lazy;
    mini.insert(value - lazy);
  }

  long long query(int key) {
    return (cost.count(key) == 0) ? LLONG_MAX : cost[key] + lazy;
  }

  long long min() {
    if (mini.empty()) {
      return LLONG_MAX;
    }
    return *mini.begin() + lazy;
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  vector<lazy_map*> blocks;
  blocks.push_back(new lazy_map());
  blocks[0]->update(s, 0);

  for (int i = 0; i < n; ++i) {
    string t;
    cin >> t;
    if (t[0] == 's') {
      int y, v;
      cin >> y >> v;
      if (y == 0) {
        y = s;
      } else if (y == s) {
        y = 0;
      }

      long long mini = blocks.back()->min();
      blocks.back()->apply(v);
      if (y != 0 && mini < LLONG_MAX) {
        blocks.back()->update(y, mini);
      }
    } else if (t[0] == 'i') {
      int y;
      cin >> y;
      if (y == 0) {
        y = s;
      } else if (y == s) {
        y = 0;
      }

      lazy_map *block = new lazy_map();
      if (y != 0 && blocks.back()->query(y) < LLONG_MAX) {
        block->update(y, blocks.back()->query(y));
        blocks.back()->erase(y);
      }
      blocks.push_back(block);
    } else {
      lazy_map *local = blocks.back();
      blocks.pop_back();
      if (local->cost.size() > blocks.back()->cost.size()) {
        swap(local, blocks.back());
      }

      for (auto [key, value] : local->cost) {
        if (value + local->lazy < blocks.back()->query(key)) {
          blocks.back()->update(key, value + local->lazy);
        }
      }
    }
  }

  cout << blocks[0]->min() << "\n";
}