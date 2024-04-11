#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i][0] >> a[i][1];
      if (a[i][0] > a[i][1]) {
        swap(a[i][0], a[i][1]);
      }
      a[i][2] = i;
    }
    sort(a.begin(), a.end());

    vector<int> ans(n);
    int mini = INT_MAX, index = -2;
    for (int i = 0, j = 0; i < n; i = j) {
      for ( ; j < n && a[j][0] == a[i][0]; ++j) {
        if (mini < a[j][1]) {
          ans[a[j][2]] = index;
        } else {
          ans[a[j][2]] = -2;
        }
      }

      for (int k = i; k < j; ++k) {
        if (a[k][1] < mini) {
          mini = a[k][1], index = a[k][2];
        }
      }
    }

    for (auto i : ans) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}