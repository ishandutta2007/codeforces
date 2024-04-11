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
const int N=100005;
ll a[N],n,ans=0,d,q;
ll getans(){
  ll x=(ans+d)/2;
  return max(x,ans+d-x);
}
int main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  d=a[1];
  for(int i=1;i<n;i++)a[i]=a[i+1]-a[i],ans+=max(0ll,a[i]);
  printf("%lld\n",getans());
  q=read();
  while(q--){
    int l=read(),r=read(),x=read();
    if(l==1)d+=x;
    if(l>1){
      ans-=max(0ll,a[l-1]);
      a[l-1]+=x;
      ans+=max(0ll,a[l-1]);
    }
    if(r<n){
      ans-=max(0ll,a[r]);
      a[r]-=x;
      ans+=max(0ll,a[r]);
    }
    printf("%lld\n",getans());
  }
  return 0;
}