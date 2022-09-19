#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[n];
    bool is[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]==(i+1)) is[i]=true;
        else is[i]=false;
    }
    int sum=0;
    for(int i=0;i<n;++i)
    {
        if(is[i]) ++sum;
    }
    if(sum==n)
    {
        cout<<0<<endl;
        continue;
    }
    int l=0;
    int r=(n-1);
    while(true)
    {
        if(is[l])
        {
            ++l;
        }
        else
        {
            break;
        }
    }
    while(true)
    {
        if(is[r])
        {
            --r;
        }
        else
        {
            break;
        }
    }
    if(sum==(l+(n-r-1)))
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<2<<endl;
    }
    }
    return 0;
}