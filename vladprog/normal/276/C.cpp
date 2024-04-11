#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    long long b[n+1];
    memset(b,0,sizeof(b));
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        b[l-1]++;
        b[r]--;
    }
    for(int i=1;i<n;i++)
        b[i]+=b[i-1];
    sort(b,b+n);
    long long ans=0;
    for(int i=0;i<n;i++)
        ans+=a[i]*b[i];
    printf("%lld",ans);
}