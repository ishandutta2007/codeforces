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

_ void source() {
    int n, lim, bal = 0, mx = -INF, cur = INF;
    cin >> n >> lim;
    vector<int> arr(n + 10), b(n + 10), suf(n + 10, -INF);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        bal += arr[i];
        b[i] = bal;
        mx = max(mx, bal);
        if (!arr[i]) {
            cur = min(cur, bal);
        }
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = max(suf[i + 1], b[i]);
    }
    if (suf[1] > lim) {
        cout << -1;
        exit(0);
    }
    int al = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!arr[i]) {
            if (b[i] + al < 0) {
                al += max(ll(0), lim - suf[i] - al);
                if (b[i] + al < 0) {
                    cout << -1;
                    exit(0);
                }
                ans++;
            }
        }
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
    srand(time(0));
    source();
    return 0;
}