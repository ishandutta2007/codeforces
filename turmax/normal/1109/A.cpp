#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    int pr[n+1];
    pr[0]=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        pr[i+1]=pr[i]^a[i];
    }
    map <pair<int,int>,int> d;
    vector <pair<int,int> > keys;
    for(int i=0;i<=n;++i)
    {
        pair <int,int> u=make_pair(i%2,pr[i]);
        //cout<<u.first<<" "<<u.second<<" update "<<endl;
        if(!d.count(u))
        {
            keys.push_back(u);
            d[u]=1;
        }
        else
        {
            d[u]++;
        }
    }
    int ans=0;
    for(int i=0;i<keys.size();++i)
    {
        int x=d[keys[i]];
        ans+=(x*(x-1)/2);
    }
    cout<<ans;
    return 0;
}