#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    pair <int,int> a[n];
    vector <pair<int,int> > v[m];
    set <pair<int,int> > z;
    int c=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        a[i].first--;
        if(a[i].first==0)
        {
            ++c;
        }
        v[a[i].first].push_back({a[i].second,i});
    }
    for(int i=0;i<m;++i)
    {
        sort(v[i].begin(),v[i].end());
    }
    int ans=1e18;
    for(int i=max(1LL,c);i<=n;++i)
    {
        z.clear();
        for(int j=0;j<n;++j)
        {
            if(a[j].first)
            z.insert({a[j].second,j});
        }
        int sum=0;
        int curr=c;
        for(int j=1;j<m;++j)
        {
            for(int k=0;k<=(v[j].size()-i);++k)
            {
                sum+=v[j][k].first;
                z.erase(v[j][k]);
                ++curr;
            }
        }
        while(curr<i)
        {
            sum+=(*z.begin()).first;
            z.erase(z.begin());
            ++curr;
        }
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}