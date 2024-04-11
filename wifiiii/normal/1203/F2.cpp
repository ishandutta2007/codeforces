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


// dp[i][j]: 1~i, r>=j
// dp[i][j] = max(dp[i-1][j], dp[i-1][r-b[j]])
int dp[105][60005];
int main() {
    int n,r;
    cin>>n>>r;
    vector<pair<int,int>> v1,v2;
    for(int i=1;i<=n;++i) {
        int a,b;
        cin>>a>>b;
        if(b>=0) v1.push_back({a,b});
        else v2.push_back({a,b});
    }
    sort(all(v1),[&](pii i,pii j){return i.first<j.first;});
    sort(all(v2),[&](pii i,pii j){return i.second+i.first<j.first+j.second;});
    int ans=0;
    for(auto p:v1) if(r>=p.first) r+=p.second,++ans;
    int mx=0;
    for(int i=1;i<=v2.size();++i) {
        int a=v2[i-1].first,b=v2[i-1].second;
        for(int j=0;j<=r;++j) {
            dp[i][j] = dp[i-1][j];
            if(j) dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
            if(j>=a && j+b>=0) dp[i][j] = max(dp[i][j], dp[i-1][j+b] + 1);
            mx=max(mx,dp[i][j]);
        }
    }
    cout<<mx+ans<<endl;
}