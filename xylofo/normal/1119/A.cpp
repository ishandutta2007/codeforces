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
  cin>>n;
  vi c(n);
  rep(i,0,n) cin>>c[i];
  int ans = 0;
  rep(i,0,n) if(c[0] != c[i]) ans = max(ans, i);
  reverse(all(c));
  rep(i,0,n) if(c[0] != c[i]) ans = max(ans, i);
  cout << ans << endl;
  return 0;
}