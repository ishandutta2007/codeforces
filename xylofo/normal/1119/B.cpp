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

int main(){
  cin.sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  ll h;
  cin>>n>>h;
  vi v(n);
  rep(i,0,n) cin>>v[i];

  v.eb(h+1);
  rep(i,0,n+1) {
    sort(v.begin(), v.begin()+i+1);
    ll hs = 0;
    for(int j = i, c = 0; j >= 0; --j, ++c)
      if(c % 2 == 0) hs += v[j];
    if(hs > h) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}