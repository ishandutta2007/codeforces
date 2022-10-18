#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<LL,int>
#define iii pair<int,ii>
#define eb  emplace_back
#define TASK "DP_C7"
using namespace std;
const int maxn = 3e5 + 5;
int n,x,a[maxn];
LL  F[maxn][5];
///--------------------------
void    readf(){
    cin >> n >> x;
    for(int i = 1;i <= n; ++i) cin >> a[i];
}
///--------------------------
void    solve(){
    LL ans = 0;
    for(int i = 1 ; i <= n; ++i){
        F[i][1] = max(F[i - 1][1],0LL)+a[i];
        F[i][2] = max(0LL,max(F[i-1][1],F[i - 1][2])) + 1LL * x * a[i];
        F[i][3] = max(0LL,max(F[i-1][2],F[i - 1][3]))  + a[i];
        ans = max(max(ans,F[i][3]),max(F[i][1],F[i][2]));
    }
    cout << ans << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifdef TLH2203
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // TLH2203
    readf();
    solve();
}