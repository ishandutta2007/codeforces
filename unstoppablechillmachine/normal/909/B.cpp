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

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random((int)time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ void source() {
    int n, ans = 0;
    set<pair<int, int> > st;
    vector<pair<int, int> > need_ers;
    cin >> n;
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len;
            st.ins(mk(l, r));
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len;
            if (st.find(mk(l, r)) == st.end()) {
                continue;
            }
            need_ers.pb(mk(l, r));
            auto it = st.upper_bound(mk(r, r));
            while (it != st.end()) {
                need_ers.pb(mk(it->f, it->sec));
                it = st.upper_bound(mk(it->sec, it->sec));
            }
            for (auto it : need_ers) {
                st.ers(it);
            }
            need_ers.clear();
            ans++;
        }
    }
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
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