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
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    vector <int> v[n+1];
    for(int i=0;i<n;++i)
    {
        v[a[i]].push_back(i);
    }
    int ans=0;
    for(int j=0;j<n;++j)
    {
        for(int k=(j+1);k<n;++k)
        {
            ans+=(lower_bound(v[a[k]].begin(),v[a[k]].end(),j)-v[a[k]].begin())*(v[a[j]].end()-upper_bound(v[a[j]].begin(),v[a[j]].end(),k));
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}