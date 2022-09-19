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
        int n,l,r;
        cin>>n>>l>>r;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans+=upper_bound(a+i+1,a+n,r-a[i])-lower_bound(a+i+1,a+n,l-a[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}