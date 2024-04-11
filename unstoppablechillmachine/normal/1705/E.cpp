#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 2e5 + 100;
int cnt[N], t[4 * N], f[4 * N];
bool all_even[4 * N], all_odd[4 * N];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = cnt[l];
        f[v] = 0;
        all_even[v] = (cnt[l] % 2 == 0);
        all_odd[v] = (cnt[l] % 2 == 1);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    all_even[v] = all_even[2 * v] && all_even[2 * v + 1];
    all_odd[v] = all_odd[2 * v] && all_odd[2 * v + 1];
    t[v] = t[2 * v] + t[2 * v + 1];
}

void change(int v, int delta, int l, int r) {
    f[v] += delta;
    t[v] += delta * (r - l + 1);
    if (delta % 2 != 0) {
        swap(all_even[v], all_odd[v]);
    }
}

void push(int v, int l, int r) {
    if (f[v]) {
        change(2 * v, f[v], l, (l + r) / 2);
        change(2 * v + 1, f[v], (l + r) / 2 + 1, r);
        f[v] = 0;
    }
}

void update(int v, int l, int r, int a, int b, int delta) {
    if (r < a || l > b) {
        return;
    }
    if (l >= a && r <= b) {
        change(v, delta, l, r);
        return;
    }
    push(v, l, r);
    int mid = (l + r) / 2;
    update(2 * v, l, mid, a, b, delta);
    update(2 * v + 1, mid + 1, r, a, b, delta);
    t[v] = t[2 * v] + t[2 * v + 1];
    all_even[v] = all_even[2 * v] && all_even[2 * v + 1];
    all_odd[v] = all_odd[2 * v] && all_odd[2 * v + 1];
}

bool check_all_even(int v, int l, int r, int a, int b) {
    if (r < a || l > b) {
        return true;
    }
    if (l >= a && r <= b) {
        return all_even[v];
    }
    push(v, l, r);
    int mid = (l + r) / 2;
    return check_all_even(2 * v, l, mid, a, b) && check_all_even(2 * v + 1, mid + 1, r, a, b);
}

bool check_all_odd(int v, int l, int r, int a, int b) {
    if (r < a || l > b) {
        return true;
    }
    if (l >= a && r <= b) {
        return all_odd[v];
    }
    push(v, l, r);
    int mid = (l + r) / 2;
    return check_all_odd(2 * v, l, mid, a, b) && check_all_odd(2 * v + 1, mid + 1, r, a, b);
}

int a[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i < N; i++) {
        if (cnt[i] >= 2) {
            cnt[i + 1] += cnt[i] / 2;
        }
    }
    build(1, 1, N - 1);
    auto sub = [&](int val) {
        int l = val - 1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check_all_even(1, 1, N - 1, val, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        update(1, 1, N - 1, val, l + 1, -1);
    };

    auto add = [&](int val) {
        int l = val - 1, r = N;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (check_all_odd(1, 1, N - 1, val, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        update(1, 1, N - 1, val, l + 1, 1);
    };
    for (int i = 0; i < q; i++) {
        int pos, new_val;
        cin >> pos >> new_val;
        sub(a[pos]);
        a[pos] = new_val;
        add(a[pos]);
        int v = 1, l = 1, r = N - 1;
        while (l != r) {
            push(v, l, r);
            if (t[2 * v + 1] > 0) {
                l = (l + r) / 2 + 1;
                v = v * 2 + 1;
            } else {
                r = (l + r) / 2;
                v = v * 2;
            }
        }
        cout << l << '\n';
    }
    return 0;
}