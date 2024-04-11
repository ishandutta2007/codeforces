#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int j = 0;
    int aj = 0;
    vector<int> segs;
    for (int i = 0; i < 2 * n; ++i) {
      int a;
      cin >> a;
      if (a > aj) {
        segs.push_back(i - j);
        aj = a;
        j = i;
      }
    }
    segs.push_back(2 * n - j);

    int m = segs.size();
    vector<bitset<N>> dp(m);
    dp[0][0] = 1;

    for (int i = 1; i < m; ++i) {
      dp[i] = dp[i - 1] | (dp[i - 1] << segs[i]);
    }

    cout << (dp[m - 1][n] ? "YES" : "NO") << "\n";
  }
}