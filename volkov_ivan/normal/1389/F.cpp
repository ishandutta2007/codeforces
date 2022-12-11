#include <bits/stdc++.h>

using namespace std;

struct segm{
    int l, r, c;
    segm() {}
    segm(int l, int r, int c): l(l), r(r), c(c) {}
};

struct Node{
    int max1 = 0, max2 = 0, d1 = 0, d2 = 0;
    Node() {}
};

const int N = 1 << 19;
vector <int> op[N], cl[N];
segm v[N];
int dp[N];
Node t[2 * N];

void relax(int pos) {
    t[pos].max1 = max(t[2 * pos].max1, t[2 * pos + 1].max1);
    t[pos].max2 = max(t[2 * pos].max2, t[2 * pos + 1].max2);
}

void full(int pos, int d1, int d2) {
    t[pos].d1 += d1;
    t[pos].d2 += d2;
    t[pos].max1 += d1;
    t[pos].max2 += d2;
}

void push(int pos) {
    full(2 * pos, t[pos].d1, t[pos].d2);
    full(2 * pos + 1, t[pos].d1, t[pos].d2);
    t[pos].d1 = t[pos].d2 = 0;
}

void update(int pos, int l, int r, int a, int b, int v1, int v2) {
    //cout << pos << ' ' << l << ' ' << r << endl;
    if (l > b || a > r || a > b) return;
    if (a <= l && r <= b) {
        //cout << l << ' ' << r << ' ' << v1 << ' ' << v2 << endl;
        full(pos, v1, v2);
        return;
    }
    int m = (l + r) / 2;
    push(pos);
    update(2 * pos, l, m, a, b, v1, v2);
    update(2 * pos + 1, m + 1, r, a, b, v1, v2);
    relax(pos);
}

signed main() {
    memset(dp, 0, sizeof(dp));
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector <int> all;
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r >> v[i].c;
        all.push_back(v[i].l);
        all.push_back(v[i].r);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i < n; i++) {
        v[i].l = lower_bound(all.begin(), all.end(), v[i].l) - all.begin() + 2;
        v[i].r = lower_bound(all.begin(), all.end(), v[i].r) - all.begin() + 2;
        //cout << v[i].l << ' ' << v[i].r << endl;
        op[v[i].l].push_back(i);
        cl[v[i].r].push_back(i);
    }
    int max1 = 0, max2 = 0, best = 0;
    for (int i = 2; i <= (int) all.size() + 1; i++) {
        dp[i] = 0;
        for (int elem : cl[i]) {
            if (v[elem].c == 1) update(1, 1, N, 1, v[elem].l - 1, 1, 0);
            else update(1, 1, N, 1, v[elem].l - 1, 0, 1);
        }
        dp[i] = max(t[1].max1, t[1].max2);
        //cout << i << ' ' << dp[i] << endl;
        best = max(best, dp[i]);
        update(1, 1, N, i, i, dp[i], dp[i]);
    }
    cout << best << endl;
}