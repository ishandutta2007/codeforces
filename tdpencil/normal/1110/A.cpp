/**
 *  Created:   21.10.2020 14:33:37	
 *	
**/
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define pb push_back
#define fi first
#define se second
#define sz(v) (int)(v.size())
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int b, k; cin >> b >> k;
  vi a(k); forn(i, k) cin >> a[i];
  vi bu(k);
  int dg = b%10;
  bu[0] = 1;
  for1(i, k){
  	bu[i] = (bu[i-1]*dg) %10;
  	//cout << bu[i]<<' ';
  }
  ll ans = 0;
  forn(i, k) {
  	a[i]%=10;
  	ans += (a[i]*bu[k-i-1])%10;
  }
  //cout << ans <<'\n';
  cout << (ans%2 ? "odd" : "even");
  return 0;   
}