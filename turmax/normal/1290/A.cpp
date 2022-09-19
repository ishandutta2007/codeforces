#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n,m,k;
    cin>>n>>m>>k;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int t1,t2;
    int ans=0;
    if(k>=m)
    {
        k=(m-1);
    }
    for(int i=0;i<=k;++i) //left
    {
        int o=1e18;
        int x=i;
        int y=(k-i);
        for(int j=0;j<(m-k);++j)
        {
            t1=(i+j);
            t2=(n-1-(k-i)-(m-1-k-j));
            //cout<<i<<" "<<j<<" "<<max(a[t1],a[t2])<<endl;
            o=min(o,max(a[t1],a[t2]));
        }
        ans=max(ans,o);
    }
    cout<<ans<<endl;
    }
    return 0;
}