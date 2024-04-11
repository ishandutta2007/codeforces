#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m,k;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    long long a[n+1];
    for(long long i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    long long l[m+1],r[m+1];
    long long d[m+1];
    for(long long i=1;i<=m;i++)
        scanf("%I64d%I64d%I64d",&l[i],&r[i],&d[i]);
    long long c[m+2];
    memset(c,0,sizeof(c));
    for(long long i=1;i<=k;i++)
    {
        long long x,y;
        scanf("%I64d%I64d",&x,&y);
        c[x]++;
        c[y+1]--;
    }
    for(long long i=2;i<=m;i++)
        c[i]+=c[i-1];
    long long sum[n+2];
    memset(sum,0,sizeof(sum));
    for(long long i=1;i<=m;i++)
        sum[l[i]]+=c[i]*d[i],sum[r[i]+1]-=c[i]*d[i];
    for(long long i=2;i<=n;i++)
        sum[i]+=sum[i-1];
    for(long long i=1;i<=n;i++)
        printf("%I64d ",a[i]+sum[i]);
}