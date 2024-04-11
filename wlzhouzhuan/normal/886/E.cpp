#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=1000005;
const int mod=1e9+7;
int f[N],n,k;
int fac[N],ifac[N];
int qpow(int a,int b=mod-2){
  int res=1;
  while(b>0){
    if(b&1)res=1ll*res*a%mod;
    a=1ll*a*a%mod,b>>=1;
  }
  return res;
}
void init(int n){
  fac[0]=ifac[0]=1;
  rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
  ifac[n]=qpow(fac[n]);
  per(i,n-1,1)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
int main(){
  scanf("%d%d",&n,&k);
  init(n);
  //printf("%d %d\n",fac[2],fac[3]);
  f[0]=1;
  int sum=0;
  for(int i=1;i<=n;i++){
    sum=(sum+1ll*f[i-1]*ifac[i-1])%mod;
    if(i>k)sum=(sum-1ll*f[i-k-1]*ifac[i-k-1]%mod)%mod;
    if(i>k){
      f[i]=1ll*fac[i-1]*sum%mod;
    }else{
      f[i]=1ll*fac[i]%mod;
    }
    //printf("f[%d]=%d,sum=%d\n",i,f[i],sum);
  }
  int ans=(fac[n]-f[n])%mod;
  for(int i=1;i<=n-k;i++){
    ans=(ans-1ll*f[i-1]*fac[n-1]%mod*ifac[i-1]%mod)%mod;
  }
  printf("%d\n",(ans%mod+mod)%mod); 
  //printf("%d\n",((fac[n]-f[n])%mod+mod)%mod);
  return 0;
}