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
const int N=100005;
const int mod=1e9+7;
char a[N];
int pre[N];
ll fac[N],ifac[N],pw[N];
int n,m;
ll qpow(ll a,ll b){
  ll res=1;
  while(b>0){
    if(b&1)res=res*a%mod;
    a=a*a%mod;
    b>>=1;
  }
  return res;
}
void init(int n){
  fac[0]=ifac[0]=pw[0]=1;
  for(int i=1;i<=n;i++)pw[i]=pw[i-1]*10%mod;
  for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
  ifac[n]=qpow(fac[n],mod-2);
  for(int i=n-1;i>=1;i--)ifac[i]=ifac[i+1]*(i+1)%mod;
}
ll C(int n,int m){
  if(n<m||n<0)return 0ll;
  else return fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int main(){
  init(1e5);
  scanf("%d%d",&n,&m);
  scanf("%s",a+1);
  for(int i=1;i<=n;i++)a[i]^=48,pre[i]=(pre[i-1]+a[i])%mod;
  ll ans=0;
  for(int i=1;i<=n;i++)ans=(ans+pw[n-i]*a[i]%mod*C(i-1,m))%mod;
  for(int t=0;t<=n-1;t++)ans=(ans+pw[t]*C(n-2-t,m-1)%mod*pre[n-1-t])%mod;
  printf("%lld\n",ans);
  return 0;
}