#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e5 + 10;
int t[4 * N];

void build(int v, int l, int r, vector<int> &val) {
    if (l == r) {
        t[v] = val[l - 1];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, val);
    build(2 * v + 1, mid + 1, r, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get_max(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r<= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return max(get_max(2 * v, l, mid, a, b), get_max(2 * v + 1, mid + 1, r, a, b));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    //int T;
    //cin >> T;
    //while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (auto &x : a) {
            cin >> x;
        }
        build(1, 1, m, a);
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int xs, ys, xf, yf, k;
            cin >> xs >> ys >> xf >> yf >> k;
            if (abs(xs - xf) % k != 0 || abs(ys - yf) % k != 0) {
                cout << "NO\n";
                continue;
            }
            int h = get_max(1, 1, m, min(ys, yf) + 1, max(ys, yf) - 1) + 1;
            if (h % k != xs % k) {
                if (xs % k > h % k) {
                    h += xs % k - h % k;
                } else {
                    h += k - (h % k - xs % k);
                }
            }
            cout << (h <= n ? "YES" : "NO") << '\n';
        }
    //}
    return 0;
}