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
        int mi=(*min_element(a,a+n));
        int ans=0;
        for(int i=0;i<n;++i) if(a[i]!=mi) ++ans;
        cout<<ans<<'\n';
    }
    return 0;
}