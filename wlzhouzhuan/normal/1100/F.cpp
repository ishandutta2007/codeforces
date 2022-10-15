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
const int N=500005;
vector<pii>qry[N];
int a[N],n,q;
int ans[N];

int bit[N],pos[N]; 
void ins(int x,int id){
  for(int i=20;i>=0;i--){
    if(x>>i&1){
      if(!bit[i]){
        bit[i]=x,pos[i]=id;
        break;
      }
      if(pos[i]<id)swap(pos[i],id),swap(bit[i],x);
      x^=bit[i];
    }
  }
}
int query(int id){
  int ret=0;
  for(int i=20;i>=0;i--){
    if(pos[i]>=id){
      ret=max(ret,ret^bit[i]);
    }
  }
  return ret;
}
int main(){
  n=read();
  rep(i,1,n)a[i]=read();
  q=read();
  rep(i,1,q){
    int l=read(),r=read();
    qry[r].pb({l,i});
  }
  rep(i,1,n){
    ins(a[i],i);
    for(auto v:qry[i]){
      ans[v.sec]=query(v.fir);
    }
  }
  rep(i,1,q)printf("%d\n",ans[i]);
  return 0;
}