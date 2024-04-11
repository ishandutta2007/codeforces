#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int cnt[61][2]={};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int x;
                cin>>x;
                cnt[i+j][x]++;
            }
        int ans=0;
        for(int l=2,r=n+m;l<r;l++,r--)
            ans+=min(cnt[l][0]+cnt[r][0],cnt[l][1]+cnt[r][1]);
        cout<<ans<<"\n";
    }
}