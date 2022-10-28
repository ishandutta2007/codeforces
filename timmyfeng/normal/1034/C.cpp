#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int M = 1e9 + 7;

vector<int> adj[N];
long long a[N];
int cnt[N];
int dp[N];

int add(int& a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

long long dfs(int u) {
  for (int c : adj[u]) {
    a[u] += dfs(c);
  }
  return a[u];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  dfs(1);

  for (int i = n; i >= 1; --i) {
    a[i] = a[1] / __gcd(a[1], a[i]);
    if (a[i] <= n) {
      ++cnt[a[i]];
    }
  }

  for (int i = n; i >= 1; --i) {
    for (int j = 2 * i; j <= n; j += i) {
      cnt[j] += cnt[i];
    }
  }

  for (int i = n; i >= 1; --i) {
    if (cnt[i] == i) {
      dp[i] = 1;
      for (int j = i * 2; j <= n; j += i) {
        add(dp[i], dp[j]);
      }
    }
  }

  cout << dp[1] << "\n";
}