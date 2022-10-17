 #include <bits/stdc++.h>

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
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

int get(int a, int mod, int b) {
    int len = 2;
    while (a) {
        a = (a + b) % mod;
        len++;
    }
    return len;
}

_ void source() {
    int n, m, k;
    cin >> n >> k >> m;
    vector<int> arr(n + 1);
    unordered_set<int> st;
    if (k == 1) {
        cout << 0;
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        st.ins(arr[i]);
    }
    if (st.size() == 1) {
        cout << (n * m) % k;
        exit(0);
    }
    vector<pair<int, int> > cur;
    for (int i = 1; i <= n; i++) {
        if (cur.empty()) {
            cur.pb(mk(arr[i], 1));
            continue;
        }
        if (arr[i] == cur.back().f) {
            int a = int(cur.size()) - 1;
            cur[a].sec++;
            if (cur[a].sec == k) {
                cur.pop_back();
            }
        }
        else {
            cur.pb(mk(arr[i], 1));
        }
    }
    int sum = 0;
    for (auto it : cur) {
        sum += it.sec;
    }
    if (m == 1) {
        cout << sum;
        exit(0);
    }
    deque<pair<int, int> > d1, d2;
    for (auto it : cur) {
        d1.pb(it);
        d2.pb(it);
    }
    int cnt = 0;
    while (!d1.empty() && !d2.empty() && d1.back().f == d2.front().f && d1.back().sec + d2.front().sec >= k) {
        cnt++;
        pair<int, int> p = mk(d1.back().f, (d1.back().sec + d2.front().sec) % k);
        d1.pop_back();
        d2.pop_front();
        if (p.sec) {
            d1.pb(p);
        }
    }
    if (d1.empty() && d2.empty()) {
        if (m % 2 == 0) {
            cout << 0;
        }
        else {
            cout << sum;
        }
        exit(0);
    }
    if (d1.size() + d2.size() > cur.size()) {
        cout << sum * m - (m - 1) * cnt * k;
        exit(0);
    }
    assert(d1.size() + d2.size() == cur.size());
    int b;
    if (cur.size() % 2) {
        b = cur[int(cur.size()) / 2].sec;
    }
    else {
        b = cur[int(cur.size()) / 2 - 1].sec;
    }
    int len = get(d1.back().sec, k, b);
    m %= len;
    if (m == 0) {
        cout << 0;
        exit(0);
    }
    int a = b, pp = 0;
    for (int i = 2; i <= m; i++) {
        a += b;
        if (a < k) {
            pp++;
        }
        a %= k;
    }
    cout << sum * m - (m - 1) * cnt * k + pp * k;
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
    srand(time(0));
    source();
    return 0;
}