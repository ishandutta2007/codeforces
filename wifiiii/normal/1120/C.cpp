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



typedef unsigned long long ull;
struct StringHash {
    static const ull p = 132523;
    static const int maxn = 5005;
    ull pw[maxn],lh[maxn],rh[maxn];
    void init(string s) {
        int n = s.size();
        pw[0]=1,lh[1]=rh[n+1]=0;
        for(int i=1;i<=n;++i) pw[i]=pw[i-1]*p;
        for(int i=1;i<=n;++i) lh[i]=lh[i-1]*p+s[i-1];
        for(int i=n;i>=1;--i) rh[i]=rh[i+1]*p+s[i-1];
    }
  	ull getl(int i, int j) {
        return lh[j]-lh[i-1]*pw[j-i+1]; //[i,j] start with 1
    }
    ull getr(int i,int j) {
        return rh[i]-rh[j+1]*pw[j-i+1]; //[i,j] start with 1
    }
    bool ispal(int i,int j) {
        ++i, ++j;
        return lh[j]-lh[i-1]*pw[j-i+1] == rh[i]-rh[j+1]*pw[j-i+1];
    }
};
int dp[5005];
unordered_map<ull,int> mp[5005];
vector<int> g[5005];
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    StringHash h;
    h.init(s);
    memset(dp, 0x3f, sizeof(dp));
    for(int i=1;i<=n;++i) {
        int lo=i,hi=n;
        while(lo<hi) {
            int mid=(hi+lo+1)/2;
            // check if [i+1, mid] is substring of [1, i]
            int len=mid-(i+1)+1, ok = 0;
            for(int j=len;j<=i;++j) if(h.getl(j-len+1, j) == h.getl(i+1, mid)) {
                ok = 1;
                break;
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        for(int j=i+1;j<=lo;++j) {
            g[j].push_back(i);
        }
    }
    dp[0]=0;
    for(int i=1;i<=n;++i) {
        dp[i]=dp[i-1]+a;
        for(int j:g[i]) dp[i]=min(dp[i],dp[j]+b);
    }
    cout<<dp[n]<<endl;
}