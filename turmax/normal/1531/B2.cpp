#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> a[n];
    for(int i=0;i<n;++i) cin>>a[i].first>>a[i].second;
    map <int,int> h;
    vector <int> keys;
    for(int i=0;i<n;++i)
    {
        if(h.count(a[i].first)) {h[a[i].first]++;}
        else {h[a[i].first]=1;keys.push_back(a[i].first);}
        if(a[i].first!=a[i].second)
        {
        if(h.count(a[i].second)) {h[a[i].second]++;}
        else {h[a[i].second]=1;keys.push_back(a[i].second);}
        }
    }
    int ans=0;
    for(auto z:keys) ans+=(h[z]*(h[z]-1))/2;
    map <pair <int,int>,int> h1;
    vector <pair<int,int> > keys1;
    for(int i=0;i<n;++i)
    {
        if(a[i].first!=a[i].second)
        {
            pair <int,int> l={min(a[i].first,a[i].second),max(a[i].first,a[i].second)};
            if(h1.count(l)) h1[l]++;
            else {h1[l]=1;keys1.push_back(l);}
        }
    }
    for(auto z:keys1) ans-=(h1[z]*(h1[z]-1))/2;
    cout<<ans;
    return 0;
}