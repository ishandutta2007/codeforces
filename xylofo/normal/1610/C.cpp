
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


void solve(){
  int n;
  cin>>n;
  vi a(n), b(n);
  rep(i,0,n) cin>>a[i]>>b[i];

  int l = 0, r = n+1;
  while(l + 1 != r) {
    int q = l + (r-l)/2;
    int cnt = 0;
    rep(i,0,n) if(b[i] >= cnt && a[i] >= q-cnt-1) ++cnt;
    if(cnt >= q) l = q;
    else r = q;
  }
  cout << l << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin>>t;
  rep(_,0,t) solve();
}