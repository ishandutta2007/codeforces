#include <bits/stdc++.h>
using namespace std;

void set_min(int &a, int b) {
  if (a > b) {
    a = b;
  }
}

void set_max(int &a, int b) {
  if (a < b) {
    a = b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, s;
  cin >> n >> m >> s;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<vector<int>> max_l = {{0}};
  for (int i = 0; i < m; ++i) {
    vector<vector<int>> new_l = max_l;
    new_l.emplace_back();

    for (int j = 0; j <= i; ++j) {
      while ((int) new_l[j + 1].size() < m - i - 1 + (int) max_l[j].size()) {
        new_l[j + 1].push_back(INT_MIN);
      }

      for (int k = 0; k < (int) max_l[j].size(); ++k) {
        if (max_l[j][k] > INT_MIN) {
          set_max(new_l[j + 1][m - i - 1 + k], max_l[j][k] + a[i]);
        }
      }
    }

    for (auto &j : new_l) {
      for (int k = 1; k < (int) j.size(); ++k) {
        set_max(j[k], j[k - 1]);
      }
    }

    swap(max_l, new_l);
  }

  vector<vector<int>> min_r = {{0}};
  for (int i = m; i < n; ++i) {
    vector<vector<int>> new_r = min_r;
    new_r.emplace_back();

    for (int j = 0; j <= i - m; ++j) {
      while ((int) new_r[j + 1].size() < i - m + (int) min_r[j].size()) {
        new_r[j + 1].push_back(INT_MAX);
      }

      for (int k = 0; k < (int) min_r[j].size(); ++k) {
        if (min_r[j][k] < INT_MAX) {
          set_min(new_r[j + 1][i - m + k], min_r[j][k] + a[i]);
        }
      }
    }

    for (auto &j : new_r) {
      for (int k = 1; k < (int) j.size(); ++k) {
        set_min(j[k], j[k - 1]);
      }
    }

    swap(min_r, new_r);
  }


  int sum = accumulate(a.begin(), a.begin() + m, 0);
  int ans = sum;

  for (int i = 0; i <= min(m, n - m); ++i) {
    for (int j = 0; j < (int) max_l[i].size() && j <= s - i; ++j) {
      int k = min(s - i - j, (int) min_r[i].size() - 1);
      if (max_l[i][j] > INT_MIN && min_r[i][k] < INT_MAX) {
        ans = min(ans, sum - max_l[i][j] + min_r[i][k]);
      }
    }
  }

  cout << ans << "\n";
}