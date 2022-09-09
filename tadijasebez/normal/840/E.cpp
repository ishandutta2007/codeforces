#include <stdio.h>
#include <vector>
using namespace std;
const int N=50050;
vector<int> Tree[N];
int a[N];
int parent[N];
int ancestor[N];
int dp[N][256];
int dep[N];
int max(int a, int b) {return a>b?a:b;}
void DFS(int cur, int prev, int depth)
{
int i,j;
parent[cur]=prev;
dep[cur]=depth;
if(depth>=256)
{
for(i=0;i<256;i++) dp[cur][i]=-1;
ancestor[cur]=cur;
for(i=0;i<256;i++)
{
int num=i^a[ancestor[cur]];
int ind=255^(num>>8);
num^=ind<<8;
dp[cur][ind]=max(dp[cur][ind],num);
ancestor[cur]=parent[ancestor[cur]];
}
for(j=0;j<8;j++)
{
int m=1<<j;
for(i=0;i<256;i++)
if(dp[cur][i]==-1 && dp[cur][i^m]>=0)
dp[cur][i]=dp[cur][i^m]^(m<<8);
}
}
for(i=0;i<Tree[cur].size();i++)
{
int v=Tree[cur][i];
if(v!=prev) DFS(v,cur,depth+1);
}
}
int query(int cur, int heigth)
{
int sol=a[cur],i;
for(i=0;i<heigth/256;i++)
{
sol=max(sol,dp[cur][i]);
cur=ancestor[cur];
}
for(i=(heigth/256)*256;i<heigth;i++)
{
sol=max(sol,i^a[cur]);
cur=parent[cur];
}
return sol;
}
int main()
{
int n,q,u,v,i;
scanf("%i%i",&n,&q);
for(i=0;i<n;i++) scanf("%i",&a[i]);
for(i=1;i<n;i++)
{
scanf("%i%i",&u,&v);
u--;
v--;
Tree[u].push_back(v);
Tree[v].push_back(u);
}
DFS(0,0,1);
while(q--)
{
scanf("%i%i",&u,&v);
u--;
v--;
printf("%i\n",query(v,dep[v]-dep[u]+1));
}
return 0;
}