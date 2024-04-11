#include<bits/stdc++.h>

#define in(c) ((x<=c)&&(c<=y))

using namespace std;

int main()
{
    int m;
    scanf("%d",&m);
    int s=0;
    int c[m+1];
    c[0]=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&c[i]);
        s+=c[i];
        c[i]+=c[i-1];
    }
    int x,y;
    scanf("%d%d",&x,&y);
    for(int i=1;i<m;i++)
        if(in(c[i])&&in(s-c[i]))
            printf("%d",i+1),exit(0);
    printf("0");
}