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

int dp[5005][5005];
int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]) - 1);
            }
            ans = max(ans, dp[i][j]);
//            cout << dp[i][j] << " ";
        }
//        cout << endl;
    }
    cout << ans << endl;
}