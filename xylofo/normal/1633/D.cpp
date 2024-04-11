#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int Q = 1e3+10;
int dist[Q];

void init(){
  rep(i,0,Q) dist[i] = 1e9;
  dist[1] = 0;
  rep(a,1,Q) {
    rep(x,1,a+1) {
      int r = a+a/x;
      if(r < Q) dist[r] = min(dist[r],dist[a]+1);
    }
  }
}

void solve(int tc) {
  int n, k;
  cin >> n >> k;
  vi b(n), c(n);
  rep(i,0,n) cin>>b[i];
  rep(i,0,n) cin>>c[i];
  k = min(15*n,k);
  vi dp(k+1);
  rep(i,0,n) for(int j = k-dist[b[i]]; j >= 0; --j)
    dp[j+dist[b[i]]] = max(dp[j+dist[b[i]]], dp[j] + c[i]);
  cout << dp[k] << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  init();
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}