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
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  string s,t;
  cin>>n>>k>>s>>t;
  ll ans = 0;
  ld leaves = 1;
  rep(i,0,n) {
    leaves = 2*leaves - (s[i] == 'b') - (t[i] == 'a');
    ans += min<ld>(leaves, k);
  }
  cout << ans << endl;
  return 0;
}