#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int A = 1e6;

template <class T>
struct fenwick_tree {

  T tree[N];

  void update(int a, T val) {
    ++a;
    for ( ; a < N; a += a & -a) {
      tree[a] += val;
    }
  }

  T query(int a) {
    ++a;
    T res = 0;
    for ( ; a; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

  T query(int a, int b) {
    return query(b) - query(a - 1);
  }

};

fenwick_tree<int> ft;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int cnt_lines = n + m + 4;

  vector<array<int, 3>> horizontal;
  for (int i = 0; i < n; ++i) {
    int y, x1, x2;
    cin >> y >> x1 >> x2;
    horizontal.push_back({y, x1, x2});
  }
  horizontal.push_back({0, 0, A});
  horizontal.push_back({A, 0, A});
  sort(horizontal.begin(), horizontal.end());

  vector<array<int, 3>> vertical;
  for (int i = 0; i < m; ++i) {
    int x, y1, y2;
    cin >> x >> y1 >> y2;
    vertical.push_back({y1, x, 1});
    vertical.push_back({y2 + 1, x, -1});
  }
  vertical.push_back({0, 0, 1});
  vertical.push_back({0, A, 1});
  vertical.push_back({A + 1, 0, -1});
  vertical.push_back({A + 1, A, -1});
  sort(vertical.begin(), vertical.end());

  int ptr = 0;
  int64_t cnt_intersection = 0;
  for (auto [y, x1, x2] : horizontal) {
    while (ptr < int(vertical.size()) && vertical[ptr][0] <= y) {
      ft.update(vertical[ptr][1], vertical[ptr][2]);
      ++ptr;
    }
    cnt_intersection += ft.query(x1, x2);
  }

  cout << cnt_intersection - cnt_lines + 1 << "\n";
}