#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

LL modinv(LL x){
  LL ans=1;
  int n=MOD-2;
  while(n){
    if(n&1) ans=ans*x%MOD;
    n>>=1;
    x=x*x%MOD;
  }
  return ans;
}

int main(){
  LL m;
  cin >> m;
  vector<LL> inv(m+1);
  for(int i=1;i<=m;i++) inv[i]=modinv(i);
  LL ans=0,tmp;
  map<LL,int> mp;
  for(int i=2;i<=m;i++){
    LL tmp=1,count=0;
    LL b=i;
    for(int j=2;j<=sqrt(b);j++){
      if(b%j==0){
        while(b%j==0) b/=j;
        tmp*=j;
        count++;
      }
    }
    if(b>1) tmp*=b,count++;
    mp[tmp]=count%2*2-1;
  }
  for(auto p:mp){
    LL i=p.first;
    LL x=m/i,y=m;
    LL b=i;
    LL q=m-x;
    // cout << x SP y SP q << endl;
    LL tmp=((2*x*y%MOD-x*x%MOD)%MOD+MOD)%MOD*modinv((y-x)*(y-x)%MOD)%MOD*q%MOD*inv[m]%MOD;
    // cout << tmp << endl;
    tmp=(tmp*p.second+MOD)%MOD;
    ans=(ans+tmp)%MOD;
  }
  cout << (ans+inv[m])%MOD << endl;
  return 0;
}