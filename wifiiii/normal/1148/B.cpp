
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)
#define int ll
int a[200005],b[200005];
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;
    if(k>=n || k>=m)
    {
        cout<<-1<<endl;
        return 0;
    }
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    int ans = 0;
    for(int i=0;i<=k;++i)
    {
        int tmp = a[i+1] + ta;
        int pos = lower_bound(b+1, b+1+m, tmp) - b;
        if(pos+k-i>m)
        {
            cout<<-1<<endl;
            return 0;
        }
        ans = max(ans, b[pos+k-i]+tb);
    }
    cout<<ans<<endl;
}