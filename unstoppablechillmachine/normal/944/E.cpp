#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast", "no-stack-protector")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "tune=native", "abm")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define rsz resize
//#define int ll
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)

#define next nextt
#define prev prevv
#define left leftt
#define right rightt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-6;

mt19937 Random(int(time(0)));

const int N = 1e5 + 10;
int pref[N], arr[N], next_mn[N], next_mx[N], dp1[N], dp2[N], t1[8 * N], t2[8 * N];

void relax1(int v) {
    t1[v] = max(t1[2 * v], t1[2 * v + 1]);
}

void relax2(int v) {
    t2[v] = max(t2[2 * v], t2[2 * v + 1]);
}

void upd1(int v, int l, int r, int need, int val) {
    if (l == r) {
        t1[v] = max(t1[v], val);
        return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
        upd1(2 * v, l, mid, need, val);
    }
    else {
        upd1(2 * v + 1, mid + 1, r, need, val);
    }
    relax1(v);
}

void upd2(int v, int l, int r, int need, int val) {
    if (l == r) {
        t2[v] = max(t2[v], val);
        return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
        upd2(2 * v, l, mid, need, val);
    }
    else {
        upd2(2 * v + 1, mid + 1, r, need, val);
    }
    relax2(v);
}

int get_max1(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r <= b) {
        return t1[v];
    }
    int mid = (l + r) / 2;
    return max(get_max1(2 * v, l, mid, a, b), get_max1(2 * v + 1, mid + 1, r, a, b));
}

int get_max2(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r <= b) {
        return t2[v];
    }
    int mid = (l + r) / 2;
    return max(get_max2(2 * v, l, mid, a, b), get_max2(2 * v + 1, mid + 1, r, a, b));
}

_ void source() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        pref[l]++;
        pref[r + 1]--;
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += pref[i];
        arr[i] = sum + 1;
    }
    /*vector<pair<int, int> > st, st2;
    for (int i = m; i >= 1; i--) {
        while(!st.empty() && st.back().f <= arr[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            next_mx[i] = st.back().sec;
        }
        st.pb({arr[i], i});

        while(!st2.empty() && st2.back().f >= arr[i]) {
            st2.pop_back();
        }
        if (!st2.empty()) {
            next_mn[i] = st2.back().sec;
        }
        st2.pb({arr[i], i});
    }*/
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        dp1[i] = get_max1(1, 1, n, 1, arr[i]) + 1;
        upd1(1, 1, n, arr[i], dp1[i]);
    }
    for (int i = m; i >= 1; i--) {
        dp2[i] = get_max2(1, 1, n, 1, arr[i]) + 1;
        upd2(1, 1, n, arr[i], dp2[i]);
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}