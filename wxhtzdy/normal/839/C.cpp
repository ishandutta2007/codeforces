#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g(100005);
bool was[100005];
int dist[100005];
double sum=0,cnt=0;
double ans[100005];
void cl() {for(int i=0;i<100005;i++)was[i]=false,dist[i]=100005,ans[i]=0;}
void dfs1(int v){
  was[v]=true;
  for(auto c:g[v]) {
    dist[c]=min(dist[c],dist[v]+1);
    if(was[c]==false)dfs1(c);
  }
}
void DFS(int v,int pr) {
  double s=0;
  bool take=1;
  int sz=0;
  for(auto c:g[v]){
    if(c==pr) continue;
    DFS(c,v);
    s+=ans[c];
    sz++;
    take=0;
  }
  if(take) {sum+=dist[v], cnt++, ans[v]=0;}
  else ans[v]=(double)s/sz+1;
}
int main() {
  int n;
  scanf("%i",&n);
  cl();
  for(int i=0;i<n-1;i++){
    int u,v;
    scanf("%i%i",&u,&v);
    --u,--v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dist[0]=0;
  dfs1(0);
  DFS(0,-1);
  printf("%.12llf\n",ans[0]);
}