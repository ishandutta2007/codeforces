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

int n, m, r, k, cnt;
set<pair<int, pair<int, int> > > st;
map<pair<int, int>, int> used;

_ int get(pair<int, int> p) {
    int y_from = max(ll(1), p.f - r + 1), y_to = min(n - r + 1, p.f);
    int x_from = max(ll(1), p.sec - r + 1), x_to = min(m - r + 1, p.sec);
    return (y_to - y_from + 1) * (x_to - x_from + 1);
}

_ void source() {
    cin >> n >> m >> r >> k;
    cnt = (n - r + 1) * (m - r + 1);
    pair<int, int> from = mk(n / 2 + (n % 2), m / 2 + (m % 2));
    st.ins(mk(get(from), from));
    used[from] = true;
    ld ans = 0;
    for (int i = 1; i <= k; i++) {
        assert(!st.empty());
        auto it = --st.end();
        ans += ld(it->f) / ld(cnt);
        pair<int, int> now = it->sec;
        if (now.f + 1 <= n) {
            pair<int, int> now2 = now;
            now2.f++;
            if (!used[now2]) {
                used[now2] = true;
                st.ins(mk(get(now2), now2));
            }
        }
        if (now.f > 1) {
            pair<int, int> now2 = now;
            now2.f--;
            if (!used[now2]) {
                used[now2] = true;
                st.ins(mk(get(now2), now2));
            }
        }
        if (now.sec + 1 <= m) {
            pair<int, int> now2 = now;
            now2.sec++;
            if (!used[now2]) {
                used[now2] = true;
                st.ins(mk(get(now2), now2));
            }
        }
        if (now.sec > 1) {
            pair<int, int> now2 = now;
            now2.sec--;
            if (!used[now2]) {
                used[now2] = true;
                st.ins(mk(get(now2), now2));
            }
        }
        st.ers(it);
    }
    cout << fixed << setprecision(10) << ans;
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
    source();
    return 0;
}