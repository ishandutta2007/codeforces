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
        int a[n*m];
        for(int i=0;i<(n*m);++i) cin>>a[i];
        int ans=0;
        for(int i=0;i<m;++i) for(int j=(i+1);j<m;++j) if(a[i]<a[j]) ++ans;
        cout<<ans<<'\n';
    }
    return 0;
}