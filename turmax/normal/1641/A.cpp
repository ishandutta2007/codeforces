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
        int n,x;
        cin>>n>>x;
        int a[n];
        multiset <int> b;
        for(int i=0;i<n;++i) {cin>>a[i];b.insert(a[i]);}
        int ans=0;
        while(!b.empty())
        {
            int u=(*b.begin());
            b.erase(b.find(u));
            if(b.find(u*x)!=b.end())
            {
                b.erase(b.find(u*x));continue;
            }
            ++ans;
        }
        cout<<ans<<'\n';
    }
    return 0;
}