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
    int n,x;
    cin>>n>>x;
    int ma=(-1);
    int u;
    int t=2;
    for(int i=0;i<n;++i)
    {
        cin>>u;
        ma=max(ma,u);
        if(u==x)
        {
            t=1;
        }
    }
    cout<<max((x+ma-1)/ma,t)<<endl;
    }
    return 0;
}