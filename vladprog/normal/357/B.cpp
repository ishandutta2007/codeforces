#include<bits/stdc++.h>

#define in(c) ((x<=c)&&(c<=y))

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int c[n];
    memset(c,255,sizeof(c));
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--;
        y--;
        z--;
        if(c[x]!=-1)
            c[y]=(c[x]+1)%3, c[z]=(c[x]+2)%3;
        else if(c[y]!=-1)
            c[x]=(c[y]+1)%3, c[z]=(c[y]+2)%3;
        else if(c[z]!=-1)
            c[x]=(c[z]+1)%3, c[y]=(c[z]+2)%3;
        else
            c[x]=0, c[y]=1, c[z]=2;
    }
    for(int i=0;i<n;i++)
        printf("%d ",c[i]+1);
}