// ./e-egor-in-the-republic-of-dagestan.yml
#include "bits/stdc++.h"
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
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct Ed {
    int v; bool c;
};

const int MN = 5e5 + 1;
int N, M;
vector<Ed> g[MN];

// bfs stuff
deque<int> dq;
int dis[MN][2];
// Ed par[MN];
bool ans[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> (N) >> (M);
    for (auto i = 0; i < M; i++) {
        int a, b; bool c;
        cin >> a >> b >> c;
        // g[a].pb({b, c});
        g[b].pb({a, c});
    }

    memset(dis, -1, sizeof dis);
    dis[N][0] = dis[N][1] = 0; dq.pb(N); //par[N] = {-1, 0};

    while (!dq.empty()) {
        int c = dq.front(), cdis = max(dis[c][0], dis[c][1]); dq.pop_front();
        // cout<<"c="<<(c)<<", "; cout<<"cdis="<<(cdis)<<", "; cout << endl; // db c,cdis

        for (auto to : g[c]) {
            // cout<<"to.v="<<(to.v)<<", "; cout<<"to.c="<<(to.c)<<", "; cout<<"dis[to.v][to.c]="<<(dis[to.v][to.c])<<", "; cout << endl; // db to.v,to.c,dis[to.v][to.c]
            if (dis[to.v][to.c] == -1) {
                dis[to.v][to.c] = cdis + 1;
                // cout<<"[to]: "; cout<<"c="<<(c)<<", "; cout<<"to.v="<<(to.v)<<", "; cout<<"to.c="<<(to.c)<<", "; cout << endl; // db l:to,c,to.v,to.c
                if (dis[to.v][!to.c] != -1) {
                    // cout<<"[add]: "; cout << endl; // db l:add
                    dq.pb(to.v);
                    // par[to.v] = {c, to.c};
                }
                else {
                    // cout<<"[flans]: "; cout << endl; // db l:flans
                    ans[to.v] = !to.c;
                }
            }
        }
    }

    int ansDis = dis[1][0] == -1 || dis[1][1] == -1 ? -1 : max(dis[1][0], dis[1][1]);
    cout << (ansDis) << '\n';
    for (auto i = 1; i <= N; i++) cout << ans[i];
    cout << '\n';

    return 0;
}