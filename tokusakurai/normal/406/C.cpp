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

template<bool directed = false>
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

    void solve(){
        vector<int> d(n, -1), p(n, -1);
        vector<vector<int>> rs(n), ch(n); //
        queue<int> que;
        vector<bool> used_e(m, false);
        que.emplace(0), d[0] = 0;
        
        while(!empty(que)){
            int i = que.front(); que.pop();
            each(e, es[i]){
                if(d[e.to] == -1){
                    d[e.to] = d[i]+1, p[e.to] = i;
                    que.emplace(e.to);
                    ch[i].eb(e.to);
                    used_e[e.id] = true;
                }
                else if(d[i] >= d[e.to] && !used_e[e.id]){
                    rs[i].eb(e.to);
                    used_e[e.id] = true;
                }
            }
        }
        
        vector<vector<int>> id1(n), id2(n);
        vector<int> used(n, 0);
        vector<int> ptr(n, 0);
        
        rep(i, n){
            while(sz(rs[i]) >= 2){
                int u = rs[i].back(); rs[i].pop_back();
                int v = rs[i].back(); rs[i].pop_back();
                cout << u+1 << ' ' << i+1 << ' ' << v+1 << '\n';
            }
            
            (empty(rs[i])? id2 : id1)[d[i]].eb(i);
        }
        
        rep3(i, n-1, 1){
            each(e, id1[i]){
                if(used[e] != 0) continue;
                cout << p[e]+1 << ' ' << e+1 << ' ' << rs[e][0]+1 << '\n';
                used[e] = 1;
            }

            each(e, id2[i]){
                if(used[e] == 1) continue;
                int u = p[e];
                used[e] = 1;
                while((ptr[u] < sz(ch[u])) && used[ch[u][ptr[u]]] == 1){
                    ptr[u]++;
                }
                
                if(ptr[u] < sz(ch[u])){
                    cout << e+1 << ' ' << u+1 << ' ' << ch[u][ptr[u]]+1 << '\n';
                    used[ch[u][ptr[u]]] = 1;
                    ptr[u]++;
                }
                else{
                    if(empty(rs[u])){
                        cout << e+1 << ' ' << u+1 << ' ' << p[u]+1 << '\n';
                        used[u] = 1;
                    }
                    else{
                        cout << e+1 << ' ' << u+1 << ' ' << rs[u][0]+1 << '\n';
                        rs[u].pop_back();
                        used[u] = 2;
                        id2[d[u]].eb(u);
                    }
                }
            }
        }
        
    }
};

int main(){
    int N, M; cin >> N >> M;

    Graph G(N);
    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    if(M&1) {cout << "No solution\n";}
    else G.solve();
}