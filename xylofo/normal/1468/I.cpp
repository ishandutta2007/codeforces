#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  ll n; cin >> n;
  pii v1, v2;
  cin >> v1.first >> v1.second >> v2.first >> v2.second;
  ll A = abs(v1.first * v2.second - v2.first * v1.second);
  ll points = A;
  //cerr << A << endl; cerr << points << endl;
  if (points == n) {
    cout << "YES" << endl;
    ll g = abs(__gcd(v1.second, v2.second));
    assert(n % g == 0);
    rep(i,0,n/g) rep(j,0,g) cout << i << " " << j << "\n"; 
  }
  else {
    cout << "NO" << endl;
  }
}