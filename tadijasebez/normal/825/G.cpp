#include <stdio.h>
#include <vector>
using namespace std;
const int N=1000050;
vector<int> Tree[N];
int dp[N];
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
void DFS(int cur, int prev)
{
dp[cur]=min(cur,dp[prev]);
int i;
for(i=0;i<Tree[cur].size();i++)
{
int v=Tree[cur][i];
if(v!=prev) DFS(v,cur);
}
}
int main()
{
int n,q,i,u,v,sol=N;
dp[0]=N;
scanf("%i%i",&n,&q);
for(i=0;i<n-1;i++)
{
scanf("%i%i",&u,&v);
Tree[u].push_back(v);
Tree[v].push_back(u);
}
int t,x,last=0;
scanf("%i%i",&t,&x);
x=(x+last)%n+1;
DFS(x,0);
sol=x;
q--;
while(q--)
{
scanf("%i%i",&t,&x);
x=(x+last)%n+1;
if(t==1)
{
sol=min(sol,dp[x]);
}
else
{
last=min(sol,dp[x]);
printf("%i\n",last);
}
}
return 0;
}