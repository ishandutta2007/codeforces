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
const int N=5005;
const int mod=998244353;
int f[N],dp[N];
int a[N],n;
int fac[N],ifac[N];
int qpow(int a,int b=mod-2){
  int res=1;
  while(b>0){
    if(b&1)res=1ll*res*a%mod;
    b>>=1,a=1ll*a*a%mod;
  }
  return res;
}
void init(int n){
  fac[0]=ifac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
  ifac[n]=qpow(fac[n]);
  for(int i=n-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
int C(int n,int m){
  if(n<m||m<0)return 0;
  else return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int main(){
  init(5000);
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  sort(a+1,a+n+1);
  f[0]=-1;
  for(int i=1,j=0;i<=n;i++){
    while(a[j+1]*2<=a[i])j++;
    f[i]=j;
    //printf("f[%d]=%d\n",i,f[i]);
  }
  if(f[n]!=n-1){
    puts("0");exit(0);
  }
  
  dp[0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<=f[i];j++){
      dp[i]=(dp[i]+1ll*dp[j]*fac[f[i]-f[j]-1]%mod*C(n-f[j]-2,n-f[i]-1)%mod)%mod;
    }
    //printf("dp[%d]=%d\n",i,dp[i]);
  }
  printf("%d\n",dp[n]);
  return 0;
}