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
const int N=200005;
int x[N],tmp,n,k;
int pre[N],suf[N];
int main(){
  int T=read();
  while(T--){
    n=read(),k=read();
    rep(i,1,n)x[i]=read();
    rep(i,1,min(n+5,N-1))pre[i]=suf[i]=0;
    sort(x+1,x+n+1);
    rep(i,1,n)tmp=read();
    int j=1;
    for(int i=1;i<=n;i++){
      while(x[i]-x[j]>k)j++;
      pre[i]=max(pre[i-1],i-j+1);
    }
    j=n;
    for(int i=n;i>=1;i--){
      while(x[j]-x[i]>k)j--;
      suf[i]=max(suf[i+1],j-i+1);
    }
    int maxx=0;
    for(int i=0;i<=n;i++)maxx=max(maxx,pre[i]+suf[i+1]);
    printf("%d\n",maxx);
  }
  return 0;
}