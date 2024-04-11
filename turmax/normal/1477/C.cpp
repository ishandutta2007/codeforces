#include <bits/stdc++.h>

using namespace std;
#define int long long
int dist(pair <int,int> u,pair <int,int> v)
{
    return (u.first-v.first)*(u.first-v.first)+(u.second-v.second)*(u.second-v.second);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> a[n];
    for(int i=0;i<n;++i) cin>>a[i].first>>a[i].second;
    bool used[n];
    for(int i=0;i<n;++i) used[i]=false;
    vector <int> ans;
    ans.push_back(0);
    int curr=0;
    used[0]=true;
    while(ans.size()!=n)
    {
        pair <int,int> ma={-1,-1};
        for(int i=0;i<n;++i)
        {
            if(!used[i])
            {
                ma=max(ma,{dist(a[curr],a[i]),i});
            }
        }
        int l=ma.second;
        curr=l;
        ans.push_back(curr);
        used[curr]=true;
    }
    for(auto h:ans) cout<<(h+1)<<' ';
    return 0;
}