#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 998244353
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
  int n;
  cin >> n;
  int u,v;
  vector<LL> deg(n,0);
  vector<LL> fact(n+1,0);
  fact[0]=1;
  repp(i,1,n+1) fact[i]=i*fact[i-1]%MOD;
  rep(i,n-1){
    cin >> u >> v;
    u--,v--;
    deg[u]++,deg[v]++;
  }
  LL ans=n;
  rep(i,n){
    ans=ans*fact[deg[i]]%MOD;
  }
  cout << ans << endl;
  return 0;
}