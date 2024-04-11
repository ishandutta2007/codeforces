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
};

int main(){
    int N;
    cin >> N;

    Max_Flow<ll> G(N+2);
    int s = N, t = N+1;

    vector<int> a(N);
    vector<vector<int>> ids(101);
    rep(i, N){
        cin >> a[i];
        ids[a[i]].eb(i);
    }

    rep(i, N){
        rep2(j, 1, a[i]){
            if(a[i]%j == 0){
                auto it = lower_bound(all(ids[j]), i);
                if(it != ids[j].begin()){
                    G.add_edge(i, *(--it), INF, true);
                }
            }
        }
    }

    ll S = 0;
    rep(i, N){
        ll w = 0;
        cin >> w;
        if(w >= 0){
            S += w;
            G.add_edge(s, i, w, true);
        }
        else{
            G.add_edge(i, t, -w, true);
        }
    }

    cout << S-G.max_flow(s, t) << '\n';
}