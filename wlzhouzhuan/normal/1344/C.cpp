#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int read(){
  int x=0;
  char ch=getchar();
  while(!isdigit(ch))ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return x;
}
vector<int>adj[N],rev[N];
int pre[N],suf[N],n,m;
int deg[N];
queue<int>q;
int main(){
  n=read(),m=read();
  while(m--){
    int u=read(),v=read();
    adj[u].push_back(v);
    rev[v].push_back(u);
  }
  for(int i=1;i<=n;i++)pre[i]=suf[i]=i;
  memset(deg,0,sizeof(deg));
  while(!q.empty())q.pop();
  for(int i=1;i<=n;i++){
    deg[i]=rev[i].size();
    if(!deg[i])q.push(i); 
  }
  int tag=0;
  while(!q.empty()){
    int u=q.front();q.pop();
    tag++;
    for(auto v:adj[u]){
      pre[v]=min(pre[v],pre[u]);
      if(!--deg[v])q.push(v);
    }
  }
  if(tag!=n){
    puts("-1");exit(0);
  }
  memset(deg,0,sizeof(deg));
  while(!q.empty())q.pop();
  for(int i=1;i<=n;i++){
    deg[i]=adj[i].size();
    if(!deg[i])q.push(i);
  }
  while(!q.empty()){
    int u=q.front();q.pop();
    for(auto v:rev[u]){
      suf[v]=min(suf[v],suf[u]);
      if(!--deg[v])q.push(v);
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++)if(min(pre[i],suf[i])==i)ans++;
  printf("%d\n",ans);
  for(int i=1;i<=n;i++){
    if(min(pre[i],suf[i])==i)putchar('A');
    else putchar('E');
  }
  return 0;
}