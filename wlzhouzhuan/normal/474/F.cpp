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
int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}
const int N=100005;
int lg[N],f[N][20],g[N][20],h[N][20];
int a[N],n,q;
int rmq(int l,int r){
  int len=lg[r-l+1];
  return gcd(g[l][len],g[r-(1<<len)+1][len]);
}
int main(){
  n=read();
  lg[1]=0;
  for(int i=2;i<N;i++)lg[i]=lg[i>>1]+1;
  for(int i=1;i<=n;i++){
    a[i]=read();
    f[i][0]=a[i];
    g[i][0]=a[i];
    h[i][0]=1;
  }
  for(int j=1;j<20;j++){
    for(int i=1;i+(1<<j)-1<=n;i++){
      int x=f[i][j-1],y=f[i+(1<<j-1)][j-1];
      g[i][j]=gcd(g[i][j-1],g[i+(1<<j-1)][j-1]);
      if(x!=y){
        if(x<y)f[i][j]=x,h[i][j]=h[i][j-1];
        else f[i][j]=y,h[i][j]=h[i+(1<<j-1)][j-1];
      }else{
        f[i][j]=x,h[i][j]=h[i][j-1]+h[i+(1<<j-1)][j-1];
      }
    }
  }
  q=read();
  while(q--){
    int l=read(),r=read();
    int G=rmq(l,r);
    int x=l,minn=1e9,cur=0;
    for(int i=19;i>=0;i--){
      if(x+(1<<i)-1<=r){
        if(f[x][i]<minn)minn=f[x][i],cur=h[x][i];
        else if(f[x][i]==minn)cur+=h[x][i];
        x+=(1<<i);
      }
    }
    //printf("l=%d,r=%d,Gcd=%d,minn=%d,cur=%d\n",l,r,G,minn,cur);
    if(G%minn)printf("%d\n",r-l+1);
    else printf("%d\n",r-l+1-cur);
  }
  return 0;
}
//