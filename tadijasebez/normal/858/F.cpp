#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
vector<int> Graph[N];
int Depth[N];
bool vis[N],ok[N];
struct Data
{
    int a,b,c;
    Data(){}
    Data(int u, int v, int j)
    {
        a=u;
        b=v;
        c=j;
    }
};
vector<Data> sol;
void DFS(int cur, int prev, int depth)
{
    int i;
    vis[cur]=true;
    Depth[cur]=depth;
    vector<int> childs;
    for(i=0;i<Graph[cur].size();i++)
    {
        int v=Graph[cur][i];
        if(!vis[v])
        {
            DFS(v,cur,depth+1);
            if(!ok[v]) childs.push_back(v);
        }
        else if(Depth[v]>Depth[cur]) childs.push_back(v);
    }
    if(childs.size()%2==1 && depth>1) childs.push_back(prev),ok[cur]=1;
    for(i=0;i+1<childs.size();i+=2)
    {
        sol.push_back(Data(childs[i],cur,childs[i+1]));
    }
}
int main()
{
    int n,m,i,u,v;
    scanf("%i %i",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%i %i",&u,&v);
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    for(i=1;i<=n;i++) if(!vis[i]) DFS(i,0,1);
    printf("%i\n",sol.size());
    for(i=0;i<sol.size();i++) printf("%i %i %i\n",sol[i].a,sol[i].b,sol[i].c);
    return 0;
}