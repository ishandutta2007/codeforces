#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2005;

char grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    char a;
    ll ans=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin >> a; grid[i][j]=a;
            dp[i][j]=1;
            if (a!=grid[i-1][j]);
            else if (grid[i-2][j]==a&&grid[i-1][j-1]==a&&grid[i-1][j+1]==a){
                dp[i][j]=min({dp[i-2][j],dp[i-1][j-1],dp[i-1][j+1]})+1;
            }
            ans+=dp[i][j];
        }
    }
    cout << ans << '\n';
}