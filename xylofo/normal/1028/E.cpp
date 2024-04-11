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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi v(n), ans(n);
    rep(i,0,n) cin>>v[i];
    auto at = [&](int i) {
      return v[i%n];
    };
    auto nxt = [&](int i) {
      return v[(i+1)%n];
    };
    int t = -1;
    rep(i,n,2*n) if(at(i) < nxt(i)) t = i;
    if(t == -1) {
      if(at(0) == 0) {
        cout << "YES" << endl;
        rep(i,0,n) cout << "1 ";
        cout << endl;
      }
      else
        cout << "NO" << endl;
      return 0;
    }
    ll lst;
    lst = ans[(t+1)%n] = at(t+1);
    lst = ans[t%n] = 2000000/lst*lst + at(t);
    rep(i,0,n-2) {
      --t;
      lst = ans[t%n] = at(t) + lst;
    }
    cout << "YES" << endl;
    rep(i,0,n) cout << ans[i] << " ";
    cout << endl;
    return 0;
}