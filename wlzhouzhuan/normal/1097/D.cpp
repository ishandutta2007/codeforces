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
const ll mod=1e9+7;
ll inv[55],dp[55];
ll n,ans=1;
int k;
ll solve(ll x,int n){
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for(int _=1;_<=k;_++){
    ll cur=0;
    for(int i=0;i<=n;i++){
      cur=(cur+1ll*dp[i]*inv[n-i+1])%mod;
      dp[i]=cur;
    }
  }
  x%=mod;
  ll cur=1,res=0;
  for(int i=n;i>=0;i--){
    res=(res+1ll*cur*dp[i])%mod;
    cur=cur*x%mod;
  }
  //printf("x=%lld,n=%d,cur=%lld\n",x,n,cur);
  return res;
}
int main(){
  inv[1]=1;
  for(int i=2;i<55;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
  scanf("%lld%d",&n,&k);
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      int cnt=0;
      while(n%i==0)n/=i,cnt++;
      ans=ans*solve(i,cnt)%mod;
    }
  }
  if(n>1)ans=ans*solve(n,1)%mod;
  printf("%lld\n",ans);
  return 0;
}