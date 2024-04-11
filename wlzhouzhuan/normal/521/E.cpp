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
const int N=200005;
vector<int>adj[N]; 
int dep[N],fa[N],n,m;
int lca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
  while(dep[u]>dep[v])u=fa[u];
  while(u!=v)u=fa[u],v=fa[v];
  return u; 
}
int vis[N],tag[N],tmp[N],len;
void getpath(int u,int v){
  if(u==v)return;
  if(dep[u]>dep[v]){
    while(u!=v){
      tmp[++len]=u;
      u=fa[u];
    }
  }else{
    stack<int>st;
    v=fa[v];
    while(u!=v){
      st.push(v);
      v=fa[v];
    }
    st.push(u);
    while(!st.empty()){
      tmp[++len]=st.top(),st.pop();
    }
  }
}
void print(){
  printf("%d",len);
  for(int i=1;i<=len;i++)printf(" %d",tmp[i]);
  puts(""); 
}
void print(int a,int b,int c,int d){
  //printf("print %d %d %d %d\n",a,b,c,d);
  if(dep[b]<dep[d])swap(a,c),swap(b,d);
  int e=lca(a,c);
  puts("YES");
  len=0,getpath(e,b),tmp[++len]=b;
  print();
  len=0,getpath(e,a),tmp[++len]=a,tmp[++len]=b;
  print();
  len=0,getpath(e,c),tmp[++len]=c,getpath(d,b),tmp[++len]=b;
  print();
  exit(0);
}
int dx[N],dy[N];
void dfs(int u,int FA){
  //printf("now dfs %d %d\n",u,FA);
  //for(int i=1;i<=n;i++)printf("dx[%d]=%d,dy[%d]=%d\n",i,dx[i],i,dy[i]);
  dep[u]=dep[FA]+1,fa[u]=FA;
  vis[u]=tag[u]=1;
  for(auto v:adj[u]){
    if(v==FA)continue;
    if(!vis[v]){
      dfs(v,u);
    }else if(tag[v]){
      //printf("fan %d %d\n",u,v);
      for(int i=u;i!=v;i=fa[i]){
        if(dx[i]&&dy[i])print(dx[i],dy[i],u,v);
        else dx[i]=u,dy[i]=v;
      }
    }
  }
  tag[u]=0;
}
int main(){
  n=read(),m=read();
  for(int i=1;i<=m;i++){
    int u=read(),v=read();
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for(int i=1;i<=n;i++){
    if(!vis[i])dfs(i,0);
  }
  puts("NO");
  return 0;
}