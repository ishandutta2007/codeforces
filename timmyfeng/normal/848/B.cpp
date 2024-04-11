#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

vector<array<int, 3>> start[N];
vector<array<int, 2>> finish[N];
array<int, 2> ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, w, h;
  cin >> n >> w >> h;

  for (int i = 0; i < n; ++i) {
    int g, p, t;
    cin >> g >> p >> t;
    int diagonal = p - t + int(1e5);
    if (g == 1) {
      start[diagonal].push_back({p, 0, i});
      finish[diagonal].push_back({p, h});
    } else {
      start[diagonal].push_back({0, p, i});
      finish[diagonal].push_back({w, p});
    }
  }

  for (int i = 0; i <= int(2e5); ++i) {
    sort(start[i].begin(), start[i].end(), [](array<int, 3> a, array<int, 3> b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }
      return a[0] < b[0];
    });

    sort(finish[i].begin(), finish[i].end(), [](array<int, 2> a, array<int, 2> b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }
      return a[0] < b[0];
    });

    for (int j = 0; j < int(start[i].size()); ++j) {
      ans[start[i][j][2]] = finish[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (auto j : ans[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
}