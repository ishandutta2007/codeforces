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

const int N = 5e5 + 10;
int arr[N];
bool t[8 * N], f[8 * N];

void push(int v) {
    f[2 * v] |= f[v];
    f[2 * v + 1] |= f[v];
    t[2 * v] |= f[v];
    t[2 * v + 1] |= f[v];
}

void upd(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        f[v] = 1;
        t[v] = 1;
        return;
    }
    push(v);
    int mid = (l + r) / 2;
    upd(2 * v, l, mid, a, b);
    upd(2 * v + 1, mid + 1, r, a, b);
}

bool get_val(int v, int l, int r, int need) {
    if (l == r) {
        return t[v];
    }
    push(v);
    int mid = (l + r) / 2;
    if (need <= mid) {
        return get_val(2 * v, l, mid, need);
    }
    else {
        return get_val(2 * v + 1, mid + 1, r, need);
    }
}

_ void source() {
    int n, k, mx;
    cin >> n >> k >> mx;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    vector<int> dp(n + 1);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        if (i) dp[i] = get_val(1, 1, n, i);
        if (!dp[i]) {
            continue;
        }
        int l = i + 1, r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (arr[mid] - arr[i + 1] <= mx) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (l - i >= k) {
            upd(1, 1, n, i + k, l);
        }
    }
    cout << (get_val(1, 1, n, n) ? "YES" : "NO");
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