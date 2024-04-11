#include <bits/stdc++.h>
using namespace std;

// must contain at least one cell of color q (or 0 can be replaced with q)
// color segment within another must have greater index

const int N = 200000 + 1;

vector<int> where[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    where[a[i]].push_back(i);
  }

  if (where[q].empty()) {
    if (where[0].empty()) {
      cout << "NO\n";
      exit(0);
    }
    int i = where[0].back();
    where[q].push_back(i);
    where[0].pop_back();
    a[i] = q;
  }

  set<int> visited;
  for (int i = 1; i <= q; ++i) {
    if (where[i].empty()) {
      continue;
    }

    auto it = visited.upper_bound(where[i][0]);
    if (it != visited.end() && *it < where[i].back()) {
      cout << "NO\n";
      exit(0);
    }

    for (auto j : where[i]) {
      visited.insert(j);
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      if (i > 1) {
        a[i] = a[i - 1];
      } else {
        int j = i;
        while (a[j] == 0) {
          ++j;
        }
        a[i] = a[j];
      }
    }
    cout << a[i] << " ";
  }
  cout << "\n";
}