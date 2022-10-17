#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
//#define debug(v) cerr << "[ " << #v << " = " << v << " ]" << endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


const ll mod = ll(1e9) + 7;
const ll inv2 = (mod+1)/2;
void solve(){
  int n;
  cin>>n;
  ll ans = 1;
  rep(i,0,n) ans = (2*ans)%mod;
  ans -= 1;

  vi cnt(32);
  ll sm2 = 1;
  rep(i,0,n) {
    ll x;
    cin>>x;
    if(x % 2) continue;
    int p = 0;
    while(x % 2 == 0) x/=2, ++p;
    ++cnt[p];
    sm2 = (2*sm2) % mod;
  }

  rep(i,0,sz(cnt)) if(cnt[i]) {
    rep(_,0,cnt[i]) sm2 = (inv2*sm2)%mod;
    ll odds = 1;
    rep(_,0,cnt[i]-1) odds = (2*odds)%mod;
    ll here = (odds * sm2) % mod;
    debug(i);
    debug(cnt[i]);
    debug(sm2);
    debug(here);
    ans = (ans + mod - here) % mod;
  }

  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  solve();
}