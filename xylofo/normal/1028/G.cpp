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
typedef vector<ll> vi;
typedef pair<int,int> pii;

ll dp[6][12345];
ll solve(ll q, ll low, vi* guesses) {
  if(low > 10000) {
    ll k = solve(q, 10000, guesses);
    if(guesses) rep(i,0,guesses->size()) (*guesses)[i] += low-10000;
    return k;
  }
  if(q == 0) return 0;
  if(!guesses && dp[q][low] != -1) return dp[q][low];
  ll x = low;
  rep(i,0,low+1) {
    x += solve(q-1,x,nullptr);
    if(i != low && guesses) (*guesses).eb(x);
    ++x;
  }
  return dp[q][low] = x - low - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    rep(i,0,6) rep(j,0,12345) dp[i][j] = -1;
    ll low = 1;
    for(int q = 5;;--q) {
      vi guesses;
      solve(q, low, &guesses);
      cout << guesses.size();
      for(ll a : guesses) cout << " " << a;
      cout << endl;
      int t;
      cin>>t;
      if(t < 0) return 0;
      low = t ? guesses[t-1]+1 : low;
    }
    return 0;
}