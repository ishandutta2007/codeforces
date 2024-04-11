#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3005;
const int mod = 1e9 + 7;

int n, D;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
  int Pow(int x, int y) {
    int res = 1;
    for(; y; y >>= 1, x = x * x % mod) {
      if(y & 1) {
	res = res * x % mod;
      }
    }
    return res;
  }
}

vector <int> G[N];

int dp[N][N];

void dfs(int x) {
  for(int i = 1; i <= n; ++ i) dp[x][i] = 1;
  for(int i = 0; i < (int) G[x].size(); ++ i) {
    int V = G[x][i];
    dfs(V);
    for(int j = 1; j <= n; ++ j) {
      dp[V][j] += dp[V][j - 1];
      dp[V][j] %= mod;
      dp[x][j] = (dp[x][j] * dp[V][j] % mod);
    }
  }
}

int A[N];

int Cha(int x) {
  int res = 0;
  for(int i = 0; i <= n; ++ i) {
    int now = 1;
    for(int j = 0; j <= n; ++ j) if(i != j) now = now * sub(i - j) % mod;
    now = Pow(now, mod - 2);
    for(int j = 0; j <= n; ++ j) if(i != j) now = now * sub(x - j) % mod;
    //cerr << i <<" " << now << endl;
    Add(res, now * A[i] % mod);
  }
  return res;
}

int calc(int x) {
  return Cha(x);
}

main() {
  cin >> n >> D;
  for(int i = 2; i <= n; ++ i) {
    int x;
    cin >> x;
    G[x].push_back(i);
  }
  dfs(1);
  for(int i = 1; i <= n; ++ i) A[i] = dp[1][i] + A[i - 1], A[i] %= mod;
  cout << calc(D) << endl;
}