#include <bits/stdc++.h>
#define pb push_back

using namespace std;
const int maxn=1e5+12;
int n,col[maxn],sz[maxn],maxx,cnt[maxn];
long long ans[maxn],can;
bool badboy[maxn];
vector<int>g[maxn];
void dastan(int v=0,int p=-1){
  sz[v]=1;
  for(auto &u:g[v])
    if(u!=p)dastan(u,v),sz[v]+=sz[u];
}
void reval(int x){
  if(maxx<++cnt[x])
    maxx=cnt[x],can=x;
  else if(maxx==cnt[x])
    can+=x;
}
void add(int v,int p=-1){
  reval(col[v]);
  for(auto &u:g[v])
    if(u!=p && !badboy[u])
      add(u,v);
}
void rem(int v,int p=-1){
  cnt[col[v]]--;
  for(auto &u:g[v])
    if(u!=p && !badboy[u])
      rem(u,v);
}
void dfs(int v=0,int p=-1,bool hrh=0){//HRH?! mipasandam!
  int mx=0,big=-1;
  for(auto &u:g[v])
    if(u!=p && sz[u]>mx)
      mx=sz[u],big=u;
  for(auto &u:g[v])
    if(u!=p && u!=big)
      dfs(u,v,1);
  if(big+1)
    dfs(big,v),badboy[big]=1;
  add(v,p);
  if(big+1)
    badboy[big]=0;
  ans[v]=can;
  if(hrh)
    rem(v,p),maxx=can=0;
}
main(){
  scanf("%d",&n);
  for_each(col,col+n,[](int &x){scanf("%d",&x);});
  for(int i=1,v,u;i<n;i++)scanf("%d%d",&v,&u),g[--v].pb(--u),g[u].pb(v);
  dastan(),dfs();
  for_each(ans,ans+n,[](long long &x){printf("%lld ",x);});putchar('\n');
  return 0;
}