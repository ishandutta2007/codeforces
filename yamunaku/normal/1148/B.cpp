#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  CFS;
  LL n,m,ta,tb,k;
  cin >> n >> m >> ta >> tb >> k;
  vector<LL> a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  if(k>=n||k>=m){
    cout << -1 << endl;
    return 0;
  }
  LL ans=0;
  rep(i,k+1){
    int idx = lower_bound(all(b),a[i]+ta)-b.begin();
    if(idx+k-i>=m){
      cout << -1 << endl;
      return 0;
    }
    ans=max(ans,b[idx+k-i]+tb);
  }
  cout << ans << endl;
  return 0;
}