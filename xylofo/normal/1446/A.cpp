#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


void solve(int tc) {
  ll n,w;
  cin>>n>>w;
  vector<pair<ll,int>> v(n);
  rep(i,0,n) {
    cin>>v[i].first;
    v[i].second = i+1;
  }
  sort(all(v));
  reverse(all(v));
  ll low = (w+1)/2;
  vi ans;
  ll cur = 0;
  rep(i,0,n) {
    if(v[i].first+cur <= w) {
      cur += v[i].first;
      ans.push_back(v[i].second);
    }
  }
  if(cur >= low) {
    cout << sz(ans) << endl;
    for(int i : ans) cout << i << " ";
    cout << endl;
  }
  else {
    cout <<"-1" << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}