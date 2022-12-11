#include <bits/stdc++.h>
#define Maxn 10007
using namespace std;
int m,n;
bool flag[57][Maxn];
int main()
{
    scanf("%d%d",&m,&n);
    memset(flag,false,sizeof(flag));
    for (int i=1;i<=m;i++)
    {
        int k;
        scanf("%d",&k);
        for (int j=1;j<=k;j++)
        {
            int x;
            scanf("%d",&x);
            flag[i][x]=true;
        }
    }
    for (int i=1;i<=m;i++)
        for (int j=i+1;j<=m;j++)
        {
            bool check=false;
            for (int k=1;k<n;k++)
                if (flag[i][k]&&flag[j][k]) check=true;
            if (!check)
            {
                printf("impossible\n");
                return 0;
            }
        }
    printf("possible\n");
    return 0;
}