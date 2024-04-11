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
#define int long long
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
ll p,q;

signed main(){
  int T=read();
  while(T--){
    scanf("%lld%lld",&p,&q);
    if(p%q!=0){
      printf("%lld\n",p);
      continue;
    }
    ll x=0,qq=q;
    for(int i=2;i*i<=qq;i++){
      if(qq%i==0){
        int cnt=0;
        int pp=p;
        while(pp%i==0)cnt++,pp/=i;
        while(qq%i==0)cnt--,qq/=i;
        cnt++;
        int res=p;
        while(cnt>0){
          res/=i;
          cnt--;
        }
        x=max(x,res);
      }
    }
    if(qq>1){
      int cnt=0;
      int pp=p;
      while(pp%qq==0)cnt++,pp/=qq;
      int res=p;
      while(cnt>0){
        res/=qq;
        cnt--;
      }
      x=max(x,res);
    }
    printf("%lld\n",x);
  }
}