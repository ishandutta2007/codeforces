#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;

int pre_sum[2][N];
int nxt[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      pre_sum[j][i + 1] = pre_sum[j][i];
    }
    if (s[i] == '0') {
      ++pre_sum[0][i + 1];
    } else if (s[i] == '1') {
      ++pre_sum[1][i + 1];
    }
  }

  iota(nxt, nxt + n, 1);

  vector<int> stk;
  for (int i = 1; i <= n; ++i) {
    int j = 0;
    int ans = 0;

    while (j + i - 1 < n) {
      int cnt = 0;
      for (int k = 0; k < 2; ++k) {
        cnt += (pre_sum[k][j + i] - pre_sum[k][j] > 0);
      }

      if (cnt <= 1) {
        ++ans;
        for (int k : stk) {
          nxt[k] = j;
        }
        stk.clear();
        j = nxt[j + i - 1];
      } else {
        stk.push_back(j);
        j = nxt[j];
      }
    }

    for (int k : stk) {
      nxt[k] = n;
    }
    stk.clear();

    cout << ans << " ";
  }
  cout << "\n";
}