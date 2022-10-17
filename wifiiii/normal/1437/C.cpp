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
typedef pair<int,int> pii;

const int maxn = 205;
int a[maxn], dp[maxn][maxn*2];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ii cin>>a[i];
        sort(al(a));
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=n;++i) {
            for(int j=1;j<2*maxn;++j) {
                for(int k=0;k<j;++k) {
                    dp[i][j]=min(dp[i][j], dp[i-1][k] + abs(j-a[i]));
                }
            }
        }
        int ans=1e9;
        for(int i=1;i<2*maxn;++i) ans=min(ans, dp[n][i]);
        cout<<ans<<endl;
    }
}