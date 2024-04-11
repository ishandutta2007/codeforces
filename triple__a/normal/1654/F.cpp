// incorrect attempt :( so painful to write the correct sol.

// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
// #define int long long
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
const int N=100007;
const int K=18;
mt19937 rng(1234);
int n;
string s;
int a[K+1][1<<K];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>s;
    rep(i,1<<n) a[0][i]=s[i]-'a';
    for (int i=1;i<=n;++i){
        vector<pii> ret; 
        vi b(1<<n);
        rep(j,1<<n) b[j]=j;
        rep(j,1<<n) ret.pb({a[i-1][j],a[i-1][j^(1<<i-1)]});
        sort(range(b),[&](int u,int v){return ret[u]<ret[v];});
        int cnt=0;
        pair<int,int> cur=ret[b[0]];
        rep(j,1<<n){
            if (ret[b[j]]!=cur) cnt++, cur=ret[b[j]];
            a[i][b[j]]=cnt; 
        }
    }
    int idx=-1;
    rep(i,1<<n) if (!a[n][i]) idx=i;
    // rep(i,1<<n) cerr<<a[n][i]<<" ";
    rep(i,1<<n) cout<<s[i^idx];
    return 0;
}


/*

*/