//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)1e3 + 3;

int n, m;
int col[N];
int d[N];
vector<int> gr[N];
vector<int> comp[N];
int cid = 0;

bool dfs(int v, int c = 0){
    col[v] = c;
    comp[cid].push_back(v);
    for(auto u: gr[v]){
        if(col[u] == col[v])
            return 0;
        if(col[u] != -1)
            continue;
        if(!dfs(u, c^1))
            return 0;
    }
    return 1;
}

int qu[2*N];
int qh = 0, qt = 0;

int diam(int v){
    fill(d, d + n, -1);
    d[v] = 0;
    qh = qt = 0;
    qu[qt++] = v;
    int ans = 0;
    while(qh < qt){
        int u = qu[qh++];
        ans = max(ans, d[u]);
        for(auto u1: gr[u]){
            if(d[u1] == -1){
                d[u1] = d[u] + 1;
                qu[qt++] = u1;
            }
        }
    }
    return ans;
}

void solve(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int v, u;
        scanf("%d%d", &v, &u);
        --v; --u;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    fill(col, col + n, -1);
    for(int i = 0; i < n; i++){
        if(col[i] == -1){
            if(!dfs(i)){
                printf("-1\n");
                return;
            }
            ++cid;
        }
    }
    int ans = 0;
    for(int i = 0; i < cid; i++){
        int d = 0;
        for(auto v: comp[i]){
            d = max(d, diam(v));
        }
        ans += d;
    }
    printf("%d\n", ans);
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}