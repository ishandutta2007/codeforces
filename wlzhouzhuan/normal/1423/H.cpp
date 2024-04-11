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
vector<pii>p[N<<2];
vector<int>qry[N];
int f[N],siz[N],st[N],opt[N],x[N],y[N],lst[N]; 
int n,q,k,top;
int nowt,tmax;

int find(int x){
  return f[x]==x?x:find(f[x]);
}
void merge(int x,int y){
  x=find(x),y=find(y);
  if(x==y)return;
  if(siz[x]>siz[y])swap(x,y);
  st[++top]=x,siz[y]+=siz[x],f[x]=y; 
}

void add(int u,int L,int R,int l,int r,pii x){
  if(l<=L&&R<=r){
    p[u].pb(x);return;
  }
  int mid=L+R>>1;
  if(l<=mid)add(u<<1,L,mid,l,r,x);
  if(mid+1<=r)add(u<<1|1,mid+1,R,l,r,x);
}
void pop(int tmp){
  while(top>tmp){
    siz[f[st[top]]]-=siz[st[top]];
    f[st[top]]=st[top];
    top--;
  }
}
void query(int u,int l,int r){
  int tmp=top;
  for(auto i:p[u])merge(i.first,i.second);
  if(l==r){
    for(auto i:qry[l])printf("%d\n",siz[find(i)]);
    pop(tmp);
    return;
  }
  int mid=l+r>>1;
  query(u<<1,l,mid),query(u<<1|1,mid+1,r);
  pop(tmp);
}
int main(){
  n=read(),q=read(),k=read(),nowt=1;
  rep(i,1,q){
    opt[i]=read();
    if(opt[i]==1)x[i]=read(),y[i]=read();
    if(opt[i]==2)x[i]=read(),qry[i].pb(x[i]);
    if(opt[i]==3)lst[++tmax]=i;
  }
  rep(i,1,q){
    if(opt[i]==1){
      int r=q;
      if(nowt+k-1<=tmax)r=lst[nowt+k-1];
      add(1,1,q,i,r,make_pair(x[i],y[i]));
    }
    if(opt[i]==3)++nowt;
  }
  rep(i,1,n)f[i]=i,siz[i]=1;
  query(1,1,q);
  return 0;
}