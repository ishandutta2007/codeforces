#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 2e5 + 10;
const int mx = 2e5;
ll sum_f[4 * N], f[4 * N], p[4 * N];
int cnt[4 * N];
bool have[N];

void push(int v) {
    if (p[v] != 0) {
        sum_f[2 * v] += p[v] * cnt[2 * v];
        sum_f[2 * v + 1] += p[v] * cnt[2 * v + 1];
        f[2 * v] += p[v];
        f[2 * v + 1] += p[v];
        p[2 * v] += p[v];
        p[2 * v + 1] += p[v];
        p[v] = 0;
    }
}

void set_value(int v, int l, int r, int need, bool val) {
    if (l == r) {
        cnt[v] = have[need] = val;
        sum_f[v] = f[v] * val;
        return;
    }
    push(v);
    int mid = (l + r) / 2;
    if (need <= mid) {
        set_value(2 * v, l, mid, need, val);
    } else {
        set_value(2 * v + 1, mid + 1, r, need, val);
    }
    sum_f[v] = sum_f[2 * v] + sum_f[2 * v + 1];
    cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
}

void update(int v, int l, int r, int a, int b, int val) {
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        sum_f[v] += cnt[v] * val;
        f[v] += val;
        p[v] += val;
        return;
    }
    push(v);
    int mid = (l + r) / 2;
    update(2 * v, l, mid, a, b, val);
    update(2 * v + 1, mid + 1, r, a, b, val);
    sum_f[v] = sum_f[2 * v] + sum_f[2 * v + 1];
}

ll get_sum(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r <= b) {
        return sum_f[v];
    }
    push(v);
    int mid = (l + r) / 2;
    return get_sum(2 * v, l, mid, a, b) + get_sum(2 * v + 1, mid + 1, r, a, b);
}

ll get_f(int v, int l, int r, int need) {
    if (l == r) {
        return f[v];
    }
    push(v);
    int mid = (l + r) / 2;
    if (need <= mid) {
        return get_f(2 * v, l, mid, need);
    }
    return get_f(2 * v + 1, mid + 1, r, need);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n, d;
    cin >> n >> d;
    ll answer = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (have[x]) {
            set_value(1, 1, mx, x, false);
            update(1, 1, mx, max(x - d, 0), x - 1, -1);
            answer -= get_sum(1, 1, mx, max(x - d, 0), x - 1);
            auto f_val = get_f(1, 1, mx, x);
            answer -= f_val * (f_val - 1) / 2;
        } else {
            set_value(1, 1, mx, x, true);
            answer += get_sum(1, 1, mx, max(x - d, 0), x - 1);
            auto f_val = get_f(1, 1, mx, x);
            answer += f_val * (f_val - 1) / 2;
            update(1, 1, mx, max(x - d, 0), x - 1, 1);
        }
        cout << answer << '\n';
    }
    return 0;
}