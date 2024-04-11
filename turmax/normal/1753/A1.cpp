#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        if(n%2==1) {cout<<(-1)<<'\n';continue;}
        vector<pair<int,int> > v;
        for(int i=0;i<n;i+=2)
        {
            if(a[i]==a[i+1])
            {
                v.push_back({i+1,i+2});
            }
            else
            {
                v.push_back({i+1,i+1});
                v.push_back({i+2,i+2});
            }
        }
        cout<<v.size()<<'\n';
        for(auto [x,y]:v) cout<<x<<' '<<y<<'\n';
    }
    return 0;
}