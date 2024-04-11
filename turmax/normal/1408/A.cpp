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
        int a[n],b[n],c[n];
        for(int i=0;i<n;++i) cin>>a[i];
        for(int i=0;i<n;++i) cin>>b[i];
        for(int i=0;i<n;++i) cin>>c[i];
        int ans[n];
        for(int i=0;i<n;++i) ans[i]=(-1);
        for(int i=0;i<n;++i)
        {
            if(a[i]!=ans[(i+n-1)%n] && a[i]!=ans[(i+1)%n])
            {
                ans[i]=a[i];
                continue;
            }
            if(b[i]!=ans[(i+n-1)%n] && b[i]!=ans[(i+1)%n])
            {
                ans[i]=b[i];
                continue;
            }
            if(c[i]!=ans[(i+n-1)%n] && c[i]!=ans[(i+1)%n])
            {
                ans[i]=c[i];
                continue;
            }
        }
        for(int i=0;i<n;++i) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}