#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int sum[maxn][30];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<maxn;++i)
    {
        for(int j=0;j<30;++j) {sum[i][j]=sum[i-1][j];sum[i][j]+=((bool) (i & (1<<j)));}
    }
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        int ans=1e9;
        for(int i=0;i<30;++i) ans=min(ans,r-l+1-sum[r][i]+sum[l-1][i]);
        cout<<ans<<'\n';
    }
    return 0;
}