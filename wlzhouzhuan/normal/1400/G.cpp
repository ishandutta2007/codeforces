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
#define int long long
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
//
const int N=600005;
const int mod=998244353;
int L[N],R[N],d[N];
int x[N],y[N];
int sum[42][N];
int n,m;
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
  rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
  ifac[n]=qpow(fac[n]);
  per(i,n-1,1)ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
} 
int C(int n,int m){
  if(n<m||n<0||m<0)return 0;
  else return 1ll*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
signed main(){
  n=read(),m=read();
  init(n);
  rep(i,1,n){
    L[i]=read(),R[i]=read();
    d[L[i]]++,d[R[i]+1]--;
  }
  rep(i,1,n)d[i]+=d[i-1];
  rep(i,0,m-1)x[i]=read(),y[i]=read();
  rep(j,0,40){
    rep(i,1,n){
      sum[j][i]=(sum[j][i-1]+C(d[i]-j,i-j))%mod;
    }
  }
  int all=1<<m,ans=0;
  rep(st,0,all-1){
    set<int>s;
    int l=1,r=n;
    rep(i,0,m-1){
      if(st>>i&1){
        ckmax(l,L[x[i]]),ckmin(r,R[x[i]]),s.insert(x[i]);
        ckmax(l,L[y[i]]),ckmin(r,R[y[i]]),s.insert(y[i]);
      }
    }
    if(l>r)continue;
    int f=(__builtin_popcount(st)&1)?-1:1;
    int res=(sum[s.size()][r]-sum[s.size()][l-1]+mod)%mod;
    ans=(ans+f*res)%mod;
  }
  if(ans<0)ans=(ans%mod+mod)%mod;
  printf("%lld\n",ans);
  return 0;
}