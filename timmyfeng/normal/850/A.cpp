#include <bits/stdc++.h>
using namespace std;

const int N = 1'000;

int point[N][5];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> point[i][j];
    }
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    bool bad = false;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        for (int k = j + 1; k < n; ++k) {
          if (k != i) {
            long long numerator = 0;
            for (int ii = 0; ii < 5; ++ii) {
              numerator += (point[i][ii] - point[j][ii]) * (point[i][ii] - point[k][ii]);
            }
            if (numerator > 0) {
              bad = true;
              goto done;
            }
          }
        }
      }
    }
done:

    if (!bad) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}