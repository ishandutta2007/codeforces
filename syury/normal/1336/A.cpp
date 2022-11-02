//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb emplace_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;

int n, k;
vector<int> gr[N];
int bal[N];

int dfs(int v, int p = -1, int h = 0){
    int chld = 0;
    I(u, gr[v]){
        if(u != p){
            chld += dfs(u, v, h + 1);
        }
    }
    bal[v] = h - chld;
    ret 1 + chld;
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d", &n, &k);
    F(i, 0, n - 1){
        int v, u;
        scanf("%d%d", &v, &u);
        --v; --u;
        gr[v].pb(u); gr[u].pb(v);
    }
    dfs(0);
    sort(bal, bal + n);
    reverse(bal, bal + n);
    ll ans = 0;
    F(i, 0, k)
        ans += bal[i];
    printf("%lld\n", ans);
    return 0;
}