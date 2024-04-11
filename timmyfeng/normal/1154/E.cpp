#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int perm[N], where[N], ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> perm[i];
    where[--perm[i]] = i;
  }

  set<int> indices;
  for (int i = 0; i < n; ++i) {
    indices.insert(i);
  }

  int team = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (indices.count(where[i]) > 0) {
      indices.erase(where[i]);
      ans[where[i]] = team;

      for (int j = 0; j < k; ++j) {
        auto it = indices.upper_bound(where[i]);
        if (it == indices.end()) {
          break;
        }
        ans[*it] = team;
        indices.erase(it);
      }

      for (int j = 0; j < k; ++j) {
        auto it = indices.lower_bound(where[i]);
        if (it == indices.begin()) {
          break;
        }
        ans[*(--it)] = team;
        indices.erase(it);
      }

      team = 3 - team;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i];
  }
  cout << "\n";
}