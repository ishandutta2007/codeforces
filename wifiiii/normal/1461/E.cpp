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

const int maxn = 1000005;
ll dp[maxn];
struct edge {
    ll v,w;
};
vector<edge> g[maxn];
int deg[maxn];
int main() {
    int T=1;
    while(T--) {
        ll k,l,r,t,x,y;
        cin>>k>>l>>r>>t>>x>>y;
        r-=l,k-=l,l=0;
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        if(k+y > r && k-x < l) ans = 0;
        else if(x == y) {
            ans = 1;
        } else if(y < x) {
            ll mx = 0;
            if(k+y > r) {
                k -= x;
                if(k < l) {
                    mx = 0;
                } else {
                    mx = 1 + k/(x-y);
                }
                if(mx < t) ans = 0;
                else ans = 1;
            } else {
                mx = k/(x-y);
                if(mx < t) ans = 0;
                else ans = 1;
            }
        } else {
            for(int i=0;i<x;++i) {
                if(l+i+y>r) dp[i]=1;
                else {
                    if((i+y)%x == i) {
                        dp[i]=0;
                    } else {
                        int nxt=(i+y)%x;
                        g[nxt].push_back({i,(i+y-x)/x+1});
                        deg[i]++;
                    }
                }
            }
            queue<int> q;
            for(int i=0;i<x;++i) if(dp[i]!=-1) q.push(i);
            while(!q.empty()) {
                int cur=q.front();q.pop();
                for(edge e:g[cur]) {
                    if(dp[cur] == 0) dp[e.v] = 0;
                    else dp[e.v] = dp[cur]+e.w;
                    if(--deg[e.v] == 0) {
                        q.push(e.v);
                    }
                }
            }
            for(int i=0;i<x;++i) if(dp[i]==-1) dp[i]=0;
            k-=l;
            if(dp[k%x]==0 || t <= dp[k%x]-1+k/x) ans=1;
            else ans=0;
        }
        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }
}