#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4000005;
const int mod=1073741824;
int vis[N],mu[N],pr[N],len;
ll f[N],g[2005],ans;
int a,b,c;
void init(int n){
  mu[1]=1;
  for(int i=2;i<=n;i++){
    if(!vis[i])pr[len++]=i,mu[i]=-1;
    for(int j=0;j<len&&pr[j]*i<=n;j++){
      vis[pr[j]*i]=1;
      if(i%pr[j]==0)break;
      mu[pr[j]*i]=-mu[i];
    }
  }
  for(int i=1;i<=2000;i++){
    for(int j=1;j<=i;j++){
      (g[i]+=i/j)%=mod;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      (f[j]+=mu[i]*g[c/i])%=mod;
    }
  }
}
int main(){
  cin>>a>>b>>c;
  init(4000000);
  for(int i=1;i<=a;i++){
    for(int j=1;j<=b;j++){
      if(__gcd(i,j)==1)ans=(ans+1ll*(a/i)*(b/j)%mod*f[i*j])%mod;
    }
  } 
  cout<<ans<<'\n';
  return 0;
}