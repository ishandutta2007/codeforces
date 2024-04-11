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
mt19937 rng(1234);

uint32_t b[N],x,y,z,b1,b2;
int a[N];
int n,l,r;
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    // int _;
    // cin>>_;
    // while (_--){
    //     cin>>n>>l>>r>>x>>y>>z>>b1>>b2;
    //     b[1]=b1, b[2]=b2;
    //     for (int i=3;i<=n;++i) b[i]=b[i-2]*x+b[i-1]*y+z;
    //     for (int i=1;i<=n;++i) a[i]=b[i]%(r-l+1)+l;
    //     for (int i=1;i<=n;++i) 
    // }
    int n,m;
    cin>>n>>m;
    if (m==n*(n-1)/2) {
        cout<<"NO\n";
        return 0;
    }
    set<pii> ban;
    while (m--){
        int u,v;
        cin>>u>>v;
        if (u>v) swap(u,v);
        ban.insert({u,v});
    }
    cout<<"YES\n";
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            if (ban.find({i,j})!=ban.end()) continue;
            int cnt=3;
            vi a(n+1,0), b(n+1,0);
            for (int k=1;k<=n;++k){
                if (k==i) {a[k]=b[k]=1; continue;}
                if (k==j) {a[k]=2; b[k]=1; continue;}
                a[k]=b[k]=cnt; cnt++;
            }
            rep1(k,n) cout<<a[k]<<" ";
            cout<<"\n";
            rep1(k,n) cout<<b[k]<<" ";
            cout<<"\n";
            return 0;
        }
    }
    return 0;
}