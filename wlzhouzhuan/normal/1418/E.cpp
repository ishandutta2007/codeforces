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
const int N=200005;
const int mod=998244353;
int qpow(int a,int b=mod-2){
  int res=1;
  while(b>0){
    if(b&1)res=1ll*res*a%mod;
    a=1ll*a*a%mod;
    b>>=1;
  }
  return res;
}
int a[N],sum[N];
int n,m;
int main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)a[i]=read();
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+a[i])%mod;
  while(m--){
    int A=read(),B=read();
    int x=lower_bound(a+1,a+n+1,B)-a;
    int L=n-x+1;
    if(L>=A){
      printf("%lld\n",(1ll*sum[x-1]*(1+mod-1ll*A*qpow(L+1)%mod)%mod+1ll*(sum[n]-sum[x-1]+mod)%mod*(1+mod-1ll*A*qpow(L)%mod)%mod)%mod);
    }else{
      puts("0");
    }
  }
  return 0;
}