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
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;
const int mod = (int)1e9 + 7;

int n, m;
int p[N];
vector<int> gr[N];
int col[N];
ll ans = 1;

int get(int v){
    return v == p[v] ? v : p[v] = get(p[v]);
}

void unite(int v, int u){
    v = get(v);
    u = get(u);
    p[v] = u;
}

void dfs(int v, int c = 0){
    col[v] = c;
    for(auto u: gr[v]){
        if(col[u] == col[v]){
            printf("0\n");
            exit(0);
        }
        if(col[u] == -1)
            dfs(u, c^1);
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    iota(p, p + n, 0);
    vector<pii> neg;
    for(int i = 0; i < m; i++){
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c);
        --v; --u;
        if(c){
            unite(v, u);
        }
        else
            neg.emplace_back(v, u);
    }
    vector<int> kek(n);
    for(int i = 0; i < n; i++)
        kek[i] = get(i);
    sort(all(kek));
    kek.erase(unique(all(kek)), kek.end());
    for(auto e: neg){
        int v, u;
        tie(v, u) = e;
        v = lower_bound(all(kek), get(v)) - kek.begin();
        u = lower_bound(all(kek), get(u)) - kek.begin();
        if(v == u){
            printf("0\n");
            return;
        }
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    fill(col, col + kek.size(), -1);
    for(int i = 0; i < (int)kek.size(); i++){
        if(col[i] == -1){
            dfs(i);
            ans = ans*2%mod;
        }
    }
    if(ans%2 == 0)
        ans /= 2;
    else
        ans = (ans + mod)/2;
    printf("%lld\n", ans);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}