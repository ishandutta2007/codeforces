#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int a;
            scanf("%d",&a);
            if(a&&(i==1||i==n||j==1||j==m))
                printf("2"),exit(0);
        }
    printf("4");
}