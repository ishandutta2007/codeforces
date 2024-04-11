#include <bits/stdc++.h>

using namespace std;
#define int long long
//after editorial solving
int go(int a,int x)
{
    int low=0;
    int up=1e9*3;
    while(true)
    {
        if((up-low)==1)
        {
            return min(low,a);
        }
        int k=(low+up)/2;
        int f=(-3*k*k-3*k-1+a);
        if(f>=x)
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int low=(-8e18);
    int up=8e18;
    while(true)
    {
        if((up-low)==1)
        {
            break;
        }
        int k;
        k=(low+up)/2;
        int b[n];
        for(int i=0;i<n;++i)
        {
            b[i]=go(a[i],k);
        }
        int sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=b[i];
        }
        if(sum>=s)
        {
            low=k;
        }
        else
        {
            up=k;
        }
    }
    int b[n];
    pair <int,int> c[n];
    int sum=0;
    for(int i=0;i<n;++i)
    {
        b[i]=go(a[i],low);
        c[i]={3*b[i]*b[i]-3*b[i]+1-a[i],i};
        sum+=b[i];
    }
    sort(c,c+n);
    reverse(c,c+n);
    for(int i=0;i<(sum-s);++i)
    {
        b[c[i].second]--;
    }
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}