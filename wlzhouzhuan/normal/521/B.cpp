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
const int N=100005;
const ll mod=1e9+9;
struct ele{
  int x,y,id;
  friend bool operator < (const ele &a,const ele &b){
    if(a.y!=b.y)return a.y<b.y;
    else return a.x<b.x;
  }
}a[N];
set<int>adj[N],fa[N];
int n;
map<pii,int>pos;
set<int>s;
ll ans=0;
int main(){
  n=read();
  for(int i=0;i<n;i++){
    a[i].x=read(),a[i].y=read(),a[i].id=i;
    pos[{a[i].x,a[i].y}]=i;
  }
  for(int i=0;i<n;i++){
    if(a[i].y==0)continue;
    int id=0;
    if(pos.count({a[i].x-1,a[i].y-1})){
      id=pos[{a[i].x-1,a[i].y-1}];
      adj[i].insert(id),fa[id].insert(i);
    }
    if(pos.count({a[i].x,a[i].y-1})){
      id=pos[{a[i].x,a[i].y-1}];
      adj[i].insert(id),fa[id].insert(i);
    }
    if(pos.count({a[i].x+1,a[i].y-1})){
      id=pos[{a[i].x+1,a[i].y-1}];
      adj[i].insert(id),fa[id].insert(i);
    }
  }
  for(int i=0;i<n;i++){
    if(fa[i].empty())s.insert(i);
    else{
      int ok=1;
      for(auto v:fa[i]){
        if(adj[v].size()==1)ok=0;
      }
      if(ok)s.insert(i);
    }
  }
  //for(auto v:s)printf("%d ",v);puts("");
  for(int turn=1;turn<=n;turn++){
    /*
    if(s.empty()){
      puts("fuck!\n");
      break;
    }
    */
    set<int>::iterator it;
    if(turn&1)it=s.end(),it--;
    else it=s.begin();
    //printf("choose %d\n",*it);
    ans=(ans*n%mod+*it)%mod;
    for(auto v:fa[*it]){
      adj[v].erase(*it); 
      if(adj[v].size()==1)s.erase(*adj[v].begin());
    }
    for(auto v:adj[*it]){
      fa[v].erase(*it);
      if(fa[v].empty()){
        s.insert(v);
      }else{
        int ok=1;
        for(auto f:fa[v]){
          if(adj[f].size()==1)ok=0;
        }
        if(ok)s.insert(v);
      }
    }
    adj[*it].clear();
    s.erase(*it); 
  }
  printf("%lld\n",ans);
  return 0;
}