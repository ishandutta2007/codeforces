#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

long long dp[6][N];

void prework() {
  const int n = 1e4;
  memset(dp, -1, sizeof(dp));
  for(int j = 1; j <= n; ++ j)
    dp[0][j] = 0;
  for(int i = 1; i <= 5; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      if(i == 5 && j != 1) break;
      long long now = j;
      for(int k = 1; k <= j + 1; ++ k)
	now = now + dp[i - 1][min(now, 10000LL)] + 1;
      dp[i][j] = now - 1 - j;
    }
  }
}

int calc(long long x) {
  return min(x + 1, 10000LL);
}

void solve(int Times, long long Left) {
  long long now = Left;
  vector < long long > ask; ask.clear();
  for(int k = 1; k <= calc(Left); ++ k) {
    now = now + dp[Times - 1][calc(now)] + 1;
    ask.push_back(now);
  }
  cout << ask.size() << endl;
  for(int i = 0; i < (int) ask.size(); ++ i) cout << ask[i] <<" ";
  cout << endl;
  fflush(stdout);
  int where = 0;
  cin >> where;
  if(where == -1) exit(0);
  long long nxt = Left;
  if(where) nxt = ask[where - 1];
  solve(Times - 1, nxt);
}

int main() {
  prework();
  solve(5, 0);
}