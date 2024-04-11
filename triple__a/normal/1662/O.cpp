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
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=1e9+7;
const int INF=LLONG_MAX/5000;
const double EPS=1e-9;
// const int MAXN=2003*2003;
const int N=360*22;
const int K=360*10000;
mt19937 rng(1234);

int n,m;
set<int> ban[N];
vi g[N];
bool vis[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        rep(i,N) ban[i].clear(), g[i].clear();
        rep(i,n){
            char c;
            cin>>c;
            if (c=='C'){
                int r,t1,t2;
                cin>>r>>t1>>t2;
                if (t2<t1) t2+=360;
                for (int i=t1;i<t2;++i){
                    ban[r*360+i%360].insert((r+1)*360+i%360);
                    ban[(r+1)*360+i%360].insert(r*360+i%360);
                }
            }
            else{
                int r1,r2,t;
                cin>>r1>>r2>>t;
                for (int i=r1+1;i<=r2;++i) ban[i*360+(t-1+360)%360].insert(i*360+t), ban[i*360+t].insert(i*360+(t+359)%360);
            }
        }
        // cout<<"done"<<endl;
        for (int i=0;i<=21;++i){
            for (int j=0;j<360;++j){
                if (i>0&&ban[i*360+j].find((i-1)*360+j)==ban[i*360+j].end()) g[i*360+j].pb((i-1)*360+j);
                if (i<=20&&ban[i*360+j].find((i+1)*360+j)==ban[i*360+j].end()) g[i*360+j].pb((i+1)*360+j);
                if (ban[i*360+j].find(i*360+(j+1)%360)==ban[i*360+j].end()) g[i*360+j].pb(i*360+(j+1)%360);
                if (ban[i*360+j].find(i*360+(j+359)%360)==ban[i*360+j].end()) g[i*360+j].pb(i*360+(j+359)%360);
                // if (sz(g[i*360+j])<4) cout<<i<<" "<<j<<" "<<sz(g[i*360+j])<<endl;
            }
        }
        queue<int> q;
        memset(vis,0,sizeof(vis));
        q.push(0);
        int ans=0;
        while (sz(q)){
            auto ret=q.front();
            q.pop();
            ans=max(ans,ret);
            for (auto c:g[ret]){
                // cout<<c<<endl;
                if (vis[c]) continue;
                q.push(c), vis[c]=1;
            }
        }
        // cout<<ans<<"\n";
        if (ans>=N-100) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}