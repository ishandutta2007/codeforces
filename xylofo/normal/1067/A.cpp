#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 998244353;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vi v(n);
  rep(i,0,n) cin>>v[i];
  vector<vector<ll>> need(2,vector<ll>(201,0));
  vector<vector<ll>> ok(2,vector<ll>(201,0));
  if(v[0] == -1) {
    rep(a,1,201) need[1][a] = 1;
  }
  else {
    need[1][v[0]] = 1;
  }
  rep(i,1,n) {
    int old = (i&1), nw = old^1;
    // need[a] = sum_{i=1..a-1} ok[a] + need[a]
    // ok[a] = need[a] + sum_{i=a..200} ok[a]
    ll sm = 0;
    rep(a,1,201) {
      need[nw][a] = sm;
      sm = (sm + ok[old][a] + need[old][a]) % md;
    }
    sm = 0;
    for(int a = 200; a>=1; --a) {
      sm = (sm + ok[old][a]) % md;
      ok[nw][a] = (sm + need[old][a]) % md;
    }
    if(v[i] != -1) {
      rep(a,1,201) if(a != v[i])
        ok[nw][a] = need[nw][a] = 0;
    }
  }
  ll sm = 0;
  rep(a,1,201) sm = (sm + ok[n&1][a]) % md;
  cout << sm << endl;
  return 0;
}