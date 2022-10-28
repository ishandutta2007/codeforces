#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> greedy(int n, int m) {
  vector<int> pattern;
  for (int i = m - 1; i > 0; i -= 2) {
    pattern.push_back(i - 1);
  }
  for (int i = m; i > 0; i -= 2) {
    pattern.push_back(i - 1);
  }

  vector<vector<int>> ans(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans[i][j] = i * m + pattern[j];
    }
    if (m % 2 == 0) {
      reverse(pattern.begin(), pattern.end());
    } else {
      rotate(pattern.begin(), pattern.begin() + 1, pattern.end());
    }
  }
  return ans;
}

vector<vector<int>> brute(int n, int m) {
  vector<int> perm(n * m);
  iota(perm.begin(), perm.end(), 0);
  do {
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ans[i][j] = perm[i * m + j];
      }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ok &= (i == 0 || (abs(ans[i][j] - ans[i - 1][j]) != m && abs(ans[i][j] - ans[i - 1][j]) != 1));
        ok &= (j == 0 || (abs(ans[i][j] - ans[i][j - 1]) != m && abs(ans[i][j] - ans[i][j - 1]) != 1));
      }
    }

    if (ok) {
      return ans;
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return {};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  if (m >= 4) {
    cout << "YES\n";
    for (auto& i : greedy(n, m)) {
      for (auto j : i) {
        cout << j + 1 << " ";
      }
      cout << "\n";
    }
  } else if (n >= 4) {
    cout << "YES\n";
    vector<vector<int>> ans = greedy(m, n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << ans[j][i] % n * m + ans[j][i] / n + 1 << " ";
      }
      cout << "\n";
    }
  } else {
    vector<vector<int>> ans = brute(n, m);
    if (ans.empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto& i : ans) {
        for (auto j : i) {
          cout << j + 1 << " ";
        }
        cout << "\n";
      }
    }
  }
}