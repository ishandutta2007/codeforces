#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll dp[15][1005],sum[15][1005];
const int mod = 1e9+7;
int main()
{
    int n,m;
    cin>>n>>m;
    dp[0][0] = 1;
    for(int i=0;i<=1000;++i) sum[0][i]=1;
    for(int i=1;i<=10;++i) {
        for(int j=1;j<=1000;++j) {
            dp[i][j] = sum[i-1][j];
            sum[i][j] = (sum[i][j-1] + dp[i][j]) % mod;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;++i) {
        for(int j=i;j<=n;++j) {
            ans += dp[m][i] * dp[m][n-j+1] % mod;
        }
    }
    ans %= mod;
    cout << ans << endl;
}