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

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long double PI = acos(-1);

const int N = 5e6;

int calc[100], dp[N];
pair<int, int> from[N];
_ void source() {
    int n, m;
    cin >> n >> m;
    if (m == n * (n - 1) / 2) {
        cout << 0;
        exit(0);
    }
    if (n == 1) {
        cout << 0;
        exit(0);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        calc[a] |= (1 << (b));
        calc[b] |= (1 << (a));
    }
    int lim = 1 << n;
    for (int i = 0; i < lim; i++) {
        dp[i] = INF;
    }
    for (int i = 0; i < n; i++) {
        dp[calc[i] | (1 << i)] = 1;
        from[calc[i] | (1 << i)] = mk(0, i);
    }
    for (int mask = 1; mask < lim; mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                if (dp[mask] + 1 < dp[mask | calc[i]]) {
                    dp[mask | calc[i]] = dp[mask] + 1;
                    from[mask | calc[i]] = mk(mask, i);
                }
            }
        }
    }
    cout << dp[lim - 1] << endl;
    int now = lim - 1;
    vector<int> ans;
    while (now) {
        pair<int, int> p = from[now];
        ans.pb(p.sec + 1);
        now = p.f;
    }
    reverse(all(ans));
    for (auto it : ans) {
        cout << it << ' ';
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