#include <bits/stdc++.h>

using namespace std;

struct Node{
    int mn, posmn, d = 0;
    Node() {}
    Node(int val, int pos): mn(val), posmn(pos) {}
};

const int N = 1 << 19;
Node t[2 * N];
int a[N];
int ll[N];
vector <int> byval[N];
int ans[N];
int f[N];

void upd0(int pos, int val) {
    for (int i = pos; i < N; i += i & (-i)) f[i] += val;
}

int get0(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & (-i)) res += f[i];
    return res;
}

void relax(int pos) {
    if (t[2 * pos].mn <= t[2 * pos + 1].mn) {
        t[pos].mn = t[2 * pos].mn;
        t[pos].posmn = t[2 * pos].posmn;
    } else {
        t[pos].mn = t[2 * pos + 1].mn;
        t[pos].posmn = t[2 * pos + 1].posmn;
    }
}

void full(int pos, int d) {
    t[pos].d += d;
    t[pos].mn += d;
}

void push(int pos) {
    full(2 * pos, t[pos].d);
    full(2 * pos + 1, t[pos].d);
    t[pos].d = 0;
}

pair <int, int> get(int pos, int l, int r, int a, int b) {
    if (a > b || l > b || a > r) return {N + 1, N + 1};
    if (a <= l && r <= b) return {t[pos].mn, t[pos].posmn};
    push(pos);
    int m = (l + r) / 2;
    return min(get(2 * pos, l, m, a, b), get(2 * pos + 1, m + 1, r, a, b));
}

void upd(int pos, int l, int r, int a, int b, int val) {
    if (a > b || l > b || a > r) return;
    if (a <= l && r <= b) {
        full(pos, val);
        return;
    }
    push(pos);
    int m = (l + r) / 2;
    upd(2 * pos, l, m, a, b, val);
    upd(2 * pos + 1, m + 1, r, a, b, val);
    relax(pos);
}

signed main() {
    memset(f, 0, sizeof(f));
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = i - a[i];
        if (a[i] < 0) {
            a[i] = N + 1;
            ll[i] = 0;
        }
        else byval[a[i]].push_back(i);
    }
    //for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    //cout << endl;
    for (int i = 1; i <= N; i++) t[N + i - 1] = Node(N, i);
    for (int i = N - 1; i >= 1; i--) relax(i);
    vector <pair <pair <int, int>, int>> qq(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        r = n - r;
        qq[i].first = {l, r};
        qq[i].second = i;
    }
    sort(qq.begin(), qq.end());
    reverse(qq.begin(), qq.end());
    memset(ans, 0, sizeof(ans));
    int lp = 0;
    for (int i = n; i >= 1; i--) {
        if (a[i] != 0) {
            upd(1, 1, N, i, i, a[i] - N);
        } else {
            upd0(i, 1); 
            //cout << 105 << ' ' << i << endl;
            //cout << 105 << endl;
            upd(1, 1, N, i, n, -1);
            //cout << t[1].mn << endl;
            while (t[1].mn <= 0) {
                int p = t[1].posmn;
                upd0(p, 1);
                //cout << 112 << ' ' << p << endl;
                upd(1, 1, N, p, p, 2 * N);
                upd(1, 1, N, p, n, -1);
            }
        }
        while (lp != q && qq[lp].first.first == i - 1) {
            ans[qq[lp].second] = get0(qq[lp].first.second);
            lp++;
            //cout << lp << ' ' << qq[lp].first.first << ' ' << qq[lp].first.second << endl;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}