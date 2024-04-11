// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("unroll-loops")
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
 
 
const int maxn=57;
const int mod=998244353;
const double pi=3.1415926535;
int n,k;
int a[maxn][maxn],s[maxn];
int mask[maxn][maxn],ans[maxn];

void dfs(int U,int cur,int dep){
    if (dep==k){
        if (U<ans[n]||(cur!=ans[__builtin_popcountll(cur)])){
            cout<<"REJECTED";
            exit(0);
        }
        return;
    }
    int empt=s[dep]-__builtin_popcountll(mask[dep][s[dep]]&U), occ=__builtin_popcountll(mask[dep][s[dep]]&cur);
    U|=mask[dep][s[dep]];
    int tmp=(cur|mask[dep][s[dep]])^(mask[dep][s[dep]]);
    for (int i=occ;i<=occ+empt;++i){
        dfs(U,tmp|mask[dep][i],dep+1);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(15), cerr.precision(10);
    cin>>n>>k;
    if (n==1){cout<<"ACCEPTED"; return 0;}
    rep(i,k){
        cin>>s[i];
        rep1(j,s[i]) cin>>a[i][j], a[i][j]--, mask[i][j]=mask[i][j-1]|(1ll<<a[i][j]);
    }
    rep1(i,n) ans[i]=ans[i-1]|(1ll<<i-1);
    dfs(0,0,0);
    cout<<"ACCEPTED";
    return 0;
}

//AACAB
//ABACA

//1 2 3 4 5 6 7 8 9 10
//1 2 3 4 5 6 5 4 3 2
//