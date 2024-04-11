#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

vector<list<int>::iterator> where[N];
vector<int> violas[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c, n, m;
  cin >> r >> c >> n >> m;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    violas[x - 1].push_back(y - 1);
  }

  long long ans = 0;
  for (int i = 0; i < r; ++i) {
    list<int> linked;
    for (int j = i; j < r; ++j) {
      for (auto k : violas[j]) {
        linked.push_back(k);
      }
    }
    linked.sort();

    for (auto it = linked.begin(); it != linked.end(); ++it) {
      where[*it].push_back(it);
    }
    linked.push_front(-1);
    linked.push_back(c);

    int sum = 0, segment = 0;
    for (int j = 0, k = 0; j < c; ++j) {
      for ( ; k < c && segment + (int) where[k].size() < m; ++k) {
        segment += where[k].size();
      }
      sum += k - j;
      segment -= where[j].size();
    }

    for (int j = r - 1; j >= i; --j) {
      ans += sum;

      for (auto k : violas[j]) {
        auto it = where[k].back();
        where[k].pop_back();

        if ((int) linked.size() - 2 >= m) {
          auto right = it, left = it;
          for (int l = 0; l < m - 1; ++l) {
            if (*(--left) == -1) {
              ++left, ++right;
            }
          }

          while (true) {
            sum += (*left - *prev(left)) * (*next(right) - *right);
            if (left++ == it || *(++right) == c) {
              break;
            }
          }
        }
        linked.erase(it);
      }
    }
  }

  cout << (long long) (r * (r + 1) / 2) * (c * (c + 1) / 2) - ans << "\n";
}