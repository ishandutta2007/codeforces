#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
    T, __gnu_pbds::null_type, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;
 
struct range_query {
    long long left, right, cost;
    int query_id;
};

long long safe_mul(long long a, long long b) {
    if (a > LLONG_MAX / b) return LLONG_MAX;
    return a * b;
}
 
const int N = 200001, K = 27;
 
long long pass[K], fine[K], time_gap;
vector<pair<int, long long>> adj[N];
int zone[N];

long long dist[N];
int jump[N];
 
void dfs_dist(int u, int p = 0) {
    for (auto [c, w] : adj[u]) {
        if (c != p) {
            dist[c] = dist[u] + w;
            jump[c] = zone[u] == zone[c] ? jump[u] : u;
            dfs_dist(c, u);
        }
    }
}
 
ordered_set<pair<long long, int>> zone_dists[K];
vector<range_query> range_queries[N];
long long ans[N];
 
void dfs_check(int u, int p = 0) {
    vector<int> results(size(range_queries[u]));
    for (int i = 0; i < ssize(range_queries[u]); ++i) {
        auto &query = range_queries[u][i];
        results[i] = (int) (zone_dists[zone[u]].order_of_key({query.left, 0}) -
                    zone_dists[zone[u]].order_of_key({query.right, 0}));
    }

    zone_dists[zone[u]].insert({dist[u] % time_gap, u});
 
    for (auto [c, w] : adj[u]) {
        if (c != p) dfs_check(c, u);
    }
 
    for (int i = 0; i < ssize(range_queries[u]); ++i) {
        auto &query = range_queries[u][i];
        results[i] += (int) (zone_dists[zone[u]].order_of_key({query.right, 0}) -
                    zone_dists[zone[u]].order_of_key({query.left, 0}));
        if (results[i] > 0) ans[query.query_id] = min(ans[query.query_id], query.cost);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n; cin >> n;
 
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w; cin >> u >> v >> w;
 
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
 
    int k; cin >> k;
    string z; cin >> z;
 
    for (int i = 2; i <= n; ++i) {
        zone[i] = z[i - 1] - 'A' + 1;
    }
 
    dfs_dist(1);
 
    for (int i = 1; i <= k; ++i) cin >> pass[i];
    for (int i = 1; i <= k; ++i) cin >> fine[i];
 
    cin >> time_gap;
 
    int q; cin >> q;
    for (int query_id = 0; query_id < q; ++query_id) {
        int type; cin >> type;
 
        if (type == 1) {
            char i; cin >> i;
            cin >> pass[i - 'A' + 1];
 
            ans[query_id] = -1;
        } else if (type == 2) {
            char i; cin >> i;
            cin >> fine[i - 'A' + 1];
            
            ans[query_id] = -1;
        } else {
            int u; cin >> u;

            map<long long, long long> sum_costs = {{0, 0}, {time_gap, 0}};
            for (int v = jump[u]; v > 1; v = jump[v]) {
                long long upper = dist[jump[v]], lower = dist[v];
 
                long long cost1 = min(safe_mul((lower - upper) / time_gap, fine[zone[v]]), pass[zone[v]]);
                long long cost2 = min(safe_mul((lower - upper + time_gap - 1) / time_gap, fine[zone[v]]), pass[zone[v]]);
 
                if (upper % time_gap < lower % time_gap) sum_costs[0] += cost1, sum_costs[time_gap] -= cost1;
                else sum_costs[0] += cost2, sum_costs[time_gap] -= cost2;
 
                sum_costs[upper % time_gap + 1] += cost2 - cost1;
                sum_costs[lower % time_gap + 1] += cost1 - cost2;
            }
 
            long long cost = 0;
            auto it = sum_costs.begin();
            while (it != --sum_costs.end()) {
                cost += it->second;
                long long left = it->first, right = (++it)->first;
                range_queries[u].push_back({left, right, cost, query_id});
            }
 
            ans[query_id] = LLONG_MAX;
        }
    }
 
    dfs_check(1);
 
    for (int i = 0; i < q; ++i) {
        if (ans[i] != -1) cout << ans[i] << "\n";
    }
}