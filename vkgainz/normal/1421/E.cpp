#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;
const int MX = 2e5+5;
void insert(pair<ll, ll> &x, ll y) {
  if(y >= x.f) {
    x = {y, x.f};
  }
  else if(y >= x.s) {
    x = {x.f, y};
  }
}
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  vector<array<pair<ll, ll>, 3>> dp(n);
  dp[0][0] = {-a[0], -1e15};
  dp[0][1] = {a[0], -1e15};
  dp[0][2] = {-1e15, -1e15};
  for(int i=1;i<n;i++) {
    dp[i][0] = {-1e15, -1e15};
    dp[i][1] = {-1e15, -1e15};
    dp[i][2] = {-1e15, -1e15};
    for(int j=0;j<3;j++) {
      insert(dp[i][j], dp[i-1][j].f - a[i]);
      insert(dp[i][j], dp[i-1][j].s - a[i]);
    }
    for(int j=0;j<3;j++) {
      insert(dp[i][j], dp[i-1][(j+2)%3].f + a[i]);
      insert(dp[i][j], dp[i-1][(j+2)%3].s + a[i]);
    }
  }
  int x = ((2-n)%3+3)%3;
  if(n%2==1 && n>1) {
    ll sum = 0LL;
    for(int i=0;i<n;i+=2) sum+=a[i];
    for(int i=1;i<n;i+=2) sum-=a[i];
    if(sum==dp[n-1][x].f) cout << dp[n-1][x].s << "\n";
    else cout << dp[n-1][x].f << "\n";
  }
  else cout << dp[n-1][x].f << "\n";
}