#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
const int maxn = 300005;
ll a[maxn],b[maxn];
ll dp[maxn][4];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i]>>b[i];
        for(int i=1;i<=n;++i) for(int j=0;j<=3;++j) dp[i][j]=1e18;
        dp[1][0] = 0;
        dp[1][1] = b[1];
        dp[1][2] = b[1] + b[1];
        for(int i=2;i<=n;++i)
        {
            for(int j1=0;j1<=2;++j1)
                for(int j2=0;j2<=2;++j2)
                    if(a[i-1] + j1 != a[i] + j2)
                        dp[i][j2] = min(dp[i][j2], dp[i-1][j1] + j2 * b[i]);
        }
        
        ll ans = 0;
        ans = min(min(dp[n][0],dp[n][1]),dp[n][2]);
        cout << ans << endl;
    }
}