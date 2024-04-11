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
const int mod=998244353;
template<typename T1,typename T2>void add(T1 &a,T2 b){a+=b;if(a>=mod)a-=mod;}
template<typename T1,typename T2>void sub(T1 &a,T2 b){a-=b;if(a<0)a+=mod;}
const int N=100005;
int a[N],b[N],c[N],p[N],n;
int main(){
  int T=read();
  while(T--){
    n=read();
    rep(i,1,n)a[i]=read();
    rep(i,1,n)b[i]=read();
    rep(i,1,n)c[i]=read();
    rep(i,1,n){
      if(i==1){
        p[i]=a[i];
        continue;
      }
      if(p[i-1]==a[i])p[i]=b[i];
      else if(p[i-1]==b[i])p[i]=a[i];
      else if(p[i-1]==c[i])p[i]=a[i];
      else p[i]=a[i];
      if(i==n){
        int x=a[i];
        if(x!=p[i-1]&&x!=p[1]){
          p[n]=x;
          continue;
        }
        x=b[i];
        if(x!=p[i-1]&&x!=p[1]){
          p[n]=x;
          continue;
        }
        x=c[i];
        if(x!=p[i-1]&&x!=p[1]){
          p[n]=x;
          continue;
        }
      }
    }
    rep(i,1,n){
      printf("%d ",p[i]); 
    }
    puts("");
  }
}