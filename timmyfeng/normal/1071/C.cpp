#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const int MAG = 8;

bool a[N];

int vecs[N];
int n, m;

int solve(int target) {
  for (int i = 0; i < n; ++i) {
    for (int j = 1; i + j * 2 < n; ++j) {
      for (int k = 0; k < 3; ++k) {
        vecs[m] ^= 1 << (i + j * k);
      }
      ++m;
    }
  }

  int res = -1;
  for (int mask = 0; mask < (1 << m); ++mask) {
    int val = 0;
    for (int i = 0; i < m; ++i) {
      if (mask & (1 << i)) {
        val ^= vecs[i];
      }
    }
    if (val == target) {
      if (res == -1 || __builtin_popcount(mask) < __builtin_popcount(res)) {
        res = mask;
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> ans;
  while (n > 8) {
    int i = --n;
    if (!a[i]) {
      continue;
    }

    int bad_case = 0b111011;
    for (int j = 0; j < 6; ++j) {
      if (a[i - j] != ((bad_case & (1 << j)) > 0)) {
        bad_case = -1;
        break;
      }
    }

    bool all = true;
    for (int j = 0; j < 3; ++j) {
      all &= a[i - j];
    }

    int len = 2;
    if (all) {
      len = 1;
    } else if (bad_case != -1) {
      len = 4;
    }

    while (2 * (len + 1) <= i && !a[i - len]) {
      ++len;
    }

    vector<int> cur;
    for (int j = 0; j < 3; ++j) {
      int ndx = i - j * len;
      cur.push_back(ndx);
      a[ndx] ^= true;
    }
    ans.push_back(cur);
  }

  int target = 0;
  for (int i = 0; i < n; ++i) {
    target ^= a[i] << i;
  }
  int mask = solve(target);

  if (mask == -1) {
    cout << "NO\n";
  } else {
    for (int i = 0; i < m; ++i) {
      if (mask & (1 << i)) {
        vector<int> cur;
        for (int j = 0; j < n; ++j) {
          if (vecs[i] & (1 << j)) {
            cur.push_back(j);
          }
        }
        ans.push_back(cur);
      }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto i : ans) {
      for (auto j : i) {
        cout << j + 1 << " ";
      }
      cout << "\n";
    }
  }
}