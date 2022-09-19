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
        int a[n],b[n];
        for(int i=0;i<n;++i) cin>>b[i]; for(int i=0;i<n;++i) cin>>a[i];
        int pra[n+1];int prb[n+1];
        pra[0]=0;prb[0]=0;
        for(int i=0;i<n;++i) {pra[i+1]=pra[i]+a[i];prb[i+1]=prb[i]+b[i];}
        int ans=1e18;
        for(int i=0;i<n;++i)
        {
            ans=min(ans,max(pra[i],prb[n]-prb[i+1]));
        }
        cout<<ans<<'\n';
    }
    return 0;
}