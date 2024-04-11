#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=300050;
vector< pair<int,int> > Tree[N];
long long ans;
void DFS(int cur, int prev, long long path)
{
ans=max(ans,path);
int i;
for(i=0;i<Tree[cur].size();i++)
{
int v=Tree[cur][i].first;
int w=Tree[cur][i].second;
if(v!=prev) DFS(v,cur,path+w);
}
}
long long sol;
int main()
{
int n,u,v,w,i;
scanf("%i",&n);
for(i=1;i<n;i++)
{
scanf("%i %i %i",&u,&v,&w);
sol+=2*w;
Tree[u].push_back(make_pair(v,w));
Tree[v].push_back(make_pair(u,w));
}
DFS(1,0,0);
printf("%lld\n",sol-ans);
return 0;
}