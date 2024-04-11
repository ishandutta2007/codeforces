#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    long long a[n+1];
    for(int i=1;i<=n;i++)
        scanf("%lli",&a[i]);
    a[n+1]=0;
    sort(a,a+n+1);
    long long s=0,k=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]-a[i-1] >1)continue;
        if(a[i]-a[i-1]==1)a[i]--;
        if(k==0)
            k=a[i];
        else
        {
            s+=a[i]*k;
            k=0;
        }
        i--;
    }
    printf("%lli",s);
}