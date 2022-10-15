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
ll zs[N],fs[N];
int l1,l2,n;
int main(){
  int T=read();
  while(T--){
    n=read();
    l1=l2=0;
    int zero=0;
    for(int i=1;i<=n;i++){
      ll x=read();
      if(x==0)zero++;
      else if(x>0)zs[++l1]=x;
      else fs[++l2]=-x;
    }
    sort(zs+1,zs+l1+1);
    sort(fs+1,fs+l2+1);
    ll ans=-6e18;
    if(zero)ans=0;
    if(l1>=5)ans=max(ans,1ll*zs[l1]*zs[l1-1]*zs[l1-2]*zs[l1-3]*zs[l1-4]);
    if(l1>=4&&l2>=1)ans=max(ans,1ll*zs[1]*zs[2]*zs[3]*zs[4]*(-fs[1]));
    if(l1>=3&&l2>=2)ans=max(ans,1ll*zs[l1]*zs[l1-1]*zs[l1-2]*fs[l2]*fs[l2-1]);
    if(l1>=2&&l2>=3)ans=max(ans,1ll*zs[1]*zs[2]*(-fs[1])*fs[2]*fs[3]);
    if(l1>=1&&l2>=4)ans=max(ans,1ll*zs[l1]*fs[l2]*fs[l2-1]*fs[l2-2]*fs[l2-3]);
    if(l2>=5)ans=max(ans,1ll*(-fs[1])*fs[2]*fs[3]*fs[4]*fs[5]);
    printf("%lld\n",ans);
  }
  return 0;
}