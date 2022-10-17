#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

ll a[105][105],b[105][105],dp[105][105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        ii jj cin>>a[i][j];
        ii jj a[i][j]-=i+j-2;
        ii jj b[i][j]=-1111;
        vector<pair<int,int>> ord;
        ii jj ord.push_back({i,j});
        sort(all(ord),[&](pii &i,pii &j){return a[i.first][i.second]>a[j.first][j.second];});
        ll ans=8e18;
        for(int i=0;i<=n;++i) dp[i][0]=-1111;
        for(int i=0;i<=m;++i) dp[0][i]=-1111;
        dp[0][1]=dp[1][0]=0;
        for(auto &p : ord) {
            int x=p.first,y=p.second;
            ll mn=a[x][y];
            b[x][y]=mn;
//            ii {jj cout<<b[i][j]<<" ";cout<<endl;};
            ii jj {
                if(b[i][j]==-1111) dp[i][j]=-1111;
                else {
                    dp[i][j]=8e18;
                    if(dp[i-1][j]!=-1111) dp[i][j]=min(dp[i][j],b[i][j]+dp[i-1][j]);
                    if(dp[i][j-1]!=-1111) dp[i][j]=min(dp[i][j],b[i][j]+dp[i][j-1]);
                    if(dp[i][j]>4e18) dp[i][j]=-1111;
                }
            }
//            ii {jj cout<<dp[i][j]<<" ";cout<<endl;};
            if(dp[n][m]!=-1111) ans=min(ans,dp[n][m]-(n+m-1)*mn);
        }
        cout<<ans<<endl;
    }
}