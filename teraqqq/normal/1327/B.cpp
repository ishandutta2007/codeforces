#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp>
#include <stdint.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define rsz resize
#define mp make_pair

#define sz(x) ((int)(x).size())
#define all(x)  (x).begin(),  (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

using ld = double;
using cd = complex<ld>;
using vcd = vector<cd>;

template<class T> using ordered_set = tree<T, null_type, less<T>,
                         rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<vi> g(n);
    vector<char> used(n), ok(n);

    for(int i = 0; i < n; ++i) {
        int k; cin >> k;
        g[i].rsz(k); for(int& x : g[i]) cin >> x;
        for(int x : g[i])
            if(!used[x-1] && !ok[i])
                used[x-1] = ok[i] = 1;
    }
    for(int i = 0; i < n; ++i) {
        if(ok[i]) continue;
        for(int j = 0; j < n; ++j) {
            if(used[j]) continue;
            cout << "IMPROVE" << '\n' << i+1 << " " << j+1 << '\n';
            return;
        }
    }

    cout << "OPTIMAL" << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}