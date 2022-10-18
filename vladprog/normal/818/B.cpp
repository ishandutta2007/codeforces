#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+1];
    memset(a,0,sizeof(a));
    int p;
    scanf("%d",&p);
    for(int i=2;i<=m;i++)
    {
        int l;
        scanf("%d",&l);
        int d=(l+n-p)%n;
        if(d==0)d=n;
        if(a[p]==0)a[p]=d;
        if(a[p]!=d)return printf("-1"),0;
        p=l;
    }
    int b[n+1];
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
        if(a[i])
        {
            if(b[a[i]])return printf("-1"),0;
            else b[a[i]]=true;
        }
    for(int i=1,j=0;i<=n;i++)
    {
        if(!a[i])
        {
            do j++;
            while(b[j]);
            a[i]=j;
        }
        printf("%d ",a[i]);
    }
}