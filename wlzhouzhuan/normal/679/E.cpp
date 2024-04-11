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

ll a[N],pw[12];
int n,q;

int get(ll x){
  return lower_bound(pw+1,pw+11,x)-pw;
}
#define ls (u<<1)
#define rs (u<<1|1)
ll pos[N<<2],dis[N<<2];
ll cov[N<<2],lzy[N<<2]; 
void build(int u,int l,int r){
  if(l==r){
    pos[u]=get(a[l]),dis[u]=pw[pos[u]]-a[l];
    return;
  }
  int mid=l+r>>1;
  build(ls,l,mid),build(rs,mid+1,r);
  dis[u]=min(dis[ls],dis[rs]);
}
void pushF(int u,ll x){
  if(cov[u])cov[u]+=x;
  else lzy[u]+=x; 
  dis[u]-=x;
}
void pushG(int u,ll x){
  pos[u]=get(x),dis[u]=pw[pos[u]]-x;
  cov[u]=x,lzy[u]=0; 
}
void pushdown(int u){
  if(cov[u])pushG(ls,cov[u]),pushG(rs,cov[u]),cov[u]=0;
  if(lzy[u])pushF(ls,lzy[u]),pushF(rs,lzy[u]),lzy[u]=0;
}
void cover(int u,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr){
    pushG(u,x);
    return;
  }
  pushdown(u);
  int mid=l+r>>1;
  if(ql<=mid)cover(ls,l,mid,ql,qr,x);
  if(qr>mid)cover(rs,mid+1,r,ql,qr,x);
  dis[u]=min(dis[ls],dis[rs]);
}
void update(int u,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr){
    pushF(u,x);
    return;
  }
  pushdown(u);
  int mid=l+r>>1;
  if(ql<=mid)update(ls,l,mid,ql,qr,x);
  if(qr>mid)update(rs,mid+1,r,ql,qr,x);
  dis[u]=min(dis[ls],dis[rs]);
}
ll maintain(int u,int l,int r){
  if(dis[u]>=0)return dis[u];
  if(l==r){
    ll x=pw[pos[u]]-dis[u];
    pos[u]=get(x),dis[u]=pw[pos[u]]-x;
    return dis[u];
  }
  pushdown(u);
  int mid=l+r>>1;
  maintain(ls,l,mid),maintain(rs,mid+1,r);
  return dis[u]=min(dis[ls],dis[rs]);
}
ll query(int u,int l,int r,int po){
  if(l==r)return pw[pos[u]]-dis[u];
  pushdown(u);
  int mid=l+r>>1;
  if(po<=mid)return query(ls,l,mid,po);
  else return query(rs,mid+1,r,po);
}
int main(){
  pw[0]=1;for(int i=1;i<=10;i++)pw[i]=pw[i-1]*42;
  n=read(),q=read();
  for(int i=1;i<=n;i++)a[i]=read();
  build(1,1,n);
  while(q--){
    int opt=read(),x=read();
    if(opt==1){
      printf("%lld\n",query(1,1,n,x));
    }else if(opt==2){
      int y=read(),qwq=read();
      cover(1,1,n,x,y,qwq);
    }else if(opt==3){
      int y=read(),qwq=read();
      update(1,1,n,x,y,qwq);
      /*
      for(int i=1;i<=n;i++)printf("%lld ",query(1,1,n,i));
      puts("");
      system("pause");
      */
      while(!maintain(1,1,n)){
        /*
        for(int i=1;i<=n;i++)printf("%lld ",query(1,1,n,i));
        puts("");
        system("pause");
        */
        update(1,1,n,x,y,qwq);
      } 
    }
    //for(int i=1;i<=n;i++)printf("%lld ",query(1,1,n,i));
    //puts(""); 
  }
  return 0;
}

/*
2 2
2 2
2 1 2 41
3 1 2 1
*/