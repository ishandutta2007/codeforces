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
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;

char a[1000005][5];
int dp[1000005][1<<3];
int main() {
    int n,m;
    cin>>n>>m;
    if(n>3 && m>3) return cout<<-1<<endl,0;
    if(m > 3) {
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=m;++j) {
                char c;
                cin>>c;
                a[j][i]=c;
            }
        }
        swap(n, m);
    } else {
        for(int i=1;i<=n;++i) {
            for(int j=1;j<=m;++j) {
                char c;
                cin>>c;
                a[i][j]=c;
            }
        }
    }
    if(m == 1) return cout << 0 << endl, 0;
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<1<<m;++j) {
            for(int k=0;k<1<<m;++k) {
                int cnt=0;
                for(int p=0;p<m;++p) if((k>>p&1)^(a[i+1][p+1]-'0')) ++cnt;
                int ok=1;
                if(i) for(int p=0;p<=m-2;++p) {
                    int c=(j>>p&1)+(j>>(p+1)&1)+(k>>p&1)+(k>>(p+1)&1);
                    if(c%2!=1) ok=0;
                }
//                cout<<j<<" "<<k<<" "<<ok<<endl;
                if(ok) dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cnt);
            }
        }
    }
    int ans=2e9;
//    for(int i=1;i<=n;++i) {
//        cout<<i<<":"<<endl;
//        for(int j=0;j<1<<m;++j) cout<<bitset<3>(j)<<": "<<dp[i][j]<<endl;
//    }
    for(int i=0;i<1<<m;++i) ans=min(ans,dp[n][i]);
    cout<<ans<<endl;
}