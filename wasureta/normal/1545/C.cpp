// ./c-aquamoon-and-permutations.yml
#include <bits/stdc++.h>
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
#if __cplusplus == 201703L // CPP17 only things
template <typename T> using opt_ref = optional<reference_wrapper<T>>; // for some templates
#endif
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
#ifdef __GNUG__
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
#endif
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct blossom {
    int n, m;
    vector<int> mate;
    vector<vector<int>> b;
    vector<int> p, d, bl;
    vector<vector<int>> g;
    blossom(int n) : n(n) {
        m = n + n / 2;
        mate.assign(n, -1);
        b.resize(m);
        p.resize(m);
        d.resize(m);
        bl.resize(m);
        g.assign(m, vector<int>(m, -1));
    }
    void add_edge(int u, int v) {
        g[u][v] = u;
        g[v][u] = v;
    }
    void match(int u, int v) {
        g[u][v] = g[v][u] = -1;
        mate[u] = v;
        mate[v] = u;
    }
    vector<int> trace(int x) {
        vector<int> vx;
        while(true) {
            while(bl[x] != x) x = bl[x];
            if(!vx.empty() && vx.back() == x) break;
            vx.push_back(x);
            x = p[x];
        }
        return vx;
    }
    void contract(int c, int x, int y, vector<int> &vx, vector<int> &vy) {
        b[c].clear();
        int r = vx.back();
        while(!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
            r = vx.back();
            vx.pop_back();
            vy.pop_back();
        }
        b[c].push_back(r);
        b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
        b[c].insert(b[c].end(), vy.begin(), vy.end());
        for(int i = 0; i <= c; i++) {
            g[c][i] = g[i][c] = -1;
        }
        for(int z : b[c]) {
            bl[z] = c;
            for(int i = 0; i < c; i++) {
                if(g[z][i] != -1) {
                    g[c][i] = z;
                    g[i][c] = g[i][z];
                }
            }
        }
    }
    vector<int> lift(vector<int> &vx) {
        vector<int> A;
        while(vx.size() >= 2) {
            int z = vx.back(); vx.pop_back();
            if(z < n) {
                A.push_back(z);
                continue;
            }
            int w = vx.back();
            int i = (A.size() % 2 == 0 ? find(b[z].begin(), b[z].end(), g[z][w]) - b[z].begin() : 0);
            int j = (A.size() % 2 == 1 ? find(b[z].begin(), b[z].end(), g[z][A.back()]) - b[z].begin() : 0);
            int k = b[z].size();
            int dif = (A.size() % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
            while(i != j) {
                vx.push_back(b[z][i]);
                i = (i + dif) % k;
            }
            vx.push_back(b[z][i]);
        }
        return A;
    }
    int solve() {
        for(int ans = 0; ; ans++) {
            fill(d.begin(), d.end(), 0);
            queue<int> Q;
            for(int i = 0; i < m; i++) bl[i] = i;
            for(int i = 0; i < n; i++) {
                if(mate[i] == -1) {
                    Q.push(i);
                    p[i] = i;
                    d[i] = 1;
                }
            }
            int c = n;

            bool aug = false;
            while(!Q.empty() && !aug) {
                int x = Q.front(); Q.pop();
                if(bl[x] != x) continue;
                for(int y = 0; y < c; y++) {
                    if(bl[y] == y && g[x][y] != -1) {
                        if(d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.push(mate[y]);
                        }else if(d[y] == 1) {
                            vector<int> vx = trace(x);
                            vector<int> vy = trace(y);
                            if(vx.back() == vy.back()) {
                                contract(c, x, y, vx, vy);
                                Q.push(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            }else {
                                aug = true;
                                vx.insert(vx.begin(), y);
                                vy.insert(vy.begin(), x);
                                vector<int> A = lift(vx);
                                vector<int> B = lift(vy);
                                A.insert(A.end(), B.rbegin(), B.rend());
                                for(int i = 0; i < (int) A.size(); i += 2) {
                                    match(A[i], A[i + 1]);
                                    if(i + 2 < (int) A.size()) add_edge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if(!aug) return ans;
        }
    }
};

struct TwoSat {
    int N, cord, ccomp;
    vector<int> ord, low, instk, stk, comp;
    vector<vector<int>> g;
    void init(int N0) {
        N = N0; cord = ccomp = 0;
        g.assign(N*2+1, vector<int>());
        ord.assign(N*2+1, 0);
        low.assign(N*2+1, 0);
        instk.assign(N*2+1, 0);
        comp.assign(N*2+1, 0);
        stk.clear();
    }
    void addEdge(int a, int b) {
        // cout << (a) << ' ' << (b) << '\n';
        if (a < 0) a = N-a;
        if (b < 0) b = N-b;
        g[a].push_back(b);
    }
    void addOr(int a, int b) {
        addEdge(-a, b);
        addEdge(-b, a);
    }
    void tarjan(int c) {
        ord[c] = low[c] = ++cord;
        instk[c] = true; stk.push_back(c);
        for (auto to : g[c]) {
            if (!ord[to]) {
                tarjan(to);
                low[c] = min(low[c], low[to]);
            }
            else if (instk[to])
                low[c] = min(low[c], ord[to]);
        }

        if (low[c] == ord[c]) {
            int u, cc = ++ccomp;
            do {
                u = stk.back(); stk.pop_back(); instk[u] = false;
                comp[u] = cc;
            } while (u != c);
        }
    }
    vector<int> solve() {
        for (auto i = 1; i <= 2*N; i++)
            if (!ord[i])
                tarjan(i);
        for (auto i = 1; i <= N; i++)
            if (comp[i] == comp[i+N]) {
                // cout<<"[same]: "; cout<<"i="<<(i)<<", "; cout << endl; // db l:same,i
                return vector<int>(N+1, -1);
            }
        vector<int> res(N+1);
        for (auto i = 1; i <= N; i++)
            res[i] = comp[i] < comp[i+N]; // 1 > 0
        return res;
    }
};

const ll MOD = 998244353;
const int MN = 501;
int N,
    A[MN*2][MN];
bool es[MN*2][MN*2];
TwoSat sat;

void solve() {
    cin >> N;

    for (auto i = 1; i <= 2*N; i++)
        for (auto j = 1; j <= N; j++)
            cin >> A[i][j];

    memset(es, 0, sizeof es);

    blossom bl(2*N+1);
    for (auto i = 1; i <= 2*N; i++) {
        for (auto j = i+1; j <= 2*N; j++) {
            int ok = 1;
            for (auto k = 1; k <= N; k++)
                ok &= A[i][k] != A[j][k];
            if (!ok) {
                es[i][j] = es[j][i] = true;
                bl.add_edge(i-1, j-1);
                // cout << (i) << ' ' << (j) << '\n';
            }
        }
    }
    int t = bl.solve();
    // cout<<"t="<<(t)<<", "; cout << endl; // db t
    assert(t == N);

    vector<int> A, B, flip(N);
    for (auto i = 1; i <= 2*N; i++) {
        if (bl.mate[i-1] > i-1) {
            A.pb(i);
            B.pb(bl.mate[i-1]+1);
        }
    }

    auto buildGraph = [&] {
        sat.init(2*N);
        for (auto i = 1; i <= 2*N; i++) {
            for (auto j = i+1; j <= 2*N; j++) {
                if (es[i][j]) {
                    sat.addEdge(i, -j);
                    sat.addEdge(j, -i);
                }
            }
        }
        for (auto i = 0; i < N; i++) {
            // cout<<"[OR]: "; cout<<"A[i]="<<(A[i])<<", "; cout<<"B[i]="<<(B[i])<<", "; cout << endl; // db l:OR,A[i],B[i]
            sat.addOr(A[i], B[i]);
        }
    };

    buildGraph();
    auto sol = sat.solve();
    // cout << "sol=["; for (auto __x:sol)cout<<__x<<", "; cout<<"], "; cout << endl; // db I:sol
    assert(sol[0] != -1);
    for (auto i = 0; i < N; i++) {
        if (!sol[A[i]]) {
            assert(sol[B[i]]);
            swap(A[i], B[i]);
        }
    }

    vector<bool> done(N);
    ll ans = 1;
    for (auto i = 0; i < N; i++) {
        if (!done[i]) {
            buildGraph();
            sat.addOr(B[i], B[i]);

            // cout<<"[testing]: "; cout<<"i="<<(i)<<", "; cout<<"A[i]="<<(A[i])<<", "; cout<<"B[i]="<<(B[i])<<", "; cout << endl; // db l:testing,i,A[i],B[i]

            auto csol = sat.solve();
            if (csol[0] != -1) {
                for (auto j = 0; j < N; j++) {
                    // cout<<"j="<<(j)<<", "; cout<<"A[j]="<<(A[j])<<", "; cout<<"B[j]="<<(B[j])<<", "; cout<<"sol[A[j]]="<<(sol[A[j]])<<", "; cout<<"sol[B[j]]="<<(sol[B[j]])<<", "; cout << endl; // db j,A[j],B[j],sol[A[j]],sol[B[j]]
                    if (!csol[A[j]]) {
                        done[j] = true;
                        assert(csol[B[j]]);
                    }
                }

                ans = ans * 2 % MOD;
                assert(done[i]);
            }
            else done[i] = true;
        }
    }

    cout << (ans) << '\n';
    for (auto i = 0; i < N; i++) {
        cout << A[i] << " \n"[i == N-1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}