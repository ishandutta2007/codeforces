#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

template<class T>
struct flow_network{
    int n;
    vector<vector<int>> adj;
    struct E{
        int from, to;
        T capacity, flow;
    };
    vector<E> edge;
    T flow = 0;
    flow_network(int n): n(n), adj(n){ }
    void clear_flow(){
        for(auto &e: edge) e.flow = 0;
        flow = 0;
    }
    int insert(int from, int to, T forward_cap, T backward_cap){
        int ind = (int)edge.size();
        adj[from].push_back(ind);
        edge.push_back({from, to, forward_cap, 0});
        adj[to].push_back(ind + 1);
        edge.push_back({to, from, backward_cap, 0});
        return ind;
    }
    void add_flow(int i, T f){
        edge[i].flow += f;
        edge[i ^ 1].flow -= f;
    }
};

// Requires flow_network
template<class T>
struct dinic_maximum_flow{
    static constexpr T eps = (T)1e-9, inf = numeric_limits<T>::max();
    flow_network<T> &F;
    dinic_maximum_flow(flow_network<T> &F): F(F), ptr(F.n), level(F.n), q(F.n){ }
    vector<int> ptr, level, q;
    bool bfs(int source, int sink){
        fill(level.begin(), level.end(), -1);
        q[0] = sink;
        level[sink] = 0;
        int beg = 0, end = 1;
        while(beg < end){
            int i = q[beg ++];
            for(auto ind: F.adj[i]){
                auto &e = F.edge[ind];
                auto &re = F.edge[ind ^ 1];
                if(re.capacity - re.flow > eps && level[e.to] == -1){
                    level[e.to] = level[i] + 1;
                    if(e.to == source) return true;
                    q[end ++] = e.to;
                }
            }
        }
        return false;
    }
    T dfs(int u, T w, int sink){
        if(u == sink) return w;
        int &j = ptr[u];
        while(j >= 0){
            int ind = F.adj[u][j];
            auto &e = F.edge[ind];
            if(e.capacity - e.flow > eps && level[e.to] == level[u] - 1){
                T flow = dfs(e.to, min(e.capacity - e.flow, w), sink);
                if(flow > eps){
                    F.add_flow(ind, flow);
                    return flow;
                }
            }
            -- j;
        }
        return 0;
    }
    // Find a maximum source-sink flow
    // O(V^2 E) ( O(E min(V^2/3, E^1/2)) for unit network )
    T maximum_flow(int source, int sink){
        while(bfs(source, sink)){
            for(auto i = 0; i < F.n; ++ i) ptr[i] = (int)F.adj[i].size() - 1;
            T sum = 0;
            while(true){
                T add = dfs(source, inf, sink);
                if(add <= eps) break;
                sum += add;
            }
            if(sum <= eps) break;
            F.flow += sum;
        }
        return F.flow;
    }
    // Find a minimum source-sink cut
    // O(V^2 E) ( O(E min(V^2/3, E^1/2)) for unit network )
    auto minimum_cut(int source, int sink){
        T cut_weight = maximum_flow(source, sink);
        vector<int> left, right;
        for(auto u = 0; u < F.n; ++ u) (!~level[u] ? left : right).push_back(u);
        return tuple{cut_weight, left, right};
    }
};

const int N = 1e3 + 5;

int n, m;
vi a;

int cntb;
map <int, int> mppb, mppc;
vpii b, c;

vpii vans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    For(i, 0, n){
        int x; cin >> x; a.emplace_back(x);
    }

    sort(bend(a));
    Fora(x, a){
        if (2 * x + 1 > m){
            cout << -1 << endl;
            return 0;
        }
        if (3 * x <= m){
            mppc[x]++;
        }
        else{
            mppb[x]++;
            cntb++;
        }
    }
    Fora(elem, mppb){
        b.emplace_back(elem);
    }
    Fora(elem, mppc){
        c.emplace_back(elem);
    }

    flow_network <int> g(2 + isz(b) + isz(c));
    int source = g.n - 2, sink = g.n - 1;
    For(i, 0, isz(b)){
        g.insert(source, i, b[i].se, 0);
    }
    For(i, 0, isz(b)){
        For(j, 0, isz(c)){
            if (b[i].fi % c[j].fi == 0 and 2 * b[i].fi + c[j].fi <= m){
                g.insert(i, isz(b) + j, N, 0);
            }
        }
    }
    For(j, 0, isz(c)){
        g.insert(isz(b) + j, sink, c[j].se, 0);
    }
    dinic_maximum_flow dg(g);
    int flow = dg.maximum_flow(source, sink);
    if (flow != cntb){
        cout << -1 << endl;
        return 0;
    }

    Fora(&edge, g.edge){
        if (0 <= edge.from and edge.from < isz(b) and isz(b) <= edge.to and edge.to < isz(b) + isz(c)){
            ForE(i, 1, edge.flow){
                vans.emplace_back(2 * b[edge.from].fi + c[edge.to - isz(b)].fi, b[edge.from].fi + c[edge.to - isz(b)].fi);
            }
            c[edge.to - isz(b)].se -= edge.flow;
        }
    }
    For(j, 0, isz(c)){
        while (c[j].se--){
            vans.emplace_back(3 * c[j].fi, 2 * c[j].fi);
        }
    }
    cout << isz(vans) << endl;
    Fora(elem, vans){
        cout << elem.fi << ' ' << elem.se << endl;
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/