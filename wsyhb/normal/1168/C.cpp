#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
int a[max_n];
const int cnt_bits=18+5;
int Last[max_n][cnt_bits],go[max_n][cnt_bits];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    for(int k=0;k<=18;++k)
        Last[n+1][k]=go[n+1][k]=n+1;
    for(int i=n;i>=1;--i)
        for(int k=0;k<=18;++k)
        {
            if(a[i+1]&(1<<k))
                Last[i][k]=i+1;
            else
                Last[i][k]=Last[i+1][k];
        }
    for(int i=n;i>=1;--i)
        for(int k=0;k<=18;++k)
        {
            if(a[i]&(1<<k))
                go[i][k]=i;
            else
            {
                go[i][k]=n+1;
                for(int j=0;j<=18;++j)
                {
                    if(a[i]&(1<<j))
                        go[i][k]=min(go[i][k],go[Last[i][j]][k]);
                }
            }
        }
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int ans=n+1;
        for(int j=0;j<=18;++j)
        {
            if(a[y]&(1<<j))
                ans=min(ans,go[x][j]);
        }
        puts(ans<=y?"Shi":"Fou");
    }
    return 0;
}