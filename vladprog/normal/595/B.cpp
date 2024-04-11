#include<bits/stdc++.h>

using namespace std;

const int p[10]={1,
                 10,
                 100,
                 1000,
                 10000,
                 100000,
                 1000000,
                 10000000,
                 100000000,
                 1000000000};
const int mod=1e9+7;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int m=n/k;
    int a[m];
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    int b[m];
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    int ans=1;
    for(int i=0;i<m;i++)
    {
        int c1=(p[k]-1)/a[i],
            c2=(p[k-1]*(b[i]+1)-1)/a[i],
            c3=(p[k-1]*b[i]-1)/a[i];
        c1=max(c1,0);
        c2=max(c2,0);
        c3=max(c3,0);
        long long c=c1-c2+c3;
        if(b[i])c++;
        //printf("%d ",c);
        ans=(ans*c)%mod;
    }
    //printf("\n");
    printf("%d\n",ans);
}