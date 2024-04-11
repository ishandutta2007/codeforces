#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast", "no-stack-protector")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "tune=native", "abm")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define rsz resize
//#define int ll
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)

#define next nextt
#define prev prevv
#define left leftt
#define right rightt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-6;

mt19937 Random(int(time(0)));

map<int, int> cnt;

_ void source() {
    int n, mn = INF, mx = -INF;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        mn = min(mn, a);
        mx = max(mx, a);
    }
    if (mn == mx) {
        cout << n << endl;
        forn(i, n) cout << mn << ' ';
        exit(0);
    }
    if (mx - mn == 1) {
        cout << n << endl;
        for (int i = 1; i <= cnt[mn]; i++) {
            cout << mn << ' ';
        }
        for (int i = 1; i <= cnt[mn + 1]; i++) {
            cout << mn + 1 << ' ';
        }
        exit(0);
    }
    int need = cnt[mn + 1] + cnt[mn + 2] * 2, cur_res = INF, opt = 0;
    for (int i = 0; i <= n; i++) {
        if (need < i) {
            break;
        }
        if ((need - i) % 2 == 1) {
            continue;
        }
        int c3 = (need - i) / 2, c1 = n - c3 - i;
        if (c1 < 0) continue;
        if (min(cnt[mn], c1) + min(cnt[mn + 1], i) + min(cnt[mn + 2], c3) < cur_res) {
            cur_res = min(cnt[mn], c1) + min(cnt[mn + 1], i) + min(cnt[mn + 2], c3);
            opt = i;
        }
        //cout << i << ' ' << cur_res << endl;
    }
    cout << cur_res << endl;
    int c3 = (need - opt) / 2, c1 = n - c3 - opt;
    for (int i = 0; i < c1; i++) {
        cout << mn << ' ';
    }
    for (int i = 0; i < opt; i++) {
        cout << mn + 1 << ' ';
    }
    for (int i = 0; i < c3; i++) {
        cout << mn + 2 << ' ';
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}