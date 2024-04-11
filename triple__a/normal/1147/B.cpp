// how to come up with such solution :(

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
const int mod=998244353;
const int INF=INT_MAX/2;
const double EPS=1e-9;
const int N=200007;
const int K=207;
mt19937 rng(time(NULL));

typedef bitset<300> bs;
int n,m;
vi g[N];
bool vis[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>m;
    vi p;
    p.pb(1);
    for (int i=2;i<=n;++i){
        if (vis[i]) continue;
        p.pb(i);
        for (int j=1;i*j<=n;++j) vis[i*j]=1;
    }
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--, v--;
        g[u].pb((v-u+n)%n), g[v].pb((u-v+n)%n);
    }
    for (int i=1;i<n;++i){
        if (n%i==0){
            int w=i;
            bool ok=1;
            for (int j=0;j<n;++j){
                // cerr<<sz(g[j])<<" "<<sz(g[(j+w)%n])<<endl;
                if (sz(g[j])!=sz(g[(j+w)%n])) {ok=0; break;}
                unordered_set<int> st;
                // cerr<<"fk: "<<j<<" "<<j+w<<endl;
                // for (auto c:g[j]) cerr<<c<<" ";
                // cerr<<"\n";
                // for (auto c:g[(j+w)%n]) cerr<<c<<" ";
                // cerr<<"\n";
                for (auto c:g[j]) st.insert(c);
                for (auto c:g[(j+w)%n]) if (st.find(c)==st.end()) {ok=0; break;}
                if (!ok) break;
            }
            if (ok){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}


/*
12 6
1 3
3 7
5 7
7 11
9 11
11 3

*/