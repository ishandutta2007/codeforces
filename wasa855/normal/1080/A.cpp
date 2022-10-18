#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n,m;
    cin>>n>>m;
    int ans=n*2/m+n*5/m+n*8/m;
    if(n*2%m!=0)
    {
        ans++;
    }
    if(n*5%m!=0)
    {
        ans++;
    }
    if(n*8%m!=0)
    {
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}