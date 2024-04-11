#include <bits/stdc++.h>
#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define nl '\n'
#define ll long long
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

ll n, m, k;
const int mxN=3e5,M=1e9+7, inf=2e9;
ll a[mxN];


template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = __gnu_pbds::tree<
K, V, Comp,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>; // from ecnerwala's library

template <typename K, typename Comp = std::less<K>>
using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;


template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;


void solve(int test_case = 0) {
    cin >> k >> n;
    vb vis(k);
    vector<int> pos(n), temp(n);
    for(int i = 0; i < n; ++i)
        cin >> pos[i], --pos[i];

    for(int i = 0; i < n; ++i)
        cin >> temp[i];

    pqg<pi> q;
    for(int i = 0; i < n; ++i)
        q.push({temp[i], pos[i]});
    vector<int> ans(k, inf);
    while(q.size()) {
        pi t=q.top();
        q.pop();
        if(vis[t.second])
            continue;
        vis[t.second] = 1;
        ans[t.second] = t.first;
        if(t.second - 1 >= 0 && t.first + 1 < ans[t.second - 1])
            q.push({t.first + 1, t.second - 1});
        if(t.second + 1 < k && t.first + 1 < ans[t.second + 1])
            q.push({t.first + 1, t.second + 1});
    }

    for(int i = 0; i < k; ++i)
        cout << ans[i] << " ";
    cout << "\n";

}

int main()
{
    //setup();
    cin.tie(0)->sync_with_stdio(0);
    //precalc();
    int T = 1;
    cin >> T;

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;

    }
}