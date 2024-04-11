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
const int N=47;
const int K=18;
mt19937 rng(time(NULL));

int n,m,q;
int d[N],p[N],g[N],calc[N][N],f[N],C[N][N];
bool vis[N];
vi can;
map<vi,int> res;
void dfs(vi& mask,vi &sub,vector<vi> &submasks,int d){
    if (d==m){
        submasks.pb(sub);
        // sub.pop_back();
        return;
    }
    rep(i,mask[d]+1){
        sub.pb(i);
        dfs(mask,sub,submasks,d+1);
        sub.pop_back();
    }
}
int solve(vi& mask){
    if (res.find(mask)!=res.end()) return res[mask];
    int ret=0;
    vector<vi> submasks;
    vi sub;
    dfs(mask,sub,submasks,0);
    submasks.pop_back();
    if (!sz(submasks)) return 1;
    int ssum=0,csum=0;
    rep(i,m) ssum+=mask[i],csum+=mask[i]*can[i];
    for (auto c:submasks){
        int pd=1, sum0=0,sum1=0;
        rep(i,m) pd=pd*C[mask[i]][c[i]]%mod, sum0+=c[i], sum1+=c[i]*can[i];
        if ((ssum-sum0)&1) ret=(ret+pd*calc[csum-sum1][sum1]%mod*solve(c))%mod;
        else ret=(ret-pd*calc[csum-sum1][sum1]%mod*solve(c)%mod+mod)%mod;
    }
    return res[mask]=ret;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n;
    f[0]=1;
    rep1(i,n) f[i]=f[i-1]*i%mod;
    C[0][0]=1;
    rep1(i,n) {
        C[i][0]=1;
        rep1(j,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    for (int i=0;i<n;++i){
        g[i]=f[i]*f[n-i-1]%mod;
    }
    for (int i=1;i<=n;++i){
        for (int j=0;i+j<=n;++j){
            int tmp=0;
            for (int k=0;k<=j;++k) tmp=(tmp+C[j][k]*g[k])%mod;
            calc[i][j]=1;
            for (int k=0;k<i;++k) calc[i][j]=calc[i][j]*tmp%mod;
        }
    }
    rep(i,n) cin>>p[i], p[i]--;
    rep(i,n){
        if (vis[i]) continue;
        int now=i,cnt=0;
        while (1){
            cnt++;
            vis[now]=1, now=p[now];
            if (now==i) break;
        }
        d[cnt]++;
    }
    vi full;
    rep1(i,n) if (d[i]) can.pb(i), full.pb(d[i]);
    // cerr<<"done"<<endl;
    m=sz(can);
    cout<<solve(full);
    return 0;
}


/*
2
1 2

*/