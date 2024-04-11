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

struct Eulerian_Trail{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    vector<pii> list;
    vector<bool> used_e, used_v;
    vector<int> deg;
    int m;
    const int n;

    Eulerian_Trail(int n) : n(n){
        es.resize(n), used_v.resize(n), deg.resize(n);
        m = 0;
    }

    void add_edge(int from, int to, bool directed = false){
        list.eb(from, to);
        es[from].eb(to, m);
        if(directed) deg[from]++, deg[to]--;
        else es[to].eb(from, m), deg[from]++, deg[to]++;
        m++;
    }

    pii get_edge(int id) {return list[id];}

    vector<int> trace(int s){
        stack<edge> st;
        vector<int> ret;
        st.emplace(s, -1);
        while(!st.empty()){
            int now = st.top().to;
            used_v[now] = true;
            if(es[now].empty()){
                ret.eb(st.top().id);
                st.pop();
            }
            else{
                auto e = es[now].back();
                es[now].pop_back();
                if(used_e[e.id]) continue;
                used_e[e.id] = true, st.emplace(e);
            }
        }
        ret.pop_back();
        reverse(all(ret));
        return ret;
    }

    vector<vector<int>> eulerian_trail(bool directed = false){
        vector<vector<int>> ret;
        if(directed){
            each(e, deg) if(e != 0) return ret;
        }
        else{
            each(e, deg) if(e&1) return ret;
        }
        used_e.assign(m, false);
        rep(i, n){
            if(es[i].empty() || used_v[i]) continue;
            ret.eb(trace(i));
        }
        return ret;
    }
};

int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    int l = -1, r = 21; //[l,r)
    vector<int> A(N), B(N);
    vector<int> ans;

    while(r-l > 1){
        int m = (l+r)/2;
        rep(i, N){
            A[i] = a[i]&((1<<m)-1), B[i] = b[i]&((1<<m)-1);
        }
        Eulerian_Trail G(2*N+(1<<m));
        rep(i, N){
            G.add_edge(2*i, 2*i+1);
            G.add_edge(2*i, 2*N+A[i]), G.add_edge(2*i+1, 2*N+B[i]);
        }
        vector<vector<int>> loop = G.eulerian_trail();
        if(sz(loop) != 1) {r = m; continue;}
        int now = 0;
        vector<int> tmp;
        rep(i, sz(loop[0])){
            int u, v;
            tie(u, v) = G.get_edge(loop[0][i]);
            if(u != now) swap(u, v);
            now = v;
            if(now < 2*N) tmp.eb(now);
        }
        if((tmp.front()&~1) == (tmp.back()&~1)){
            tmp.eb(tmp.front());
            reverse(all(tmp));
            tmp.pop_back();
            reverse(all(tmp));
        }
        swap(ans, tmp), l = m;
    }

    cout << l << '\n';
    each(e, ans) cout << e+1 << ' '; cout << '\n';
}