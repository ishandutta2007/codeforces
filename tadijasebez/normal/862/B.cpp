#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> Tree[N];
vector<int> BipGraph[2];
void DFS(int cur, int prev, int lvl)
{
    BipGraph[lvl].push_back(cur);
    int i;
    for(i=0;i<Tree[cur].size();i++)
    {
        int v=Tree[cur][i];
        if(v!=prev)
        {
            DFS(v,cur,lvl^1);
        }
    }
}
int main()
{
    int i,u,v,n;
    scanf("%i",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%i %i",&u,&v);
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    DFS(1,0,1);
    long long sol=0;
    for(i=0;i<BipGraph[0].size();i++)
    {
        int v=BipGraph[0][i];
        sol+=BipGraph[1].size()-Tree[v].size();
    }
    printf("%lld\n",sol);
    return 0;
}