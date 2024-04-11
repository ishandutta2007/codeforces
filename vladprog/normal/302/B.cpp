#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)
    {
        int c,t;
        scanf("%d%d",&c,&t);
        a[i]=c*t;
    }
    for(int t=0,i=0,j=0;j<m;j++)
    {
        int v;
        scanf("%d",&v);
        while(v>t)
            t+=a[i++];
        printf("%d\n",i);
    }
}