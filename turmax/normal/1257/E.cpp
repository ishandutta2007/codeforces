#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k1,k2,k3;
    cin>>k1>>k2>>k3;
    int n=k1+k2+k3;
    int d[n];
    int k;
    for(int i=0;i<k1;++i)
    {
        cin>>k;
        k--;
        d[k]=1;
    }
    for(int i=0;i<k2;++i)
    {
        cin>>k;
        k--;
        d[k]=2;
    }
    for(int i=0;i<k3;++i)
    {
        cin>>k;
        k--;
        d[k]=3;
    }
    int a[n+1];
    int b[n+1];
    int c[n+1];
    a[0]=0;
    b[0]=0;
    c[0]=0;
    for(int i=0;i<n;++i)
    {
        if(d[i]==1)
        {
            a[i+1]=a[i];
            b[i+1]=min(b[i]+1,a[i]+1);
            c[i+1]=min(c[i]+1,min(b[i]+1,a[i]+1));
        }
        if(d[i]==2)
        {
            a[i+1]=a[i]+1;
            b[i+1]=min(b[i],a[i]);
            c[i+1]=min(c[i]+1,min(b[i]+1,a[i]+1));
        }
        if(d[i]==3)
        {
            a[i+1]=a[i]+1;
            b[i+1]=min(b[i]+1,a[i]+1);
            c[i+1]=min(c[i],min(a[i],b[i]));
        }
    }
    cout<<min(a[n],min(b[n],c[n]));
    return 0;
}