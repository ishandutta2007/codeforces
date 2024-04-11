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

typedef complex<int> P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    int x,y;
    cin>>n>>s>>x>>y;
    P p0(x,y);
    vector<P> v(n+1,0);
    rep(i,0,n) {
      char c = s[i];
      if(c == 'U') v[i+1] = v[i] + P(0,  1);
      if(c == 'D') v[i+1] = v[i] + P(0, -1);
      if(c == 'L') v[i+1] = v[i] + P(-1, 0);
      if(c == 'R') v[i+1] = v[i] + P( 1, 0);
    }
    int ans = 1e9;
    rep(i,0,n+1) {
      int l = i-1, r = n;
      while(l + 1 != r) {
        int m = (l+r+1)/2;
        int len = m-i;
        P p = p0 - v[i] - v[n] + v[m];
        int k = abs(p.real()) + abs(p.imag());
        if(k%2 == len%2 && k <= len) r = m;
        else l = m;
      }
      int len = r-i;
      P p = p0 - v[i] - v[n] + v[r];
      int k = abs(p.real()) + abs(p.imag());
      if(k%2 == len%2 && k <= len) ans = min(ans, len);
    }
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
    return 0;
}