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
int a[N],n,q;
int main(){
  int T=read();
  while(T--){
    n=read(),q=read();
    ll ans=0;
    rep(i,1,n)a[i]=read(),ans+=max(0,a[i]-a[i-1]);
    a[n+1]=0;
    printf("%lld\n",ans);
    while(q--){
      int l=read(),r=read();
      if(l>r)swap(l,r);
      ll res=ans;
      if(l+1==r){
        res-=max(0,a[l]-a[l-1])+max(0,a[r]-a[l])+max(0,a[r+1]-a[r]);
        res+=max(0,a[r]-a[l-1])+max(0,a[l]-a[r])+max(0,a[r+1]-a[l]);
      }else if(l!=r){
        res-=max(0,a[l]-a[l-1])+max(0,a[l+1]-a[l]);
        res-=max(0,a[r]-a[r-1])+max(0,a[r+1]-a[r]);
        res+=max(0,a[r]-a[l-1])+max(0,a[l+1]-a[r]);
        res+=max(0,a[l]-a[r-1])+max(0,a[r+1]-a[l]);
      }
      ans=res;
      swap(a[l],a[r]);
      printf("%lld\n",res); 
    }
  }
  return 0;
}