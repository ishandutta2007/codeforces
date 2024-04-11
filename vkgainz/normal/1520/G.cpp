#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
const int MX = 3e6+5;
using cd = complex<double>;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, w; cin >> n >> m >> w;
  vector<vector<int>> a(n, vector<int>(m));
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> a[i][j];
  vector<vector<ll>> dp(n, vector<ll>(m));
  vector<vector<ll>> rev(n, vector<ll>(m));
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      dp[i][j] = 1e9, rev[i][j] = 1e9;
    }
  }
  dp[0][0] = 0;
  queue<pair<int, int>> in;
  in.push({0, 0});
  while(!in.empty()) {
    auto curr = in.front();
    in.pop();
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for(int r=0;r<4;r++) {
      int nx = curr.f + dx[r], ny = curr.s + dy[r];
      if(nx<n&&ny<m&&nx>=0&&ny>=0 && a[nx][ny] >= 0) {
        if(dp[curr.f][curr.s] + 1 < dp[nx][ny]) {
          dp[nx][ny] = dp[curr.f][curr.s] + 1;
          in.push({nx, ny});
        }
      }
    }
  }
  rev[n-1][m-1] = 0;
  in.push({n-1, m-1});
  while(!in.empty()) {
    auto curr = in.front();
    in.pop();
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for(int r=0;r<4;r++) {
      int nx = curr.f + dx[r], ny = curr.s + dy[r];
      if(nx<n&&ny<m&&nx>=0&&ny>=0 && a[nx][ny] >= 0) {
        if(rev[curr.f][curr.s] + 1 < rev[nx][ny]) {
          rev[nx][ny] = rev[curr.f][curr.s] + 1;
          in.push({nx, ny});
        }
      }
    }
  }
  ll inHome = 1e18, inSchool = 1e18;
  ll ans = 1e18;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(a[i][j] > 0) {
        if(dp[i][j] != 1e9)
          inHome = min(inHome, dp[i][j]*1LL*w + a[i][j]);
        if(rev[i][j] != 1e9)
          inSchool = min(inSchool, rev[i][j]*1LL*w + a[i][j]);
      }
      if(a[i][j] >= 0 && dp[i][j] < 1e9 && rev[i][j] < 1e9) {
        ans = min(ans, (dp[i][j] + rev[i][j])*1LL*w);
      }
    }
  }
  if(inHome < 1e18 && inSchool < 1e18)
    ans = min(ans, inHome + inSchool);
  if(ans == 1e18) cout << -1 << "\n";
  else cout << ans;
}