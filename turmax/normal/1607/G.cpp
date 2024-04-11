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
        int s=0;
        int n,m;
        cin>>n>>m;
        vector <vector <int> > a(n);
        vector <pair<int,int> > z;
        int sr=0;
        for(int i=0;i<n;++i)
        {
            a[i].resize(3);
            cin>>a[i][0]>>a[i][1];
            a[i][2]=m;
            s+=(a[i][0]+a[i][1]-a[i][2]);
            z.push_back({max(0LL,a[i][0]-a[i][2]),min(a[i][0],a[i][1]+a[i][0]-a[i][2])});
            sr+=z.back().second;
        }
        int res[n];
        for(int i=0;i<n;++i)
        {
            if(sr<=(s/2))
            {
                res[i]=z[i].second;
            }
            else if(sr+z[i].first-z[i].second>=(s/2))
            {
                sr-=(z[i].second-z[i].first);
                res[i]=z[i].first;
            }
            else
            {
                res[i]=z[i].second+(s/2)-sr;
                sr=s/2;
            }
        }
        cout<<abs(2*sr-s)<<'\n';
        for(int i=0;i<n;++i)
        {
            cout<<a[i][0]-res[i]<<' '<<a[i][1]-(a[i][0]+a[i][1]-a[i][2]-res[i])<<'\n';
        }
    }
    return 0;
}