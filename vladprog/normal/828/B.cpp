#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d%*c",&n,&m);
    int lx=101,rx=0,ly=101,ry=0,k=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c;
            scanf("%c",&c);
            if(c=='B')
                lx=min(lx,i),rx=max(rx,i),
                ly=min(ly,j),ry=max(ry,j),
                k++;
        }
        scanf("%*c");
    }
    if(lx==101)
        printf("1");
    else
    {
        int x=rx-lx+1;
        int y=ry-ly+1;
        int a=max(x,y);
        if(n<a||m<a)
            printf("-1");
        else
            printf("%d",a*a-k);
    }
}