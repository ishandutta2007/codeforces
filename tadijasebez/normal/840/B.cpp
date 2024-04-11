#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N=300050;
vector<pair<int,int> > Graph[N];
int num[N];
bool visited[N];
vector<int> sol;
int DFS(int cur, int prev)
{
visited[cur]=true;
int i;
int ret=0;
for(i=0;i<Graph[cur].size();i++)
{
int v=Graph[cur][i].first;
int e=Graph[cur][i].second;
if(v!=prev && !visited[v])
{
if(DFS(v,cur)) sol.push_back(e),ret^=1;
}
}
if(num[cur]==-1) return 0;
return ret^num[cur];
}
int main()
{
int n,m,u,v,i;
int j=0,k=0;
bool ok=false;
scanf("%i%i",&n,&m);
for(i=0;i<n;i++)
{
scanf("%i",&num[i]);
if(num[i]==-1) ok=true,k=i;
if(num[i]==1) j++;
}
for(i=1;i<=m;i++)
{
scanf("%i%i",&u,&v);
u--;
v--;
Graph[u].push_back(make_pair(v,i));
Graph[v].push_back(make_pair(u,i));
}
if(!ok && j%2==1) printf("-1\n");
else
{
DFS(k,k);
printf("%i\n",sol.size());
for(i=0;i<sol.size();i++)
printf("%i\n",sol[i]);
}
return 0;
}