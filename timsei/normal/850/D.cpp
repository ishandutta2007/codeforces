#include <bits/stdc++.h>
using namespace std;

const int N = 64;

int n, A[N];

int du[N], rd[N];

bool ans[N][N], dp[N][N][N * N / 2];

vector <int> lsk;

void solve(int n, int m, int E) {
  if(!n || !m) return;
  if(E >= A[n]) {
    if(dp[n][m - 1][E - A[n]]) {
      lsk.push_back(A[n]);
      return (void)solve(n, m - 1, E - A[n]);
    }
    else return(void) solve(n - 1, m, E);
  }
  else return (void)solve(n - 1, m, E);
}

void solve(int m, vector <int> lsk) {
  cout << lsk.size() << endl;
  //cerr << m << endl;for(int i = 0; i < (int) lsk.size(); ++ i) cerr << lsk[i] << " "; cerr << endl;
  for(int i = 0; i < (int) lsk.size(); ++ i) du[i + 1] = lsk[i], rd[i + 1] = m - lsk[i] - 1;
  for(int i = 1; i <= m; ++ i) {
    int no = 0;
    vector < pair <int, int> > now; now.clear();
    for(int j = 1; j <= m; ++ j)  {
      if(du[j] > du[no]) no = j;
      now.push_back(make_pair(rd[j], j));
    }
    if(!du[no]) break;
    sort(now.begin(), now.end());
    reverse(now.begin(), now.end());
    for(int j = 0; j < (int) now.size(); ++ j) {
      if(now[j].second == no || ans[now[j].second][no] || ans[no][now[j].second]) continue;
      if(!du[no]) break;
      -- du[no]; -- rd[now[j].second];
      ans[no][now[j].second] = 1;
    }
    now.clear();
    for(int j = 1; j <= m; ++ j) {
      now.push_back(make_pair(du[j], j));
    }
    sort(now.begin(), now.end());
    reverse(now.begin(), now.end());
    for(int j = 0; j < (int) now.size(); ++ j) {
      if(now[j].second == no || ans[no][now[j].second] || ans[now[j].second][no]) continue;
      if(!rd[no]) break;
      -- rd[no]; -- du[now[j].second];
      ans[now[j].second][no] = 1;
    }
  }
  for(int i = 1; i <= m; ++ i) {
    for(int j = 1; j <= m; ++ j) cout << ans[i][j];
    cout << endl;
  }
}

int main() {
  int Sum = 0;
  cin >> n;
  for(int i = 1; i <= n; ++ i) cin >> A[i], Sum += A[i];
  sort(A + 1, A + n + 1);
  dp[0][0][0] = 1;
  dp[1][0][0] = 1;
  for(int i = 1; i <= n; ++ i) {
    for(int j = 0; j < 61; ++ j) {
      for(int k = j * (j - 1) / 2; k <= j * 30; ++ k) {
	dp[i][j + 1][k + A[i]] |= dp[i][j][k];
	if((k + A[i]) >= (j + 1) * j / 2) {
	  //cerr << i << " " << j + 1 <<" " << k + A[i] << endl;
	  dp[i + 1][j + 1][k + A[i]] |= dp[i][j][k];
	}
      }
    }
  }
  for(int i = 1; i <= 61; ++ i) {
    if(dp[n][i][i * (i - 1) / 2] && dp[n][i - 1][i * (i - 1) / 2 - A[n]]) {
      lsk.clear();
      solve(n, i, i * (i - 1) / 2);
      solve(i, lsk);
      return 0;
    }
  }
  puts("=(");
}