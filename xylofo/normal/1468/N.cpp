#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  ll c1, c2, c3;
  cin>>c1>>c2>>c3;
  ll a1, a2, a3, a4, a5;
  cin>>a1>>a2>>a3>>a4>>a5;
  ll k;
  c1 -= a1;
  c2 -= a2;
  c3 -= a3;

  if(c1 < 0 || c2 < 0 || c3 < 0) goto bad;
  k = min(c1, a4);
  c1 -= k;
  a4 -= k;

  k = min(c2, a5);
  c2 -= k;
  a5 -= k;

  c3 -= a4;
  c3 -= a5;

  if(c1 < 0 || c2 < 0 || c3 < 0) goto bad;

  cout << "YES" << endl;
  return;

bad:
  cout << "NO" << endl;
  return;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}