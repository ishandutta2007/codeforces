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
        map <int,int> o;vector <int> keys;
        for(int i=0;i<n;++i) {cin>>a[i];if(o.count(a[i])) o[a[i]]++;else{o[a[i]]=1;keys.push_back(a[i]);}}
        int ans=(n%2);
        for(auto h:keys)
        {
            ans=max(ans,2*o[h]-n);
        }
        cout<<ans<<endl;
    }
    return 0;
}