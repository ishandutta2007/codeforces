#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
const int M = N * 3;

int dp[N][M], n, m, x, y, pos[M], tot;

struct NODE {
  int p, l, r;
  void input(void) {
    scanf("%d%d", &p, &l);
    r = l;
  }
  friend bool operator < (NODE a, NODE b) {
    return a.p < b.p;
  }
}T[N];

int L[N], P[N], R[N];

int get(int x) {
  return lower_bound(pos + 1, pos + tot + 1, x) - pos;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++ i) {
    T[i].input();
    pos[++ tot] = T[i].p;
    pos[++ tot] = T[i].p - T[i].l;
    pos[++ tot] = T[i].p + T[i].r;
  }
  sort(pos + 1, pos + tot + 1);
  tot = unique(pos + 1, pos + tot + 1) - pos - 1;
  sort(T + 1, T + n + 1);
  for(int i = 1; i <= n; ++ i) {
    L[i] = get(T[i].p - T[i].l);
    P[i] = get(T[i].p);
    R[i] = get(T[i].p + T[i].r);
    //cerr << i <<" " << L[i] <<" " << P[i] <<" " << R[i] << endl;
  }
  //for(int i = 1; i <= tot; ++ i) cerr << pos[i] <<" ";
  //puts("");
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= tot; ++ j) dp[i][j] = dp[i - 1][j];
    dp[i][P[i]] = max(dp[i - 1][L[i]] + T[i].l, dp[i][P[i]]);
    dp[i][R[i]] = max(dp[i - 1][P[i]] + T[i].r, dp[i][R[i]]);
    for(int j = 1; j < i; ++ j) {
      // [L[i], P[j], P[i], R[j]]
      if(L[i] < P[j] && P[j] < P[i] && P[i] < R[j]) {
	//cerr << i <<" " << j << endl;
	dp[i][R[j]] = max(dp[i][R[j]], dp[j - 1][L[i]] + pos[R[j]] - pos[L[i]]);
      }
    }
    for(int j = tot - 1; j >= 1; -- j) dp[i][j] = max(dp[i][j], dp[i][j + 1] - (pos[j + 1] - pos[j]));
    for(int j = 1; j <= tot; ++ j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
    //cerr << i << endl;
    //for(int j = 1; j <= tot; ++ j) cerr << dp[i][j] <<" ";
    //puts("");
  }
  cout << dp[n][tot] << endl;
}