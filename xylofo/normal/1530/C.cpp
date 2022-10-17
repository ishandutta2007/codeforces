#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef long double ld;

void solve(int tc) {
  int n;
  cin>>n;
  vi a(n), b(n);
  rep(i,0,n) cin>>a[i];
  rep(i,0,n) cin>>b[i];
  sort(all(a));
  sort(all(b));
  reverse(all(a));
  reverse(all(b));

  vi pa(n+1), pb(n+1);
  rep(i,0,n) {
    pa[i+1] = pa[i] + a[i];
    pb[i+1] = pb[i] + b[i];
  }

  rep(k,n,2*n+5) {
    int discard = k/4;
    int keep = k - discard;
    ll A = pa[max(n-discard,0)] + (k-max(n,discard)) * 100LL;
    ll B = pb[min(n,keep)];
    if(A >= B) {
      cout << k-n << endl;
      return;
    }
  }
  assert(false);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}