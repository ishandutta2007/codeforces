#include <bits/stdc++.h>
using namespace std;

const int N = 200'000 + 1;

bool ban[N];

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

void euclid(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
  } else {
    int xx, yy;
    euclid(b, a % b, xx, yy);
    x = yy;
    y = xx - yy * (a / b);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  map<int, int> count;
  for (int i = 0; i < m; ++i) {
    ++count[gcd(i, m)];
  }

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ban[a] = true;
    if (a != 0) {
      --count[gcd(a, m)];
      if (count[gcd(a, m)] == 0) {
        count.erase(gcd(a, m));
      }
    }
  }

  map<int, array<int, 2>> dp;
  for (auto [d, c] : count) {
    for (int i = 2; i * d <= m; ++i) {
      if (count.count(i * d) > 0) {
        dp[i * d] = max(dp[i * d], array<int, 2>{dp[d][0] + c, d});
      }
    }
  }

  vector<int> chain;
  int cur = m;
  while (dp[cur][1] != 0) {
    cur = dp[cur][1];
    chain.push_back(cur);
  }

  vector<int> ans;
  int prv = 1;
  while (!chain.empty()) {
    int u = chain.back();
    chain.pop_back();
    for (int i = 0; i < m; ++i) {
      if (!ban[i] && gcd(i, m) == u) {
        int x, y;
        euclid(prv, m, x, y);
        x = (long long) i / gcd(prv, m) * x % m;
        if (x < 0) {
          x += m;
        }
        ans.push_back(x);
        prv = i;
      }
    }
  }

  if (!ban[0]) {
    ans.push_back(0);
  }

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}