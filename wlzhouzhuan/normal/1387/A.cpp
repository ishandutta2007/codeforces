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
const double eps=1e-5;
struct Edge{
  int to,nxt,val;
}edge[N<<1];
int head[N],tot;
void add(int u,int v,int w){
  edge[++tot]={v,head[u],w};
  head[u]=tot;
}
vector<int>go;
double ANS[N],ex=0;
bool vis[N];
int k[N],b[N];
int n,m;

void dfs(int u){
  vis[u]=1,go.pb(u);
  for(register int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to,y=edge[i].val;
    if(vis[v]){
      int kk=-k[u],bb=y-b[u];
      if(k[v]==kk){
        if(b[v]!=bb)puts("NO"),exit(0);
      }else{
        double cur=(bb-b[v])/1.0/(k[v]-kk);
        if(ex!=-666&&fabs(cur-ex)>eps){
          puts("NO"),exit(0);
        }
        ex=cur;
      }
    }else{
      k[v]=-k[u],b[v]=y-b[u];
      dfs(v);
    }
  }
}
int main(){
  n=read(),m=read();
  for(int i=1;i<=m;i++){
    int u=read(),v=read(),w=read();
    add(u,v,w),add(v,u,w);
  }
  for(int i=1;i<=n;i++)if(!vis[i]){
    k[i]=1,b[i]=0;
    go.clear(),ex=-666,dfs(i);
    /*
    for(auto v:go){
      printf("i=%d,k=%d,b=%d\n",v,k[v],b[v]);
    }
    printf("ex=%.1lf\n",ex);
    */
    if(ex!=-666){
      for(auto v:go){
        ANS[v]=k[v]*ex+b[v];
      }
    }else{
      vector<int>tmp;
      for(auto v:go){
        if(k[v]==1)tmp.pb(b[v]);
        else tmp.pb(-b[v]);
      }
      sort(tmp.begin(),tmp.end());
      ex=-tmp[tmp.size()/2];
      for(auto v:go){
        ANS[v]=k[v]*ex+b[v];
      }
    }
  }
  puts("YES");
  for(int i=1;i<=n;i++){
    printf("%.1lf ",ANS[i]);
  }
  return 0;
}