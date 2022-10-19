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

template<bool directed = true>
struct Graph{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    Graph(int n) : es(n), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }
};

template<bool directed = true>
struct Strongly_Connected_Components{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es, rs;
    vector<int> vs, comp;
    vector<bool> used;
    const int n;
    int m;

    Strongly_Connected_Components(int n) : es(n), rs(n), vs(n), comp(n), used(n), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m), rs[to].emplace_back(from, m);
        if(!directed) es[to].emplace_back(from, m), rs[from].emplace_back(to, m);
        m++;
    }

    void topological_sort(int now){
        used[now] = true;
        for(auto &e: es[now]){
            if(!used[e.to]) topological_sort(e.to);
        }
        vs.push_back(now);
    }

    void track_back(int now, int cnt){
        used[now] = true, comp[now] = cnt;
        for(auto &e: rs[now]){
            if(!used[e.to]) track_back(e.to, cnt);
        }
    }

    Graph<true> decompose(){
        fill(begin(used), end(used), false);
        for(int i = 0; i < n; i++){
            if(!used[i]) topological_sort(i);
        }
        fill(begin(used), end(used), false), reverse(begin(vs), end(vs));
        int cnt = 0;
        for(auto &e: vs){
            if(!used[e]) track_back(e, cnt++);
        }
        Graph<true> G(cnt);
        for(int i = 0; i < n; i++){
            for(auto &e: es[i]){
                int u = comp[i], v = comp[e.to];
                if(u != v) G.add_edge(u, v);
            }
        }
        return G;
    }

    int operator [] (int k) const {return comp[k];}
};

int main(){
    int N, M, K; cin >> N >> M >> K;

    int pw = 1;
    rep(i, K) pw *= 27;

    vector<int> id(pw, -1);
    rep(i, N){
        string S; cin >> S;
        int s = 0;
        each(e, S){
            s *= 27;
            if(e == '_') s += 26;
            else s += (e-'a');
        }
        id[s] = i;
    }

    Strongly_Connected_Components scc(N);

    bool flag = true;

    rep(i, M){
        string S; cin >> S;
        vector<int> s = {0};
        each(e, S){
            vector<int> t;
            each(u, s) t.eb(u*27+26), t.eb(u*27+(e-'a'));
            swap(s, t);
        }

        int x; cin >> x; x--;

        bool ng = true;
        each(e, s){
            if(id[e] == -1) continue;
            if(id[e] == x) ng = false;
            else scc.add_edge(x, id[e]);
        }

        if(ng) flag = false;
    }

    if(!flag || scc.decompose().n < N) cout << "NO\n";
    else{
        cout << "YES\n";
        vector<int> ord(pw);
        rep(i, N) ord[scc[i]] = i;
        rep(i, N){
            cout << ord[i]+1;
            cout << (i == N-1? '\n' : ' ');
        }
    }
}