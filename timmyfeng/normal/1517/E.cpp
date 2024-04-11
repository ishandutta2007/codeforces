#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>

template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
    T, __gnu_pbds::null_type, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

const int N = 200000, M = 998244353;

long long a[N], prefix[N], suffix[N];

long long solve(int l, int r, long long x) {
    for (int i = l; i <= r; ++i) {
        prefix[i] = i - 2 >= l ? prefix[i - 2] : 0;
        prefix[i] += i - 1 >= l ? -2 * a[i - 1] : 0;
    }

    for (int i = r; i >= l; --i) {
        suffix[i] = i + 2 <= r ? suffix[i + 2] : 0;
        suffix[i] += i + 1 <= r ? 2 * a[i + 1] : 0;
    }

    long long alt = 0;
    for (int i = l; i <= r; ++i) {
        alt += i % 2 == 0 ? a[i] : -a[i];
    }

    ordered_set<pair<long long, int>> odd, even;
    long long ans = 0;

    for (int i = l; i <= r; ++i) {
        if (i % 2 == 0) {
            ans += odd.size() - odd.order_of_key({x - alt - suffix[i], N});
            even.insert({prefix[i], i});
        } else {
            ans += even.size() - even.order_of_key({x + alt - suffix[i], N});
            odd.insert({prefix[i], i});
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long sum = accumulate(a, a + n, 0LL);
        long long ans = 0;

        while (sum > 0) {
            sum -= 2 * a[n - ++ans];
        }

        ans += solve(0, n - 1, 0);
        ans += solve(1, n - 1, -a[0]);
        ans += solve(0, n - 2, a[n - 1]);
        ans += solve(1, n - 2, a[n - 1] - a[0]);

        cout << ans % M << "\n";
    }
}