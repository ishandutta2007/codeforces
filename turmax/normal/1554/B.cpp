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
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int ans=(-1e9);
        for(int i=max(0LL,n-250);i<n;++i)
        {
            for(int j=max(0LL,n-250);j<i;++j)
            {
                ans=max(ans,(i+1)*(j+1)-k*(a[i] | a[j]));
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}