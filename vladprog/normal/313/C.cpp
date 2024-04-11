#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long a[n];
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]),a[i]*=-1;
    sort(a,a+n);
    a[0]*=-1;
    for(int i=1;i<n;i++)
        a[i]=a[i-1]+a[i]*-1;
    long long s=0;
    for(long long i=1;i<=n;i*=4)
        s+=a[i-1];
    printf("%I64d",s);
}