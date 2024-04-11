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
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random((int)time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1e5 + 10;

_ void source() {
    int n, k, mx = 0, last;
    set<int> st;
    vector<int> ans, cur;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        st.ins(i);
    }
    int need = 1;
    for (int i = 1; i <= k; i++) {
        int a;
        cin >> a;
        ans.pb(a);
        cur.pb(a);
        while (!cur.empty() && cur.back() == need) {
            cur.pop_back();
            need++;
        }
        mx = max(mx, a);
        last = a;
        st.ers(a);
    }
    while (!st.empty() && *st.begin() < mx) {
        while (!cur.empty() && cur.back() == need) {
            cur.pop_back();
            need++;
        }
        if (cur.empty()) {
            break;
        }
        if (st.find(cur.back() - 1) != st.end()) {
            cur.pb(cur.back() - 1);
            ans.pb(cur.back());
            st.ers(cur.back());
        }
        else {
            cout << -1;
            exit(0);
        }
    }
    while (!cur.empty() && cur.back() == need) {
        cur.pop_back();
        need++;
    }
    if (!cur.empty()) {
        cout << -1;
        exit(0);
    }
    for (int i = n; i > mx; i--) {
        ans.pb(i);
    }
    copy(all(ans), ostream_iterator<int>(cout, " "));
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