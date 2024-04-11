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

ll torep(ll x, ll y) {
  ll g = __gcd(x,y);
  x /= g;
  y /= g;
  if(x < 0) x = -x, y = -y;
  return x + (y << 32);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<ll,ll> r;
    unordered_map<ll,ll> rr;
    unordered_map<ll,vector<pii> > atR;
    ll pts = 0;
    rep(i,0,n) {
      int t,x,y;
      cin>>t>>x>>y;
      pii pt(x,y);
      ll R = x*x+y*y;
      ll p = torep(x,y);
      if(t == 1) {
        pts++;
        r[p]++;
        vector<pii> &s = atR[R];
        for(pii qt: s) {
          ll pp = torep(qt.X + x, qt.Y + y);
          rr[pp]++;
        }
        s.eb(pt);
      }
      if(t == 2) {
        pts--;
        r[p]--;
        vector<pii> &s = atR[R];
        vector<pii> ss;
        for(pii qt: s) if(qt != pt) {
          ll pp = torep(qt.X + x, qt.Y + y);
          rr[pp]--;
          ss.eb(qt);
        }
        s = move(ss);
      }
      if(t == 3) {
        ll cur = pts;
        cur -= r[p];
        cur -= 2*rr[p];
        cout << cur << '\n';
      }
    }
    return 0;
}