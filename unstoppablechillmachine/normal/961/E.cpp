#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
//#define endl "\n"

#define right rightt
#define left leftt
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-6;

const int N = 2e5 + 10;
int t[8 * N];

void relax(int v) {
    t[v] = t[2 * v] + t[2 * v + 1];
}

void upd(int v, int l, int r, int need) {
    if (l == r) {
        t[v]++;
        return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
        upd(2 * v, l, mid, need);
    }
    else {
        upd(2 * v + 1, mid + 1, r, need);
    }
    relax(v);
}

_ int get_sum(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return 0;
    }
    if (l >= a && r <= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return get_sum(2 * v, l, mid, a, b) + get_sum(2 * v + 1, mid + 1, r, a, b);
}

_ void source() {
    int n;
    cin >> n;
    vector<int> st, arr(n + 1);
    map<int, int> val;
    for (int i = 1; i <= n; i++) {
        st.pb(i);
        cin >> arr[i];
        st.pb(arr[i]);
    }
    sort(all(st));
    st.rsz(unique(all(st)) - st.begin());
    int mx = st.size();
    for (int i = 0; i < st.size(); i++) {
        val[st[i]] = i + 1;
    }
    vector<pair<int, int> > query;
    for (int i = 1; i <= n; i++) {
        query.pb({min(val[arr[i]], val[i] - 1), val[i]});
    }
    sort(all(query));
    int cur = 1;
    ll ans = 0;
    for (auto it : query) {
        while (cur <= it.f) {
            upd(1, 1, mx, val[arr[cur]]);
            cur++;
        }
        ans += get_sum(1, 1, mx, it.sec, mx);
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