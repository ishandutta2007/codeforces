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

int x[200005], y[200005];
vector<pair<int,int>> g[200005];
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}
ll dis(pair<int,int> a, pair<int,int> b) {
    return 0ll + abs(a.first - b.first) + abs(a.second - b.second);
}
ll dp[200005][2];
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i=1;i<=n;++i) {
        cin >> x[i] >> y[i];
        v.push_back(max(x[i], y[i]));
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    for(int i=1;i<=n;++i) {
        g[lower_bound(all(v),max(x[i], y[i]))-v.begin()+1].push_back({x[i], y[i]});
    }
    g[0].push_back({0, 0});
    dp[0][0] = dp[0][1] = 0;;;;
    for(int i=1;i<=v.size();++i) {
        sort(g[i].begin(), g[i].end(), cmp);
        dp[i][0] = dis(g[i].back(), g[i][0]) + min(dp[i-1][0] + dis(g[i-1][0], g[i].back()), dp[i-1][1] + dis(g[i-1].back(), g[i].back()));
        dp[i][1] = dis(g[i].back(), g[i][0]) + min(dp[i-1][0] + dis(g[i-1][0], g[i][0]), dp[i-1][1] + dis(g[i-1].back(), g[i][0]));
    }
    cout << min(dp[v.size()][0], dp[v.size()][1]) << endl;;;;
    
}