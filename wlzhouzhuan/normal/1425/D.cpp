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
#define x1 xd1
#define x2 xd2
#define y1 yd1
#define y2 yd2
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
const int mod=1000000007;
const int N=2005;
struct fuck{
  int x,y,b;
}a[N];
int sum[N][N];
int n,m,R,t=1000;

int fac[N],ifac[N];
int qpow(int a,int b=mod-2){
  int res=1;
  while(b>0){
    if(b&1)res=1ll*res*a%mod;
    a=1ll*a*a%mod;
    b>>=1;
  }
  return res;
}
void init(int n){
  fac[0]=ifac[0]=1;
  for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
  ifac[n]=qpow(fac[n],mod-2);
  for(int i=n-1;i>=1;i--)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
}
int C(int n,int m){
  if(n<m||n<0)return 0;
  else return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int calc1(int x1,int y1,int x2,int y2){
  return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
} 
int main(){
  init(2000);
  n=read(),m=read(),R=read();
  for(int i=1;i<=n;i++){
    a[i].x=read(),a[i].y=read(),a[i].b=read();
    sum[a[i].x][a[i].y]++;
  }
  for(int i=1;i<=t;i++){
    for(int j=1;j<=t;j++){
      sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
    }
  }
  ll ans=0;
  for(int i=1;i<=n;i++){
    int x1=max(1,a[i].x-R),y1=max(1,a[i].y-R);
    int x2=min(t,a[i].x+R),y2=min(t,a[i].y+R);
    int in_dot=calc1(x1,y1,x2,y2);
    ans=(ans+1ll*(C(n,m)-C(n-in_dot,m)+mod)*a[i].b%mod*a[i].b%mod)%mod;
  }
  //printf("cur ans=%lld\n",ans);
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      int x1=max(1,a[i].x-R),y1=max(1,a[i].y-R);
      int x2=min(t,a[i].x+R),y2=min(t,a[i].y+R);
      int in_dot=calc1(x1,y1,x2,y2);
      int kase=C(n,m);
      kase=(kase-C(n-in_dot,m)+mod)%mod;
      int x3=max(1,a[j].x-R),y3=max(1,a[j].y-R);
      int x4=min(t,a[j].x+R),y4=min(t,a[j].y+R);
      int in_dot2=calc1(x3,y3,x4,y4);
      kase=(kase-C(n-in_dot2,m)+mod)%mod;
      int x5=max(x1,x3),y5=max(y1,y3);
      int x6=min(x2,x4),y6=min(y2,y4);
      int in_dot3=0;
      if(x5<=x6&&y5<=y6){
        in_dot3=calc1(x5,y5,x6,y6);
      } 
      int in=in_dot+in_dot2-in_dot3;
      kase=(kase+C(n-in,m))%mod;
      ans=(ans+1ll*2*a[i].b%mod*a[j].b%mod*kase%mod)%mod;
    }
  }
  printf("%lld\n",(ans%mod+mod)%mod);
  return 0; 
}