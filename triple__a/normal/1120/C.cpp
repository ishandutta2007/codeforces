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
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
// const int mod=998244353;
const int INF=LLONG_MAX;
const double EPS=1e-9;
const int N=5007;
const int K=19;
mt19937 rng(1234);

const int mod[2]={998244353,234567899};
const int base[2]={12321,32123};
int n,a,b;
string s;
int dp[N],fst[N][N];
int hsh[2][N],f[2][N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    cin>>n>>a>>b>>s;
    f[0][0]=f[1][0]=1;
    rep(_,2) rep1(i,n) f[_][i]=f[_][i-1]*base[_]%mod[_];
    rep(_,2) rep1(i,n) hsh[_][i]=(hsh[_][i-1]*base[_]+s[i-1])%mod[_];
    auto get_hsh=[&](int l,int r){
        int ret[2]={0,0};
        rep(_,2) ret[_]=(hsh[_][r]-hsh[_][l]*f[_][r-l]%mod[_]+mod[_])%mod[_];
        return ret[0]*mod[1]+ret[1]; 
    };
    for (int i=1;i<=n;++i){
        unordered_map<int,int> idx;
        for (int j=0;i+j<=n;++j){
            auto aaa=get_hsh(j,i+j);
            if (idx.find(aaa)!=idx.end()) fst[i][j]=idx[aaa];
            else fst[i][j]=j, idx[aaa]=j;
            // cerr<<j<<" "<<i+j<<" "<<fst[i][j]<<" "<<aaa<<endl;
        }
    }
    for (int i=1;i<=n;++i){
        dp[i]=a+dp[i-1];
        for (int j=0;j<i;++j){
            if (fst[i-j][j]+i-j<=j) dp[i]=min(dp[i],dp[j]+b);
        }
    }
    cout<<dp[n];
    return 0;
}

/*
3
3 3
3 1 5
7 5
5 5 5 4 1 2 1
2 10
3 3
*/