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

LL inv(LL x){
  LL a=MOD-2;
  LL ans=1;
  while(a){
    if(a&1) ans=ans*x%MOD;
    x=x*x%MOD;
    a>>=1;
  }
  return ans;
}

int main(){
  CFS;
  int n,m;
  cin >> n >> m;
  vector<LL> a(n),w(n);
  LL sum = 0;
  LL x=0,y=0;
  rep(i,n) cin >> a[i]; // 1like 0dis
  rep(i,n){
    cin >> w[i], sum+=w[i];
    if(a[i]) x+=w[i];
    else y+=w[i];
  }
  vector<LL> waru(2*m+1,0);
  rep(i,2*m+1) if(sum+i-m>0) waru[i]=inv(sum+i-m);
  vector<LL> dp(2*m+1,0); // 0:-m m:0 2m:m
  vector<LL> ndp(2*m+1,0);
  dp[m]=1;
  repp(i,0,m){
    rep(j,2*m+1) ndp[j]=0;
    repp(j,1,2*m){
      ndp[j+1]=(ndp[j+1]+(x+(i+j-m)/2)*waru[j]%MOD*dp[j]%MOD)%MOD;
      ndp[j-1]=(ndp[j-1]+(y-(i-j+m)/2)*waru[j]%MOD*dp[j]%MOD)%MOD;
    }
    swap(dp,ndp);
  }
  LL aaa=0,bbb=0;
  rep(i,2*m+1){
    LL k = (m+i-m)/2;
    aaa=(aaa+dp[i]*(x+k)%MOD*inv(x)%MOD)%MOD;
  }
  rep(i,2*m+1){
    LL k = (m-i+m)/2;
    bbb=(bbb+dp[i]*(y-k)%MOD*inv(y)%MOD)%MOD;
  }
  rep(i,n){
    if(a[i]){
      cout << aaa*w[i]%MOD << "\n";
    }else{
      cout << bbb*w[i]%MOD << "\n";
    }
  }
  cout << flush;
  return 0;
}