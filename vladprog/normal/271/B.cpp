#include<bits/stdc++.h>

using namespace std;

int main()
{
    int p[100004];
    p[0]=0;
    p[1]=0;
    for(int i=2;i<100004;i++)
        p[i]=1;
    for(long long i=2;i<100004;i++)
        if(p[i])
            for(long long j=i*i;j<100004;j+=i)
                p[j]=0;
    for(int i=100003,l=100003;i>=0;i--)
    {
        if(p[i])l=i;
        p[i]=l-i;
    }
    /*for(int i=1;i<=20;i++)
        printf("%d ",p[i]);
    printf("\n");*/
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int t;
            scanf("%d",&t);
            a[i][j]=p[t];
            //printf("%d ",p[t]);
        }
        //printf("\n");
    }
    int ans=1e9;
    for(int i=0;i<n;i++)
    {
        int t=0;
        for(int j=0;j<m;j++)
            t+=a[i][j];
        //printf("%d - %d\n",i,t);
        ans=min(ans,t);
    }
    for(int j=0;j<m;j++)
    {
        int t=0;
        for(int i=0;i<n;i++)
            t+=a[i][j];
        //printf("%d - %d\n",j,t);
        ans=min(ans,t);
    }
    printf("%d",ans);
}