#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S secondond
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 2e5 + 10;
int t[4 * N];
void update(int v, int l, int r, int need, int val) {
    if (l == r) {
        t[v] = max(t[v], val);
        return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
        update(2 * v, l, mid, need, val);
    } else {
        update(2 * v + 1, mid + 1, r, need, val);
    }
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get_max(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r <= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return max(get_max(2 * v, l, mid, a, b), get_max(2 * v + 1, mid + 1, r, a, b));
}

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    set<int> guys;
    for (int i = 1; i <= n; i++) {
        guys.insert(i);
    }
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            if (x == 0) {
                for (;;) {
                    auto it = guys.lower_bound(l);
                    if (it == guys.end() || *it > r) {
                        break;
                    }
                    guys.erase(it);
                }
            } else {
                update(1, 1, n, r, l);
            }
        } else {
            int id;
            cin >> id;
            if (!guys.count(id)) {
                cout << "NO\n";
            } else {
                int left_border, right_border;
                auto it = guys.upper_bound(id);
                if (it == guys.end()) {
                    right_border = n;
                } else {
                    right_border = *it - 1;
                }
                it--;
                if (it == guys.begin()) {
                    left_border = 1;
                } else {
                    it--;
                    left_border = *it + 1;
                }
                if (get_max(1, 1, n, id, right_border) >= left_border) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
            }
        }
    }
}