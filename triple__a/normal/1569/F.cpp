#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod=998244353;
const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(vi x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        int res=0;
        for (auto c:x) res^=splitmix64(c + FIXED_RANDOM);
        return res;
    }
};

const int maxn=100007;
const double EPS=1e-9;
const double pi=3.14159265358979;
int n,m,k;
bool vis[12][12];
int col[6][2];
bool dp[1<<6][6];
unordered_set<vi,custom_hash> res;
bool v[12];
bool ok(){
    memset(dp,0,sizeof(dp));
    int m=n>>1;
    rep(i,m) dp[1<<i][i]=1;
    rep(i,1<<m){
        if (__builtin_popcount(i)<2) continue;
        rep(j,m){
            if (i>>j&1){
                rep(k,m){
                    if (!dp[i^(1<<j)][k]) continue;
                    if ((i>>k&1)&&((vis[col[j][0]][col[k][0]]&&vis[col[j][1]][col[k][1]])||(vis[col[j][0]][col[k][1]]&&vis[col[j][1]][col[k][0]]))) dp[i][j]=1;
                }
            }
        }
    }
    rep(j,m) if (dp[(1<<m)-1][j]&&vis[col[j][0]][col[j][1]]) return 1;
    return 0;
}
vi hii;
void dfs2(int rem){
    if (!rem){
        vi tmp;
        tmp.clear();
        for (auto c:hii){
            int qq=0;
            rep(i,c){
                if (c>>i&1) qq+=(1<<col[i][0])+(1<<col[i][1]);
            }
            tmp.pb(qq);
        }
        sort(range(tmp));
        res.insert(tmp);
        return;
    }
    for (int mask=rem;mask>rem/2;mask=(mask-1)&rem){
        hii.pb(mask);
        dfs2(mask^rem);
        hii.pop_back();
    }
}
void dfs(int dep){
    if (dep==n/2){
        if (ok()) dfs2((1<<(n/2))-1);
        return;
    }
    int fst=0;
    rep(i,n){
        if (v[i]) continue;
        fst=i; break;
    }
    col[dep][0]=fst, v[fst]=1;
    rep(i,n){
        if (v[i]) continue;
        v[i]=1, col[dep][1]=i;
        dfs(dep+1);
        v[i]=0;
    }
    v[fst]=0;
}
int f[13];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(20);
    cin>>n>>m>>k;
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--, v--;
        vis[u][v]=vis[v][u]=1;
    }
    f[0]=1;
    for (int i=1;i<=12;++i) f[i]=f[i-1]*i;
    dfs(0);
    int ans=0;
    for (auto v:res){
        ans+=(k<sz(v)?0:f[k]/f[k-sz(v)]);
    }
    cout<<ans;
    return 0;
}

/*
2
101919804931827191 136638622643121931

*/