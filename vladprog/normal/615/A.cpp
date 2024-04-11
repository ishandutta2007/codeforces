#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);;
    bool b[m];
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            int y;
            scanf("%d",&y);
            b[y-1]=true;
        }
    }
    for(int i=0;i<m;i++)
        if(!b[i])
            printf("NO"),exit(0);
    printf("YES");
}