#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int L = __lg(N) + 1;

int sparse[L][N];
int prefix[N];
int a[N];

int query(int a, int b) {
  int l = __lg(b - a);
  return min(sparse[l][a], sparse[l][b - (1 << l)]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> where;
    int maximum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] > maximum) {
        maximum = a[i];
        where.clear();
      }
      if (a[i] == maximum) {
        where.push_back(i);
      }
    }

    for (int i = 0; i <= __lg(n); ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        if (i == 0) {
          sparse[i][j] = a[j];
        } else {
          sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      prefix[i] = max(i == 0 ? 0 : prefix[i - 1], a[i]);
    }

    vector<int> ans;
    if (where.size() >= 3) {
      ans = {where[1], 1, n - where[1] - 1};
    }

    int suffix = a[n - 1];
    for (int i = n - 1, j = 0; suffix < maximum; --i) {
      while (prefix[j] <= suffix) {
        ++j;
      }
      if (j > 0 && prefix[j - 1] == suffix) {
        if (query(j, i) == suffix) {
          ans = {j, i - j, n - i};
        } else if (j > 1 && prefix[j - 2] == suffix) {
          if (query(j - 1, i) == suffix) {
            ans = {j - 1, i - j + 1, n - i};
          }
        }
      }
      suffix = max(suffix, a[i - 1]);
    }

    if (ans.empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto i : ans) {
        cout << i << " ";
      }
      cout << "\n";
    }
  }
}