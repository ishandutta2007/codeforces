#include <bits/stdc++.h>
using namespace std;

const int N = 300 + 1;
const int R = 60'000 + 1;

mt19937 rng((unsigned long long) new char);

int projects[N][R];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r;
  cin >> n >> r;

  vector<array<int, 2>> positive;
  vector<array<int, 2>> negative;

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (b >= 0) {
      positive.push_back({a, b});
    } else {
      negative.push_back({a, b});
    }
  }

  int ans = 0;
  sort(positive.begin(), positive.end());
  for (int i = 0; i < (int) positive.size(); ++i) {
    if (positive[i][0] > r) {
      break;
    }
    r += positive[i][1];
    ++ans;
  }

  int best = 0;
  for (int k = 0; k < 20; ++k) {
    if (k == 0) {
      sort(negative.begin(), negative.end());
    } else if (k == 1) {
      sort(negative.rbegin(), negative.rend());
    } else {
      shuffle(negative.begin(), negative.end(), rng);
    }

    for (int i = 1; i <= (int) negative.size(); ++i) {
      auto [a, b] = negative[i - 1];
      for (int j = 0; j <= r; ++j) {
        projects[i][j] = projects[i - 1][j];
        if (j >= a && j >= -b) {
          projects[i][j] = max(projects[i][j], projects[i - 1][j + b] + 1);
        }
      }
    }
    best = max(best, projects[negative.size()][r]);
  }

  ans += best;
  cout << ans << "\n";
}