#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 1;
const int M = 1e9 + 7;

vector<int> adj[N];
int dp[N][N];
int n;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int mod_inv(int a) {
  return mod_pow(a, M - 2);
}

void dfs(int u) {
  for (int i = 1; i <= n; ++i) {
    dp[u][i] = 1;
  }

  for (int c : adj[u]) {
    dfs(c);
    for (int i = 1; i <= n; ++i) {
      dp[u][i] = mul(dp[u][i], dp[c][i]);
    }
  }

  for (int i = 1; i <= n; ++i) {
    dp[u][i] = add(dp[u][i], dp[u][i - 1]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int d;
  cin >> n >> d;
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    adj[p].push_back(i);
  }

  dfs(1);

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    int numerator = dp[1][i];
    int denominator = 1;
    for (int j = 0; j <= n; ++j) {
      if (i != j) {
        numerator = mul(numerator, sub(d, j));
        denominator = mul(denominator, sub(i, j));
      }
    }
    ans = add(ans, mul(numerator, mod_inv(denominator)));
  }

  cout << ans << "\n";
}