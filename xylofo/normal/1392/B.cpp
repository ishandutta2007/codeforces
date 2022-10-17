#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,0,n) cin>>a[i];
  k = k % 2+2;
  rep(_,0,k) {
     ll d = *max_element(all(a));
     rep(i,0,n) a[i] = d-a[i];
  }
  rep(i,0,n) {
    cout << a[i] << " \n"[i==n-1];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}