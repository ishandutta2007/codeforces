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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> p(n);
        for (auto &i : p) cin >> i;

        long long answer = 0;
        ordered_set<int> indices;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] < i) {
                answer += indices.order_of_key(p[i - 1]);
                indices.insert(i);
            }
        }

        cout << answer << "\n";
    }
}