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
#define int long long
struct node{
  int x,opt,y;
};
vector<node>ans;
int x;
int a,b;
void exgcd(int a,int b,int &x,int &y){
  if(b==0){
    x=1,y=0;
    return;
  }
  exgcd(b,a%b,y,x);
  y-=(a/b)*x;
}
void get(int a,int b){
  int res=0;
  while(b>0){
    if(b&1){
      if(res&&a)ans.pb({res,'+',a});
      res+=a;
    }
    ans.pb({a,'+',a}),a=2*a;
    b>>=1;
  }
}
signed main(){
  cin>>x;
  int y=1;
  while(2*y<=x){
    ans.pb({y*x,'+',y*x});
    y<<=1;
  }
  ans.pb({y*x,'^',x});
  y=(y*x)^x;
  cerr<<x<<' '<<y<<'\n';
  exgcd(x,y,a,b);
  cerr<<a<<' '<<b<<'\n';
  if(a<0){
    int qwq=(-a-1)/y+1;
    a+=qwq*y,b-=qwq*x;
  }
  if(b&1)b-=x,a+=y;
  //cerr<<a<<' '<<b<<'\n';
  b=-b;
  get(x,a),get(y,b);
  ans.pb({x*a,'^',y*b});
  printf("%lld\n",ans.size());
  for(auto v:ans)printf("%lld %c %lld\n",v.x,v.opt,v.y);
  return 0;
}