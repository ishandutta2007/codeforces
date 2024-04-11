#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> E[N];
int sol,col[N];
void DFS(int u, int p, int c)
{
    if(c!=col[u]) sol++;
    for(int i=0;i<E[u].size();i++)
    {
        int v=E[u][i];
        if(v!=p) DFS(v,u,col[u]);
    }
}
int main()
{
    int n,i,u;
    scanf("%i",&n);
    for(i=2;i<=n;i++) scanf("%i",&u),E[u].push_back(i);
    for(i=1;i<=n;i++) scanf("%i",&col[i]);
    DFS(1,0,0);
    printf("%i\n",sol);
    return 0;
}