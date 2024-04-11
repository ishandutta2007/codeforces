#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <pair<int,int> > a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    if(n%2==1)
    {
        cout<<"NO";
        return 0;
    }
    set <pair<int,int> > o;
    for(int i=0;i<(n/2);++i)
    {
        o.insert({a[i].first+a[i+n/2].first,a[i].second+a[i+n/2].second});
    }
    if(o.size()==1)
    {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    return 0;
}