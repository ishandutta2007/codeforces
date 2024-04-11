#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

void bad(){
  cout << "cslnb" << endl;
  exit(0);
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin>>n;
  vector<ll> v(n);
  map<ll,ll> cnt;
  ll tot = 0;
  rep(i,0,n) {
    cin>>v[i];
    ++cnt[v[i]];
    tot += v[i];
  }
  trav(q, cnt) if(q.second > 2) {
    bad();
  }
  vi dbl;
  trav(q, cnt) if(q.second == 2) {
    dbl.push_back(q.first);
  }
  if(sz(dbl) > 1) bad();
  if(sz(dbl) == 1) {
    ll x = dbl[0];
    if(x == 0 || cnt[x-1] > 0) bad();
  }

  ll target = ((n-1) * n) / 2;
  ll turns = tot - target;
  if(turns%2 == 0) bad();

  cout << "sjfnb" << endl;
}