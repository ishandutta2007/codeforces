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
const int N=255;
int ans[N];
int n,x,y;
int main(){
  int T=read();
  while(T--){
    n=read(),x=read(),y=read(); 
    int dif=y-x,maxx=1e9;
    for(int i=1;i<n;i++){
      if(dif%i==0){
        int d=dif/i;
        int a0=x%d;
        if(!a0)a0=d;
        if((y-a0)/d+1>=n){
          if(y<maxx){
            maxx=y;
            int turns=n,x=0;
            while(turns--){
              x++;
              if(x==1)ans[x]=y;
              else ans[x]=ans[x-1]-d;
            }
          }
        }else{
          int _=a0+d*(n-1);
          if(_<maxx){
            maxx=_;
            int turns=n,x=0;
            while(turns--){
              x++;
              if(x==1)ans[x]=a0;
              else ans[x]=ans[x-1]+d;
            }
          }
        }
      }
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
  }
  return 0;
}