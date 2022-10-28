#include <bits/stdc++.h>
using namespace std;

const int B = 16;

template <class T>
struct fenwick {
    vector<T> tree;
    int n;

    fenwick(int n) : n(n) {
        tree.resize(n + 1);
    }

    void update(int a, T x) {
        for ( ; a <= n; a += (a & -a)) {
            tree[a] += x;
        }
    }

    T query(int a) {
        T res = 0;
        for ( ; a > 0; a -= (a & -a)) {
            res += tree[a];
        }
        return res;
    }

    int lower_bound(T k) {
        int res = 0;
        T sum = 0;
        for (int i = __lg(n); i >= 0; --i) {
            if (res + (1 << i) <= n && sum + tree[res + (1 << i)] < k) {
                res += 1 << i;
                sum += tree[res];
            }
        }
        return res + 1;
    }
};

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, k;
    cin >> n >> t >> k;

    fenwick<int> fenw(n);
    for (int i = 1; i <= n; i += B) {
        int j = min(n, i + B - 1);
        fenw.update(i, j - i + 1 - query(i, j));
    }

    while (t--) {
        int x = fenw.lower_bound(k);

        int low = x, high = min(n, x + B - 1);
        while (low < high) {
            int mid = (low + high) / 2;
            if (mid - query(1, mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        fenw.update(x, -1);

        cout << "! " << low << endl;

        if (t > 0) {
            cin >> k;
        }
    }
}