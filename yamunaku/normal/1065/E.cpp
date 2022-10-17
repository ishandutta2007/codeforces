#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 998244353
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

LL modpow(LL a,LL n){
  LL res=1;
  while(n>0){
    if(n&1) res=res*a%MOD;
    a=a*a%MOD;
    n>>=1;
  }
  return res;
}

int main(){
  LL n,m,a;
  cin >> n >> m >> a;
  vector<LL> b(m+1);
  b[0]=0;
  for(int i=1;i<=m;i++){
    cin >> b[i];
  }
  LL ans=1;
  for(int i=1;i<=m;i++){
    ans=ans*((modpow(a,2*(b[i]-b[i-1]))+modpow(a,b[i]-b[i-1]))%MOD*modpow(2,MOD-2)%MOD)%MOD;
  }
  ans=ans*modpow(a,n-2*b[m])%MOD;
  cout << ans << endl;
  return 0;
}