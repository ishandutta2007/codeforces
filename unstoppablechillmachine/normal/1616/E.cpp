#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 2e5 + 10;
int t[4 * N];
void build(int v, int l, int r, const string& s) {
    if (l == r) {
        t[v] = 1 << (s[l - 1] - 'a');
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, s);
    build(2 * v + 1, mid + 1, r, s);
    t[v] = t[2 * v] | t[2 * v + 1];
}

void set_val(int v, int l, int r, int pos, int val) {
    if (l == r) {
        t[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        set_val(2 * v, l, mid, pos, val);
    } else {
        set_val(2 * v + 1, mid + 1, r, pos, val);
    }
    t[v] = t[2 * v] | t[2 * v + 1];
}

int find_left(int v, int l, int r, int a, int b, int mask) {
    if (l > b || r < a) {
        return 1e18;
    }
    if (l >= a && r <= b) {
        while (l < r) {
            int mid = (l + r) / 2;
            if (t[2 * v] & mask) {
                v *= 2;
                r = mid;
            } else {
                v = v * 2 + 1;
                l = mid + 1;
            }
        }
        if (t[v] & mask) {
            return l;
        } else {
            return 1e18;
        }
    }
    int mid = (l + r) / 2;
    return min(find_left(2 * v, l, mid, a, b, mask), find_left(2 * v + 1, mid + 1, r, a, b, mask));
}

int T[N], n;
void upd(int v, int delta) {
    for (; v <= n; v += v & (-v)) {
        T[v] += delta;
    }
}

int get(int v) {
    int res = 0;
    for (; v > 0; v -= v & (-v)) {
        res += T[v];
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test;
    cin >> test;
    vector<int> msk(26);
    msk[0] = 1;
    for (int i = 1; i < 26; i++) {
        msk[i] = msk[i - 1] | (1 << i);
    }
    while (test--) {
        cin >> n;
        string s, t;
        cin >> s >> t;
        build(1, 1, n, s);
        for (int i = 1; i <= n; i++) {
            T[i] = 0;
        }
        int ans = 1e18, sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = (t[i] == 'a' ? 0 : msk[t[i] - 'a' - 1]);
            int ps = find_left(1, 1, n, 1, n, cur);
            if (ps != 1e18) {
                ans = min(ans, sum + ps - get(ps - 1) - 1);
            }
            //cerr << i << ' ' << sum << '\n';
            //cerr << ps << '\n';
            ps = find_left(1, 1, n, 1, n, 1 << (t[i] - 'a'));
            //cerr << ps << '\n';
            if (ps != 1e18) {
                sum += ps - get(ps - 1) - 1;
                upd(ps, 1);
                set_val(1, 1, n, ps, 0);
            } else {
                break;
            }
        }
        cout << (ans == 1e18 ? -1 : ans) << '\n';
    }
}