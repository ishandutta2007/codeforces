#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

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

const int N = 1e6 + 10;
int arr[N], go[N], primes[N];
ll t[4 * N];
vector<int> p;

_ int get(int n) {
    int res = 1;
    for (auto it : p) {
        if (it > sqrt(n)) {
            break;
        }
        int cnt = 0;
        while (n % it == 0) {
            cnt++;
            n /= it;
        }
        if (cnt) return go[n] * (cnt + 1);
    }
    if (n > 1) {
        res *= 2;
    }
    return res;
}

_ void relax(int v) {
    t[v] = t[2 * v] + t[2 * v + 1];
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

_ void upd(int v, int l, int r, int need) {
    if (l == r) {
        t[v] = arr[l];
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

_ ll get_sum(int v, int l, int r, int a, int b) {
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
    for (int i = 2; i <= 1e6; i++) {
        primes[i] = true;
    }
    primes[0] = primes[1] = false;
    int lim = 1e6;
    for (int i = 2; i <= lim; i++) {
        if (primes[i] && i * 1ll * i <= lim) {
            for (int j = i * i; j <= lim; j += i) {
                primes[j] = false;
            }
        }
    }
    for (int i = 2; i <= lim; i++) {
        if (primes[i]) {
            p.pb(i);
        }
    }
    go[1] = 1;
    for (int i = 2; i <= lim; i++) {
        go[i] = get(i);
    }
    int n, m;
    set<int> st;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] > 2) {
            st.ins(i);
        }
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            vector<int> need_ers;
            auto it = st.lower_bound(l);
            while (it != st.end() && *it <= r) {
                arr[*it] = go[arr[*it]];
                upd(1, 1, n, *it);
                if (arr[*it] <= 2) {
                    need_ers.pb(*it);
                }
                it++;
            }
            for (auto it : need_ers) {
                st.ers(it);
            }
        }
        else {
            cout << get_sum(1, 1, n, l, r) << '\n';
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