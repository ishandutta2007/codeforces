#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int n,m,k,rss[3000];
char spider[3000][3000],rp[4]={'R','L','D','U'};
int rx[4]={0,0,-1,1},ry[4]={-1,1,0,0};
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) scanf("%s",&spider[i][1]);
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=3;k++)
            {
                int xx=i+rx[k]*(i-1),yy=j+ry[k]*(i-1);
                if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&spider[xx][yy]==rp[k]) rss[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++) cout<<rss[i]<<" ";
}