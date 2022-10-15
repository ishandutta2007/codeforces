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
#define IT map<ll,ll>::iterator
map<ll,ll>dp;
ll a[N],n;
int main(){
  scanf("%lld",&n);
  rep(i,1,n)scanf("%lld",&a[i]);
  dp[a[1]-1]=0;
  rep(i,2,n){
    IT it=dp.lower_bound(a[i]);
    for(;it!=dp.end();dp.erase(it++)){
      ll x=it->fir,y=it->sec;
      ckmax(dp[x%a[i]],y+1ll*(i-1)*(x-x%a[i]));
      ckmax(dp[a[i]-1],y+1ll*(i-1)*((x+1)/a[i]-1)*a[i]);
    }
  }
  ll ans=0;
  IT it=dp.begin();
  for(;it!=dp.end();it++){
    //printf("%lld %lld\n",it->fir,it->sec);
    ckmax(ans,it->fir*n+it->sec);
  }
  printf("%lld\n",ans);
  return 0;
}