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
        int x,y;
        cin>>x>>y;
        if(y<x) {cout<<(x+y)<<'\n';continue;}
        int o=y/x;
        int ans=((o*x)+y)/2;
        assert(ans%x==y%ans);
        cout<<ans<<'\n';
    }
    return 0;
}