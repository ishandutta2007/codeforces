#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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

const int maxn = 400005;
int a[maxn],dp[maxn][2];
int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ii cin>>a[i];
        for(int i=0;i<=n;++i)for(int j=0;j<2;++j) dp[i][j]=1e9;
        dp[0][0]=0;
        for(int i=0;i<n;++i) {
            // j == 0
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + a[i+1]);
            dp[i+2][1] = min(dp[i+2][1], dp[i][0] + a[i+1] + a[i+2]);
            // j == 1
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
            dp[i+2][0] = min(dp[i+2][0], dp[i][1]);
        }
        cout<<min(dp[n][0],dp[n][1])<<endl;
    }
}