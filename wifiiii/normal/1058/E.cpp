#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

int a[300005];
int dp[2][150][2];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    int lst=-1;
    forii
    {
        ll tmp;cin>>tmp;
        a[i]=__builtin_popcountll(tmp);
    }
    forii
    {
        int cnt = a[i];
        for(int i=1;i<=64;++i) ans+=dp[0][i][cnt&1];
        for(int i=1;i<=64;++i)
            for(int j=0;j<=1;++j)
                dp[1][min(i+cnt,64)][(j+cnt)&1] += dp[0][i][j];
        dp[1][cnt][cnt&1]++;
        swap(dp[0],dp[1]);
        memset(dp[1],0,sizeof(dp[1]));
        lst=cnt;
    }
    forii
    {
        int mx=a[i],sum=a[i];
        for(int j=i+1;j<=n;++j)
        {
            mx=max(mx,a[j]),sum+=a[j];
            if(sum-mx<mx && (sum&1)==0) ans--;
            if(sum>128) break;
        }
    }
    cout<<ans<<endl;
}