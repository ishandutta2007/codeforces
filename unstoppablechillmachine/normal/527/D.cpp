#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define int ll
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

const int N = 1e6 + 10;
int t[N], f[N];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.f - a.sec < b.f - b.sec;
}

void push(int v) {
    if (f[v]) {
        f[2 * v] = max(f[2 * v], f[v]);
        f[2 * v + 1] = max(f[2 * v + 1], f[v]);
        t[2 * v] = max(t[2 * v], f[v]);
        t[2 * v + 1] = max(t[2 * v + 1], f[v]);
        f[v] = 0;
    }
}

int get(int v, int l, int r, int need) {
    if (l == r) {
        return t[v];
    }
    push(v);
    int mid = (l + r) / 2;
    if (need <= mid) {
        return get(2 * v, l, mid, need);
    }
    else {
        return get(2 * v + 1, mid + 1, r, need);
    }
}

void upd(int v, int l, int r, int a, int b, int val) {
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        t[v] = max(t[v], val);
        f[v] = max(f[v], val);
        return;
    }
    push(v);
    int mid = (l + r) / 2;
    upd(2 * v, l, mid, a, b, val);
    upd(2 * v + 1, mid + 1, r, a, b, val);
}

_ void source() {
    int n;
    cin >> n;
    vector<pair<int, int> > arr(n);
    for (auto &it : arr) {
        cin >> it.f >> it.sec;
    }
    sort(all(arr), cmp);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int cur = get(1, 1, n, i + 1) + 1;
        ans = max(ans, cur);
        int l = i, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (abs(arr[i].f - arr[mid].f) >= arr[i].sec + arr[mid].sec) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if (abs(arr[i].f - arr[r].f) >= arr[i].sec + arr[r].sec) {
            upd(1, 1, n, r + 1, n, cur);
        }
    }
    cout << ans;
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