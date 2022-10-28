#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, r;
  cin >> l >> r;
  int d = r - l + 1;

  vector<array<int, 3>> roads;

  for (int i = 0; i <= __lg(d); ++i) {
    for (int j = 0; j < i; ++j) {
      roads.push_back({32 - i, 32 - j, 1 << (i - 1)});
    }
  }

  for (int i = 0; i < __lg(d) - 1; i += 2) {
    for (int j = 0; j <= i; ++j) {
      roads.push_back({i / 2 + 4, 32 - j, 1});
    }
  }

  roads.push_back({1, 2, l});
  roads.push_back({1, 3, l});

  for (int i = 0; i <= __lg(d); ++i) {
    if ((d & (1 << i)) == 0) {
      continue;
    }

    int prefix = d - d % (1 << (i + 1));
    if (i >= __lg(d) - 1) {
      for (int j = 0; j <= i; ++j) {
        roads.push_back({1 + (i < __lg(d)), 32 - j, prefix + (i == __lg(d) ? l : 0)});
      }
    } else if (i % 2 == 0) {
      roads.push_back({1, i / 2 + 4, prefix - 1 + l});
    } else {
      roads.push_back({2, i / 2 + 4, prefix - 1});
      roads.push_back({3, i / 2 + 4, prefix - 1 + (1 << (i - 1))});
    }
  }

  cout << "YES\n";
  cout << 32 << " " << roads.size() << "\n";
  for (auto [u, v, w] : roads) {
    cout << u << " " << v << " " << w << "\n";
  }
}