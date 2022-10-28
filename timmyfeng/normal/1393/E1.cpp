#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int M = 1e9 + 7;

int add(int& a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

vector<int> order[N];
vector<int> dp[N];
string s[N];

string get(int a, int b) {
  if (b == int(s[a].size())) {
    return s[a];
  } else {
    return s[a].substr(0, b) + s[a].substr(b + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    int m = s[i].size();

    int pre = -1;
    vector<int> left;
    vector<int> right;
    for (int j = 0; j < m; ++j) {
      if (pre == -1) {
        pre = j;
      }
      if (j + 1 == m || s[i][j] != s[i][j + 1]) {
        for (int k = pre; k <= j; ++k) {
          if (j + 1 == m || s[i][j] > s[i][j + 1]) {
            left.push_back(k);
          } else {
            right.push_back(k);
          }
        }
        if (j + 1 == m) {
          left.push_back(m);
        }
        pre = -1;
      }
    }

    order[i] = left;
    while (!right.empty()) {
      order[i].push_back(right.back());
      right.pop_back();
    }
    dp[i].resize(m + 1);
  }

  dp[0].assign(1, 1);
  order[0].assign(1, 0);
  for (int i = 1; i <= n; ++i) {
    int k1 = s[i - 1].size();
    int k2 = s[i].size();

    int ptr = 0;
    for (int j = 0; j <= k2; ++j) {
      while (ptr <= k1 && get(i - 1, order[i - 1][ptr]) <= get(i, order[i][j])) {
        ++ptr;
      }
      if (ptr > 0) {
        add(dp[i][j], dp[i - 1][ptr - 1]);
      }
    }

    for (int j = 1; j <= k2; ++j) {
      add(dp[i][j], dp[i][j - 1]);
    }
  }

  cout << dp[n][s[n].size()] << "\n";
}