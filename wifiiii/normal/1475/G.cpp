#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int cnt[200005], dp[200005];
vector<int> g[200005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    for(int i=1;i<=200000;++i) {
        for(int j=i+i;j<=200000;j+=i) {
            g[j].push_back(i);
        }
    }
    while(t--) {
        memset(cnt,0,sizeof(cnt));
        int n;
        cin >> n;
        for(int i=1;i<=n;++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int ans=0;
        for(int i=1;i<=200000;++i) {
            dp[i]=cnt[i];
            for(int j:g[i]) dp[i]=max(dp[i],dp[j]+cnt[i]);
            ans=max(ans,dp[i]);
        }
        cout<<n-ans<<endl;
    }
}