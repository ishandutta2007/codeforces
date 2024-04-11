#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

const int M=1010,N=60,MOD=1e9+7;

string s[N];
int dp[M][M],sum[M];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    unordered_map<int,int> cnt;
    for(int i=0;i<m;i++)
    {
        int mask=0;
        for(int j=0;j<n;j++)
            if(s[j][i]=='1')
                mask|=1ll<<j;
        cnt[mask]++;
    }
    dp[0][0]=sum[0]=1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=i;j++)
            dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1])%MOD,
            sum[i]=(sum[i]+dp[i][j])%MOD;
//    for(int i=0;i<=30;i++)
//        cout<<sum[i]<<" ";
//    cout<<"\n";
    int ans=1;
    for(auto p:cnt)
        ans=ans*sum[p.y]%MOD;
    cout<<ans;
}