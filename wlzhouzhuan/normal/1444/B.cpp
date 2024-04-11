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
const int N=300005;
ll ans,a[N];
int n;
const ll mod=998244353;
ll qpow(ll a,ll b){
  ll res=1;
  while(b>0){
    if(b&1)res=1ll*res*a%mod;
    a=1ll*a*a%mod,b>>=1;
  }
  return res;
}
int main(){
  n=read();
  for(int i=1;i<=2*n;i++)a[i]=read();
  sort(a+1,a+2*n+1);
  for(int i=1;i<=n;i++){
    ans=(ans-a[i]%mod+mod)%mod;
  }
  for(int i=n+1;i<=2*n;i++){
    ans=(ans+a[i]%mod)%mod;
  }
  for(int i=2*n;i>n;i--)ans=1ll*ans*i%mod;
  for(int i=n;i>=1;i--)ans=1ll*ans*qpow(i,mod-2)%mod;
  cout<<(ans%mod+mod)%mod; 
  return 0;
}