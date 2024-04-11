#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7, M = (1e9+7), MAXN = 1 * 2e5;
int A[MAXN], C[MAXN];
#include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 #include <iterator>
 using namespace __gnu_pbds;

 template <typename T> using oset = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int N, l, r;
    cin >> N >> l >> r;
    vector<int> A(N);
    for(auto &i : A)
        cin >> i;
    oset<pair<int, int>> ts;
    // R - l - 1
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int f1 = l - A[i], f2 = r - A[i];
        int res = ts.order_of_key({f2 + 1, 0})- ts.order_of_key({f1, 0});
        ans += res;
        ts.insert({A[i], i});
    }

    cout << ans << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1; cin >> T;

    while(T--) {
        solve();
    }
}