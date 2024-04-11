#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int inf=1e9;

const int N=5050*2;
struct Edge{
int u,v,c,f;
};

vector<Edge> edges;
vector<int> G[N];
int s,t;

void AddEdge(int u,int v,int c){
G[u].pb(edges.size());
edges.pb((Edge){u,v,c,0});
G[v].pb(edges.size());
edges.pb((Edge){v,u,0,0});
}

int was[N],dist[N];
queue<int> q;
bool BFS(){
for(int i=s;i<=t;i++)was[i]=0,dist[i]=-1;
q.push(s);dist[s]=0;
while(q.size()){
int x=q.front();
q.pop();
for(int e:G[x]){
int y=edges[e].v;
int c=edges[e].c-edges[e].f;
if(c&&dist[y]==-1){
dist[y]=dist[x]+1;
q.push(y);
}
}
}
return dist[t]!=-1;
}

int DFS(int u,int flow){
if(flow==0||u==t)return flow;
if(dist[u]>=dist[t])return 0;
int ans=0;
for(;was[u]<G[u].size();was[u]++){
int e=G[u][was[u]];
int v=edges[e].v;
int c=edges[e].c-edges[e].f;
if(c==0||dist[v]!=dist[u]+1)continue;
int cut=DFS(v,min(flow,c));
ans+=cut;
flow-=cut;
edges[e].f+=cut;
edges[e^1].f-=cut;
if(!flow)break;
}
return ans;
}

int n,m;
int Flow(int C){
for(int i=0;i<n;i++){
edges[i<<1].c=C;
}
for(int i=0;i<edges.size();i++){
edges[i].f=0;
}
int flow=0;
while(BFS()){
flow+=DFS(s,inf);
}
return flow;
}

int xr[N];
int a[N],b[N];
int main(){
scanf("%i %i",&n,&m);
s=0;t=n+m+1;
for(int i=1;i<=n;i++){
AddEdge(s,i,0);
}
for(int i=1;i<=m;i++){
int u,v;
scanf("%i %i",&u,&v);
AddEdge(u,n+i,1);
AddEdge(v,n+i,1);
AddEdge(n+i,t,1);
xr[i]=u^v;
}
int top=n,bot=0,mid,ans=n;
while(top>=bot){
mid=top+bot>>1;
if(Flow(mid)==m){
top=mid-1;
ans=mid;
}else bot=mid+1;
}
Flow(ans);
printf("%i\n",ans);
for(int i=0;i<edges.size();i++){
int e=edges[i].v-n;
if(e>=1&&e<=m){
int u=edges[i].u;
if(u>=1&&u<=n&&edges[i].f==1){
a[e]=u;b[e]=xr[e]^u;
}
}
}
for(int i=1;i<=m;i++){
printf("%i %i\n",a[i],b[i]);
}
return 0;
}