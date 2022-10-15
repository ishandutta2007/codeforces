// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
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
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=65;
const int K=18;
mt19937 rng(time(NULL));

int modpow(int u,int v){
    int ans=1, t=u;
    while (v){
        if (v&1) ans=ans*t%mod;
        t=t*t%mod, v>>=1;
    }
    return ans;
}

int n,k;
int prob[N][N],inv[N];
bool vis[N];
vector<pii> res;
int ans;
void dfs(vi& mask,int now,int d){
    if (d==sz(res)){
        int tmp=1;
        rep(i,d) {
            tmp=tmp*prob[res[i].S][mask[i]]%mod;
        } 
        // cerr<<now<<" "<<tmp*16%mod<<endl;
        ans=(ans+now%mod*tmp)%mod;
        return;
    }
    rep(i,res[d].S+1){
        mask.pb(i);
        dfs(mask,now,d+1);
        now*=res[d].F;
        mask.pop_back();
    }
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>k;
    for (int i=2;i*i<=n;++i){
        if (n%i==0){
            int w=0;
            while (n%i==0) n/=i, w++;
            res.pb({i,w}), vis[w]=1;
        }
    }
    if (n>1) res.pb({n,1}), vis[1]=1;
    for (int i=1;i<=60;++i) inv[i]=modpow(i,mod-2);
    rep1(i,59){
        if (!vis[i]) continue;
        vi f(i+1,0);
        f[i]=1;
        rep(_,k){
            vi g(i+1,0);
            for (int j=0;j<=i;++j){
                for (int k=j;k<=i;++k){
                    g[j]=(g[j]+f[k]*inv[k+1])%mod;
                }
            }
            f=g;
        }
        for (int j=0;j<=i;++j) {
            // cerr<<i<<" "<<j<<" "<<f[j]<<endl;
            prob[i][j]=f[j];
        }
    }
    vi mask;
    dfs(mask,1,0);
    cout<<ans;
    
    return 0;
}


/*
2
1 2

*/