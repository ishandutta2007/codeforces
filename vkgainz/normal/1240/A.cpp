#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 1e5+5;

int main() {
  int q; cin >> q;
  while(q--) {
    int n; cin >> n;
    vector<int> p(n); 
    for(auto &p : p) cin >> p, p/=100;
    sort(p.begin(), p.end(), greater<int>());
    int x, a; cin >> x >> a;
    int y, b; cin >> y >> b;
    ll k; cin >> k;
    int lo = 0, hi = n;
    for(int j=0;j<70;j++) {
      int mid = (lo+hi)/2;
      ll contrib = 0LL;
      int r = mid/a;
      int s = mid/b;
      int both = mid/((a*1LL*b)/(__gcd(a, b)));
      for(ll i=0;i<min(n, both);i++) {
        contrib += p[i]*1LL*(x+y);
      }
      r-=both;
      s-=both;
      if(x>y) {
        for(int i=both;i<min(n, both+r);i++) {
          contrib += p[i]*1LL*x;
        }
        for(int i=both+r;i<min(n, both+r+s);i++) {
          contrib += p[i]*1LL*y;
        }
      }
      else {
        for(int i=both;i<min(n, both+s);i++) {
          contrib += p[i]*1LL*y;
        }
        for(int i=both+s;i<min(n, both+r+s);i++) {
          contrib += p[i]*1LL*x;
        }
      }
      if(contrib >= k) {
        hi = mid;
      }
      else {
        lo = mid+1;
      }
    }
    if(lo > n) cout << -1 << "\n";
    else
      cout << lo << "\n";
  }
}