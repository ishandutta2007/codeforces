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

const int N = 1505;
const int mod = 998244353;

inline int mul(int x, int y){
    return x * 1ll * y % mod;
}

struct edge{
    int v, u, w;
    edge(int _v, int _u, int _w):v(_v), u(_u), w(_w){}
    bool operator < (const edge & e)const{
        return w < e.w;
    }
};

struct component{
    vector<int> dp;
    int nodes;
    int edges;
};

component c[N];
int p[N];

int get(int v){
    return v == p[v] ? v : p[v] = get(p[v]);
}

inline void check_clique(int v){
    if(c[v].nodes * (c[v].nodes - 1)/2 == c[v].edges){
        ++c[v].dp[1];
        if(c[v].dp[1] == mod)
            c[v].dp[1] = 0;
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    vector<edge> e;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            scanf("%d", &x);
            if(i < j)
                e.emplace_back(i, j, x);
        }
    }
    iota(p, p + n, 0);
    for(int i = 0; i < n; i++){
        c[i] = component{{0, 1}, 1, 0};
    }
    sort(all(e));
    for(auto curr: e){
        int v = curr.v, u = curr.u;
        v = get(v); u = get(u);
        if(v == u){
            ++c[v].edges;
            check_clique(v);
        }
        else{
            if(c[v].nodes < c[u].nodes)
                swap(v, u);
            p[u] = v;
            c[v].nodes += c[u].nodes;
            c[v].edges += c[u].edges + 1;
            vector<int> dp(c[v].dp.size() + c[u].dp.size() - 1, 0);
            auto& L = c[v].dp;
            auto& R = c[u].dp;
            for(int sl = 1; sl < L.size(); sl++){
                for(int sr = 1; sr < R.size(); sr++){
                    int curr = mul(L[sl], R[sr]);
                    dp[sl + sr] += curr;
                    dp[sl + sr] -= dp[sl + sr] >= mod ? mod : 0;
                }
            }
            c[v].dp.swap(dp);
            check_clique(v);
        }
    }
    int fin = get(0);
    for(int i = 1; i <= n; i++)
        printf("%d ", c[fin].dp[i]);
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