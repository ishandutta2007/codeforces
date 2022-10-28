#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

double prob[2][N];
int x[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(11);

  int n, m;
  cin >> n >> m;

  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    sum += x[i];
  }

  if (m == 1) {
    cout << 1.0 << "\n";
    exit(0);
  }

  prob[0][0] = 1.0;
  for (int i = 1; i <= n; ++i) {
    fill(prob[i % 2], prob[i % 2] + N, 0.0);
    double sum = 0.0;
    for (int j = 1; j < N; ++j) {
      sum += prob[1 - i % 2][j - 1];
      if (j >= x[i]) {
        prob[i % 2][j] = (sum - prob[1 - i % 2][j - x[i]]) / (m - 1);
      } else {
        prob[i % 2][j] = sum / (m - 1);
      }
      if (j >= m) {
        sum -= prob[1 - i % 2][j - m];
      }
    }
  }

  double ans = 0.0;
  for (int i = 0; i < sum; ++i) {
    ans += prob[n % 2][i];
  }

  cout << 1.0 + ans * (m - 1) << "\n";
}