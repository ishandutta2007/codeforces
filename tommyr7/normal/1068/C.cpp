#include <bits/stdc++.h>
#define Maxn 107
using namespace std;
int n,m;
vector<int> ans[Maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans[x].push_back(i);
        ans[y].push_back(i);
    }
    for (int i=1;i<=n;i++)
    {
        printf("%d\n",(int)ans[i].size()+1);
        printf("%d %d\n",i,m+i);
        for (int j=0;j<(int)ans[i].size();j++)
            printf("%d %d\n",i,ans[i][j]);
    }
    return 0;
}