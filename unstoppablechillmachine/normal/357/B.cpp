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

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ void source() {
    int n, m;
    set<int> st;
    cin >> n >> m;
    vector<int> color(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        st.ins(1);
        st.ins(2);
        st.ins(3);
        cin >> a >> b >> c;
        if (color[b]) {
            swap(a, b);
        }
        if (color[c]) {
            swap(a, c);
        }
        if (color[a]) {
            st.ers(color[a]);
            color[b] = *st.begin();
            st.ers(st.begin());
            color[c] = *st.begin();
        }
        else {
            color[a] = 1;
            color[b] = 2;
            color[c] = 3;
        }
        st.clear();
    }
    for (int i = 1; i <= n; i++) {
        cout << max(ll(1), color[i]) << ' ';
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
    srand(time(0));
    source();
    return 0;
}