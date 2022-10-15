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
ll a[N];
ll n,L;
bool check(double x){
  double dist1=0,speed=1,t=x;
  for(int i=1;i<=n+1;i++){
    double need=(a[i]-a[i-1])/speed;
    if(need<=t){
      dist1=a[i],t-=(a[i]-a[i-1])/speed;
      speed++;
    }else{
      dist1+=speed*t;
      break;
    }
  }
  double dist2=L;
  speed=1,t=x;
  for(int i=n;i>=0;i--){
    double need=(a[i+1]-a[i])/speed;
    if(need<=t){
      dist2=a[i],t-=(a[i+1]-a[i])/speed;
      speed++;
    }else{
      dist2-=speed*t;
      break;
    }
  }
  return dist1>=dist2;
}
int main(){
  int T=read();
  while(T--){
    n=read(),L=read();
    rep(i,1,n)a[i]=read();
    a[0]=0,a[n+1]=L;
    double l=0.0,r=L+5;
    for(int i=0;i<=90;i++){
      double mid=(l+r)/2.0;
      if(check(mid))r=mid;
      else l=mid;
    }
    printf("%.12lf\n",l);
  }
  return 0;
}