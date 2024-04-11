#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template<typename T>
struct Max_Flow{
    struct edge{
        int to; T cap; int rev;
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> es;
    vector<bool> used;
    const T INF_T;
    const int n;

    Max_Flow(int n) : INF_T(numeric_limits<T>::max()), n(n){
        es.resize(n), used.resize(n);
    }

    void add_edge(int from, int to, T cap, bool directed = true){
        es[from].eb(to, cap, sz(es[to]));
        es[to].eb(from, directed? 0 : cap, sz(es[from])-1);
    }

    T dfs(int now, int t, T flow){
        if(now == t) return flow;
        used[now] = true;
        each(e, es[now]){
            if(!used[e.to] && e.cap > 0){
                T f = dfs(e.to, t, min(flow, e.cap));
                if(f > 0){
                    e.cap -= f;
                    es[e.to][e.rev].cap += f;
                    return f;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t){
        T flow = 0;
        for(;;){
            fill(all(used), false);
            T f = dfs(s, t, INF_T);
            if(f == 0) return flow;
            flow += f;
        }
    }

    void dfs2(int now){
        used[now] = true;
        each(e, es[now]){
            if(e.cap == 0 || used[e.to]) continue;
            dfs2(e. to);
        }
    }
};

int main(){
    int N, M; cin >> N >> M;

    Max_Flow<ll> G(20*N+2);
    int s = 20*N, t = s+1;
    rep(i, N){
        G.add_edge(s, 20*i, INF, true);
        rep2(j, 0, 18) G.add_edge(20*i+j+1, 20*i+j, INF, true);
        G.add_edge(20*i+19, t, INF, true);
    }

    vector<ll> w(N, 0);
    rep(i, M){
        int u, v; ll c; cin >> u >> v >> c; u--, v--;
        w[u] += c, w[v] -= c;
        rep2(j, 0, 18) G.add_edge(20*v+j, 20*u+j+1, INF, true);
    }

    rep(i, N){
        if(w[i] >= 0){
            rep(j, 20){
                G.add_edge(20*i+j, t, w[i], true);
            }
        }
        else{
            rep(j, 20){
                G.add_edge(s, 20*i+j, -w[i], true);
            }
        }
    }

    G.max_flow(s, t);
    fill(all(G.used), false);
    G.dfs2(s);

    vector<int> ans(N, 0);
    rep(i, N){
        rep(j, 20){
            if(G.used[20*i+j]) ans[i] = j;
        }
    }

    rep(i, N) cout << ans[i] << ' '; cout << '\n';
}