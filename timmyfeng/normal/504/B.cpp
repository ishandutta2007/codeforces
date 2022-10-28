#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>

template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
    T, __gnu_pbds::null_type, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

vector<int> read(int n) {
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    ordered_set<int> nums;
    for (int i = n - 1; i >= 0; --i) {
        nums.insert(a[i]);
        a[i] = nums.order_of_key(a[i]);
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a = read(n), b = read(n);

    int carry = 0;
    for (int i = n - 1; i >= 0; --i) {
        a[i] += b[i] + carry;
        if (a[i] >= n - i) {
            a[i] -= n - i;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    ordered_set<int> nums;
    for (int i = 0; i < n; ++i) {
        nums.insert(i);
    }

    for (auto i : a) {
        auto it = nums.find_by_order(i);
        cout << *it << " ";
        nums.erase(it);
    }
    cout << "\n";
}