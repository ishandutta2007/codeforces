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
        array<int,3> a[n];
        for(int i=0;i<n;++i) cin>>a[i][0]>>a[i][1]>>a[i][2];
        map <int,vector<vector <int> > > u;
        for(int i=0;i<n;++i)
        {
            if(u.count(a[i][0]+a[i][1]-a[i][2]))
            u[a[i][0]+a[i][1]-a[i][2]].push_back({max(0LL,a[i][0]-a[i][2]),min(a[i][0],a[i][0]+a[i][1]-a[i][2]),i});
            else
            u[a[i][0]+a[i][1]-a[i][2]]={{max(0LL,a[i][0]-a[i][2]),min(a[i][0],a[i][0]+a[i][1]-a[i][2]),i}};
        }
        int ans=0;
        int res1[n];
        for(auto [key,v1]:u)
        {
            vector <vector <int> > v=v1;
            set <vector <int> > d;
            int r=(-1);
            for(auto h:v) d.insert({h[1],h[0],h[2]});
            int ans1=0;
            for(auto h:d)
            {
                if(h[1]>r)
                {
                    r=h[0];
                    res1[h[2]]=h[0];
                    ++ans1;
                }
                else
                {
                    res1[h[2]]=r;
                }
            }
            ans+=ans1;
        }
        cout<<ans<<'\n';
        for(int i=0;i<n;++i)
        {
            cout<<(a[i][0]-res1[i])<<' '<<(a[i][2]-(a[i][0]-res1[i]))<<'\n';
        }
    }
    return 0;
}