#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(int n)
{
    if(n<0)
    {
        return 1e18;
    }
    if(n==0)
    {
        return 0;
    }
    int u=1;
    while(true)
    {
        if(u<=n && (2*u)>n)
        {
            return go(n-u)+1;
        }
        u*=2;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin>>n>>x;
    for(int k=0;k<1000000;++k)
    {
        if(go(n-k*x)<=k && (n-k*x)>=k)
        {
            cout<<k;
            return 0;
        }
    }
    cout<<(-1);
    return 0;
}