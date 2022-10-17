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
#define CYES cout<<"Yes"<<endl;
#define CNO cout<<"No"<<endl;

typedef long long LL;
typedef long double LD;

int main(){
  int n,m;
  cin >> n >> m;
  vector<LL> a(n),b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  sort(all(a),greater<LL>());
  sort(all(b));
  if(b[0]<a[0]){
    cout << -1 << endl;
    return 0;
  }
  LL ans=0;
  repp(i,1,n){
    ans+=a[i]*m;
  }
  rep(i,m){
    ans+=b[i];
  }
  if(b[0]!=a[0]) ans+=a[0]-a[1];
  cout << ans << endl;
  return 0;
}