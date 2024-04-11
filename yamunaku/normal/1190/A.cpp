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
  LL n,m,k;
  cin >> n >> m >> k;
  vector<LL> p(m);
  rep(i,m) cin >> p[i],p[i]--;
  LL ans=0;
  LL now=0;
  LL idx=0;
  while(1){
    ans++;
    if(p[idx]-idx>=now) now=(p[idx]-idx)/k*k+k;
    LL pre=idx;
    while(idx<m){
      if(p[idx]-pre>=now) break;
      idx++;
    }
    if(idx>=m) break;
  }
  cout << ans << endl;
  return 0;
}