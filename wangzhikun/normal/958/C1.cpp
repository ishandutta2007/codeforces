#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[1000001];
long long sum[1000001];
int main()
{
    int n,k;
    long long ans=0;
    memset(sum,0,sizeof(sum));
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,sum[i]%k+(sum[n]-sum[i])%k);
    }
    cout<<ans;
    return 0;
}