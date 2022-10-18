#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        switch(i%4)
        {
        case 2:
            for(int i=1;i<m;i++)
                printf(".");
            printf("#\n");
            break;
        case 0:
            printf("#");
            for(int i=1;i<m;i++)
                printf(".");
            printf("\n");
            break;
        default:
            for(int i=1;i<=m;i++)
                printf("#");
            printf("\n");
            break;
        }
}