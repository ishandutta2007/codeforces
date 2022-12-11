#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e18;

struct Node {
    int max_base = -INF;
    int add = -INF;
    bool f = 0;
    int max_total = -2 * INF;
    Node() {}
};

const int N = 1 << 19;
Node t1[2 * N], t2[2 * N];
int pref[N], suff[N], a[N], b[N], c[N], poss[N];
vector <pair <int, int>> op[N], cl[N];
vector <int> v_l;

void relax(Node *t, int pos) {
    t[pos].max_base = max(t[2 * pos].max_base, t[2 * pos + 1].max_base);
    t[pos].max_total = max(t[2 * pos].max_total, t[2 * pos + 1].max_total);
}

void full(Node *t, int pos, int add) {
    t[pos].f = 1;
    t[pos].max_total = t[pos].max_base + add;
    t[pos].add = add;
}

void push(Node *t, int pos) {
    if (!t[pos].f)
        return;
    t[pos].f = 0;
    full(t, 2 * pos, t[pos].add);
    full(t, 2 * pos + 1, t[pos].add);
}

void update(Node *t, int pos, int l, int r, int k, int new_base) {
    if (k > r || k < l)
        return;
    if (l == r) {
        t[pos].max_base = new_base;
        t[pos].max_total = t[pos].max_base + t[pos].add;
        return;
    }
    int m = (l + r) / 2;
    push(t, pos);
    if (k <= m)
        update(t, 2 * pos, l, m, k, new_base);
    else
        update(t, 2 * pos + 1, m + 1, r, k, new_base);
    relax(t, pos);
}

void new_add(Node *t, int pos, int l, int r, int a, int b, int add) {
    if (a > r || l > b || a > b)
        return;
    if (a <= l && r <= b) {
        full(t, pos, add);
        return;
    }
    int m = (l + r) / 2;
    push(t, pos);
    new_add(t, 2 * pos, l, m, a, b, add);
    new_add(t, 2 * pos + 1, m + 1, r, a, b, add);
    relax(t, pos);
}

int add_to_st(vector <pair <int, int>> &st, int pos, int val) {
    while (!st.empty() && st.back().second <= val)
        st.pop_back();
    int ret = (st.empty() ? 0 : st.back().first) + 1;
    st.push_back({pos, val});
    return ret;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    b[0] = b[n + 1] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i] - b[i - 1];
    suff[n + 1] = 0;
    for (int i = n; i >= 0; i--) suff[i] = suff[i + 1] + c[i] - b[i + 1];
    int sm_b = 0;
    for (int i = 1; i <= n; i++) sm_b += b[i];
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        k *= -1;
        op[l].push_back({i, k});
        cl[r].push_back({i, k});
    }
    int best = -INF;
    vector <pair <int, int>> st1, st2;
    for (int i = 1; i <= n; i++) {
        for (auto [num, cost] : op[i]) {
            v_l.push_back(i);
            poss[num] = v_l.size();
            update(t1, 1, 1, N, v_l.size(), cost);
            update(t2, 1, 1, N, v_l.size(), cost);
            //cout << cost << endl;
        }
        int vl = add_to_st(st1, i, pref[i]);
        int ll = lower_bound(v_l.begin(), v_l.end(), vl) - v_l.begin() + 1;
        new_add(t1, 1, 1, N, ll, v_l.size(), pref[i]);
        int curr = max(t1[1].max_total, t2[1].max_total);
        //cout << pref[i] << ' ' << curr << ' ' << suff[i] << ' ' << t1[1].max_total<< ' ' << t2[1].max_total << endl;
        best = max(best, curr + suff[i]);

        vl = add_to_st(st2, i, curr);
        ll = lower_bound(v_l.begin(), v_l.end(), vl + 1) - v_l.begin() + 1;
        new_add(t2, 1, 1, N, ll, v_l.size() + op[i + 1].size(), curr);

        for (auto [num, cost] : cl[i]) {
            int pos = poss[num];
            update(t1, 1, 1, N, pos, -INF);
            update(t2, 1, 1, N, pos, -INF);
        }
    }
    cout << sm_b + best << "\n";
}