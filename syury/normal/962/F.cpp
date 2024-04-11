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

const int N = (int)1e5 + 5;

int n, m, gt = 0;
int V[N], U[N];
int tin[N];
bool in_tree[N];
vector<int> tnext[N];
vector<int> gr[N];
int sum[N];
int add[N];
int up[N][20];
int mx[N][20];
bool fuck[N];
int dsu[N];

int dsu_get(int v){
    return v == dsu[v] ? v : dsu[v] = dsu_get(dsu[v]);
}

void unite(int v, int u){
    v = dsu_get(v);
    u = dsu_get(u);
    if(v != u)
        dsu[v] = u;
}

inline int nxt(int v, int e){
    return v == V[e] ? U[e] : V[e];
}

void dfs(int v, int pr = -1){
    tin[v] = gt++;
    up[v][0] = (pr == -1 ? v : pr);
    for(int i = 1; i < 20; i++)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for(auto e: gr[v]){
        int u = nxt(v, e);
        if(tin[u] != -1)
            continue;
        in_tree[e] = 1;
        tnext[v].push_back(e);
        dfs(u, v);
    }
}

int calc_sum(int v){
    int carry = 0;
    for(auto e: tnext[v]){
        sum[e] = -calc_sum(nxt(v, e));
        //cerr << v << ' ' << nxt(v, e) << ' ' << sum[e] << endl;
        carry -= sum[e];
    }
    carry += add[v];
    mx[v][0] = -carry;
    return carry;
}

void calc_sum2(int v){
    for(int i = 1; i < 20; i++)
        mx[v][i] = max(mx[v][i - 1], mx[up[v][i - 1]][i - 1]);
    for(auto e: tnext[v]){
        calc_sum2(nxt(v, e));
    }
}

inline int pathmax(int v, int u){
    int ans = 0;
    for(int i = 19; i >= 0; i--){
        if(tin[up[u][i]] > tin[v]){
            ans = max(ans, mx[u][i]);
            u = up[u][i];
        }
    }
    if(u != v)
        ans = max(ans, mx[u][0]);
    return ans;
}

int calc_bad(int v){
    int carry = 0;
    for(auto e: tnext[v]){
        int curr = calc_bad(nxt(v, e));
        if(curr)
            fuck[e] = 1;
        carry += curr;
    }
    carry += add[v];
    return carry;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    iota(dsu, dsu + n, 0);
    for(int i = 0; i < m; i++){
        cin >> V[i] >> U[i];
        --V[i]; --U[i];
        unite(V[i], U[i]);
        gr[V[i]].push_back(i);
        gr[U[i]].push_back(i);
    }
    set<int> gavno;
    for(int i = 0; i < n; i++)
        gavno.insert(dsu_get(i));
    int who = dsu_get(0);
    for(auto v: gavno){
        if(v == who)
            continue;
        V[m] = v;
        U[m] = who;
        gr[v].push_back(m);
        gr[who].push_back(m);
        ++m;
    }
    fill(tin, tin + N, -1);
    dfs(0);
    for(int i = 0; i < m; i++){
        if(!in_tree[i]){
            int v = V[i], u = U[i];
            if(tin[v] > tin[u])swap(v, u);
            ++add[v];
            --add[u];
        }
    }
    calc_sum(0);
    calc_sum2(0);
    memset(add, 0, sizeof(add));
    for(int i = 0; i < m; i++){
        if(!in_tree[i]){
            int v = V[i], u = U[i];
            if(tin[v] > tin[u])swap(v, u);
            int curr = pathmax(v, u);
            if(curr > 1){
                fuck[i] = 1;
                ++add[v];
                --add[u];
            }
        }
    }
    calc_bad(0);
    vector<int> ans;
    for(int i = 0; i < m; i++)
        if(!fuck[i] && (!in_tree[i] || sum[i] == 1))
            ans.push_back(i + 1);
    cout << ans.size() << endl;
    for(auto x: ans)
        cout << x << ' ';
    cout << endl;
    return 0;
}