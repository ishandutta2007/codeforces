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
const int N=10;
double ans=0.0;
int L[N],R[N],n;
int main(){
  n=read();
  rep(i,0,n-1)L[i]=read(),R[i]=read();
  rep(j,1,10000){
    int all=1<<n;
    rep(st,0,all-1){
      if(__builtin_popcount(st)<2)continue;
      double res=1.0;
      rep(i,0,n-1){
        int l=L[i],r=R[i];
        if(st>>i&1)ckmax(l,j);
        else ckmin(r,j-1);
        if(l>r){
          res=0.0;break;
        }
        res=res*(r-l+1)/(R[i]-L[i]+1);
      }
      ans+=res;
    }
  }
  printf("%.12lf\n",ans);
  return 0;
}