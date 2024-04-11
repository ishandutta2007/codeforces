#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int l[n],r[n];
    l[0]=1;r[n-1]=1;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=1;i<n;++i)
    {
        if(a[i]>a[i-1])
        {
            l[i]=l[i-1]+1;
        }
        else
        {
            l[i]=1;
        }
    }
    for(int i=(n-2);i>=0;--i)
    {
        if(a[i]<a[i+1])
        {
            r[i]=r[i+1]+1;
        }
        else
        {
            r[i]=1;
        }
    }
    int ans=1;
    for(int i=0;i<n;++i)
    {
        if(i!=0 && i!=(n-1) && a[i+1]>=(a[i-1]+2))
        {
            ans=max(ans,l[i-1]+1+r[i+1]);
        }
        if(i!=0)
        {
            ans=max(ans,l[i-1]+1);
        }
        if(i!=(n-1))
        {
            ans=max(ans,r[i+1]+1);
        }
    }
    cout<<ans;
    return 0;
}