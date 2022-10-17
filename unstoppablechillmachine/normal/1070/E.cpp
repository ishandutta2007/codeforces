//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

#ifdef flaax
template <class H> void _dbg(const char* s, H h) { cerr << s << " = " << h << endl; }
template <class H, class... T> void _dbg(const char* s, H h, T... t) {
    while (*s != ',') cerr << *s++; cerr << " = " << h << ","; _dbg(s + 1, t...);
}
#define db(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define db(...)
#endif

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define add push_back
#define del pop_back
#define ins insert
#define ers erase
#define f first
#define s second
ll sqr(ll x) { return x * x; }
ld sqrd(ld x) { return x * x; }
#define pw(x) (1ll << (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937 Random((int)time(0));
ll rnd(ll x) { return Random() % x; }
#define TASK ""

const ll INF = (ll)1e9 + 282;
const ll MOD = (ll)1e9 + 7;
const ld PI = acosl(-1.0);

struct Node {
    int x, y, l, r, sz;
};

vector <Node> t;
int cnt = 0, root = 0;

void init(int _n) {
    t.clear();
    t.resize(_n);
    cnt = 0;
    root = 0;
}

int make(int x) {
    cnt++;
    t[cnt].l = t[cnt].r = 0;
    t[cnt].x = x;
    t[cnt].y = rnd(INF);
    t[cnt].sz = 1;
    return cnt;
}

int getSz(int v) {
    return t[v].sz;
}

void relax(int v) {
    if (!v) {
        t[v].sz = 0;
        return;
    }
    t[v].sz = 1;
    if (t[v].l) {
        t[v].sz += t[t[v].l].sz;
    }
    if (t[v].r) {
        t[v].sz += t[t[v].r].sz;
    }
}

pii split(int v, int x) {
    if (!v) {
        return {0, 0};
    }
    if (t[v].x <= x) {
        pii sp = split(t[v].r, x);
        t[v].r = sp.f;
        relax(v);
        relax(sp.s);
        return {v, sp.s};
    } else {
        pii sp = split(t[v].l, x);
        t[v].l = sp.s;
        relax(v);
        relax(sp.f);
        return {sp.f, v};
    }
}

int merge(int l, int r) {
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    if (t[l].y > t[r].y) {
        t[l].r = merge(t[l].r, r);
        relax(l);
        return l;
    } else {
        t[r].l = merge(l, t[r].l);
        relax(r);
        return r;
    }
}

int insert(int v, int n) {
    if (!v) {
        relax(n);
        return n;
    }
    if (t[n].y > t[v].y) {
        pii sp = split(v, t[n].x);
        relax(sp.f);
        relax(sp.s);
        t[n].l = sp.f;
        t[n].r = sp.s;
        relax(n);
        return n;
    }
    if (t[n].x < t[v].x) {
        t[v].l = insert(t[v].l, n);
    } else {
        t[v].r = insert(t[v].r, n);
    }
    relax(v);
    return v;
}

int get(int v, int need) {
    //db("GET", v, need);
    if (!v) {
        return 0;
    }
    if (getSz(t[v].l) + 1 == need) {
        return t[v].x;
    }
    //db(t[v].l, getSz(t[v].l));
    if (getSz(t[v].l) >= need) {
        //db("goL");
        return get(t[v].l, need);
    } else {
        //db("goR");
        return get(t[v].r, need - 1 - getSz(t[v].l));
    }
}

struct FenTree {
    vector <ll> t;
    int n;

    void init(int _n) {
        n = _n;
        t.clear();
        t.resize(n, 0);
    }

    ll query(int p) {
        ll res = 0;
        for (; p >= 0; p = (p & (p + 1)) - 1) {
            res += t[p];
        }
        return res;
    }

    void update(int p, ll x) {
        for (; p < n; p = p | (p + 1)) {
            t[p] += x;
        }
    }
}fftime, ffcnt;

const int N = 2e5 + 10;
int arr[N], tim[N];
vector <int> w[N];
set <int> times;

bool check(int x, int m, ll t) {
    ll stime = fftime.query(x), scnt = ffcnt.query(x);
    int r = scnt / m * m;
    if (r == scnt) {
        r -= m;
    }
    //db(x, stime, scnt, r);
    if (!r) {
        return stime <= t;
    }
    int p = get(root, r);
    //db(p);
    ll rtime = fftime.query(p);
    return stime + rtime <= t;
}

int getCnt(int n, int m, ll t) {
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid, m, t)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (!check(l, m, t)) {
        return 0;
    }
    //db(l, fcnt.query(l));
    return ffcnt.query(l);
}

void $main(int tst) {
    int n, m;
    cin >> n >> m;
    ll t;
    cin >> t;
    times.clear();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (tim[arr[i]] != tst) {
            w[arr[i]].clear();
            tim[arr[i]] = tst;
        }
        w[arr[i]].add(i);
        times.ins(arr[i]);
    }
    fftime.init(n);
    ffcnt.init(n);
    init(n + 10);
    //db("=");
    int ans1 = 0, ans2 = 1;
    for (int i : times) {
        for (int j : w[i]) {
            fftime.update(j, arr[j]);
            ffcnt.update(j, 1);
            root = insert(root, make(j));
        }
        int res = getCnt(n, m, t);
        if (res > ans1) {
            ans1 = res;
            ans2 = arr[w[i][0]];
        }
    }
    //check(3, m, t);
    //db("=======================ANS=======================");
    cout << ans1 << " " << ans2;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(12);
#ifdef flaax
    assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
#else
    //assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    //assert(freopen(TASK".in", "r", stdin)); assert(freopen(TASK".out", "w", stdout));
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        $main(i + 1);
        cout << "\n";
    }
#ifdef flaax
    cout << endl;
    cerr << endl << "\t" << fixed << setprecision(12) << (ld)clock() / CLOCKS_PER_SEC << " sec" << endl;
#endif
}