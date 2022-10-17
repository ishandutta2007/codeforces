#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

using namespace std;

typedef long double ld;
typedef long long ll;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 5e5 + 10;

int t[10 * N], arr[N];;
bool was;

_ void relax(int v) {
    t[v] = __gcd(t[2 * v], t[2 * v + 1]);
}

_ void build(int v, int l, int r) {
    if (l == r) {
        t[v] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    relax(v);
}

_ void upd(int v, int l, int r, int need, int val) {
    if (l > need || r < need) {
        return;
    }
    if (l == r) {
        t[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * v, l, mid, need, val);
    upd(2 * v + 1, mid + 1, r, need, val);
    relax(v);
}

_ int get(int v, int l, int r, int a, int b, int val) {
    if (l > b || r < a || was) {
        return 0;
    }
    int mid = (l + r) / 2;
    if (l >= a && r <= b) {
        if (t[v] % val == 0) {
            return 0;
        }
        if (l == r) {
            return 1;
        }
        if (t[2 * v] % val == 0) {
            return get(2 * v + 1, mid + 1, r, a, b, val);
        }
        else if (t[2 * v + 1] % val == 0) {
            return get(2 * v, l, mid, a, b, val);
        }
        was = true;
        return 2;
    }
    return get(2 * v, l, mid, a, b, val) + get(2 * v + 1, mid + 1, r, a, b, val);
}

_ void source() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            was = false;
            int res = get(1, 1, n, l, r, x);
            if (res <= 1) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            int pos, val;
            cin >> pos >> val;
            upd(1, 1, n, pos, val);
        }
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}