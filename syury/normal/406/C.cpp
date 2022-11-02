//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;

int V[N], U[N];
int n, m;
int deg[N], p[N];
int depth[N];
vector<int> gr[N];
set<int> children[N];
bool dead[N], used[N];
set<pii, greater<pii> > q;

inline int get(int v, int i){
    return V[i] == v ? U[i] : V[i];
}

void dfs(int v, int pr = -1){
    used[v] = 1;
    p[v] = pr;
    depth[v] = pr == -1 ? 0 : (1 + depth[pr]);
    bool is_leaf = 1;
    for(int e: gr[v]){
        int u = get(v, e);
        if(used[u])
            continue;
        is_leaf = 0;
        dead[e] = 1;
        children[v].insert(u);
        dfs(u, v);
    }
    if(is_leaf)
        q.emplace(depth[v], v);
}

inline void relink(int v){
    while(!gr[v].empty() && dead[gr[v].back()])
        gr[v].pop_back();
    if(gr[v].empty())
        return;
    int e = gr[v].back();
    int u = get(v, e);
    p[v] = u;
    //cerr << "relink " << v << " to " << u << endl;
    dead[e] = 1;
    children[u].insert(v);
    depth[v] = depth[u] + 1;
    q.emplace(depth[v], v);
}

void solve(){
    scanf("%d%d", &n, &m);
    if(m&1){
        printf("No solution\n");
        return;
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d", V + i, U + i);
        --V[i]; --U[i];
        gr[V[i]].push_back(i);
        gr[U[i]].push_back(i);
    }
    dfs(0);
    for(int i = 0; i < n; i++){
        vector<pii> cu;
        for(auto e: gr[i])
            cu.emplace_back(depth[get(i, e)], e);
        sort(all(cu));
        gr[i].clear();
        for(auto x: cu)
            gr[i].push_back(x.Y);
    }
    vector<tuple<int, int, int> > ans;
    while(!q.empty()){
        int v = q.begin()->second;
        //cerr << v << ' ' << q.begin()->first << endl;
        if(!v)
            break;
        q.erase(q.begin());
        int pr = p[v];
        //cerr << "pred " << p[v] << endl;
        if(children[pr].size() == 1u){
            int ppr = p[pr];
            children[ppr].erase(pr);
            children[pr].erase(v);
            ans.emplace_back(v, pr, ppr);
            relink(v);
            relink(pr);
            if(children[ppr].empty())
                q.emplace(depth[ppr], ppr);
        }
        else{
            auto it = children[pr].begin();
            if(*it == v)
                ++it;
            int u = *it;
            q.erase(make_pair(depth[u], u));
            ans.emplace_back(v, pr, u);
            children[pr].erase(v);
            children[pr].erase(u);
            relink(v);
            relink(u);
            if(children[pr].empty())
                q.emplace(depth[pr], pr);
        }
    }
    for(auto x: ans)
        printf("%d %d %d\n", get<0>(x) + 1, get<1>(x) + 1, get<2>(x) + 1);
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}