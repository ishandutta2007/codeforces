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
    int n,m;
    cin>>n>>m;
    pair <int,int> a[m];
    vector <int> v;
    for(int i=0;i<m;++i)
    {
        cin>>a[i].first>>a[i].second;
        v.push_back(a[i].first);
    }
    sort(v.begin(),v.end());
    int pr[v.size()+1];pr[0]=0;
    for(int i=0;i<v.size();++i)
    {
        pr[i+1]=pr[i]+v[i];
    }
    int res=0;
    for(int i=0;i<m;++i)
    {
        int ans=a[i].second*n;
        //cout<<ans<<" ans "<<endl;
        if(a[i].first<=a[i].second)
        {
            ans+=(a[i].first-a[i].second);
        }
        //cout<<ans<<" ans "<<endl;
        int z=lower_bound(v.begin(),v.end(),a[i].second)-v.begin();
        int o=max(z,m-n);
        ans+=(pr[m]-pr[o]-((m-o)*a[i].second));
        //cout<<i<<" i "<<ans<<" ans "<<endl;
        res=max(res,ans);
    }
    cout<<res<<endl;
    }
    return 0;
}