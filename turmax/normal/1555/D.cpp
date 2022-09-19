#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    int sum[n+1][6];
    for(int i=0;i<6;++i) sum[0][i]=0;
    vector <string> d={"abc","acb","bac","bca","cab","cba"};
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<6;++j)
        {
            int x=abs(d[j][i%3]-s[i]);
            sum[i+1][j]=sum[i][j]+min(1LL,x);
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        int ans=1e18;
        for(int i=0;i<6;++i) ans=min(ans,sum[r][i]-sum[l][i]);
        cout<<ans<<'\n';
    }
    return 0;
}