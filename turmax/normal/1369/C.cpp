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
        int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int b[m];for(int i=0;i<m;++i) cin>>b[i];
        sort(b,b+m);
        reverse(b,b+m);
        sort(a,a+n);
        int ans=0;
        while(b[m-1]==1)
        {
            ans+=a[n-1]*2;
            n--;
            m--;
        }
        int curr=0;
        for(int i=0;i<m;++i)
        {
            ans+=a[curr];
            curr+=(b[i]-1);
        }
        curr=(n-1);
        for(int i=0;i<m;++i)
        {
            ans+=a[curr];
            curr--;
        }
        cout<<ans<<endl;
    }
    return 0;
}