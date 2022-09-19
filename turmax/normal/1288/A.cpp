#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n,d;
    cin>>n>>d;
    int ans=1e18;
    for(int i=0;i<2*sqrt(d);++i)
    {
        ans=min(ans,i+((d+i)/(i+1)));
    }
    if(ans<=n)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}