#include "bits/stdc++.h"
using namespace std;
 
#define rep(i, a, b) for(int i=a; i<=b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define f first
#define s second
#define nl "\n"
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int t, n;
ll a[200001], d[200001];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  cin >> t;
  while(t--){
    cin >> n;
    rep(i,1,n){
      cin >> a[i];
      d[i]=a[i]-a[i-1];
    }

    ll ans=0;
    rep(i,2,n){
      if(d[i]<0)  d[1]+=d[i], ans+=-d[i], d[i]=0;
    }
    rep(i,2,n){
      // cout << "add " << d[i] << nl;
      ans+=d[i];
    }
    // cout << "d1 " << d[1] << nl;
    ans+=abs(d[1]);
    cout << ans << nl;
  }
}