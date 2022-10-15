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
/*
long long n;
map<pll,ll>Map;
ll f(ll n,ll m){
  //printf("f(%lld,%lld)\n",n,m);
  if(n==0)return 1;
  if(m==-1)return 0;
  if(Map[{n,m}])return Map[{n,m}];
  ll ans=0;
  for(int i=0;i<=7;i++){
    if((1ll<<m)*i>n)break;
    ans+=f(n-(1<<m)*i,m-1);
  }
  return Map[{n,m}]=ans;
}
*/
__int128 sqr(__int128 x){
  return x*x;
}
int main(){
  int T=read();
  while(T--){
    ll nn;
    scanf("%lld",&nn);
    __int128 n=nn;
    n=(sqr(n/2+2)/4);
    n%=mod;
    nn=n;
    printf("%lld\n",nn);
  }
  return 0;
}