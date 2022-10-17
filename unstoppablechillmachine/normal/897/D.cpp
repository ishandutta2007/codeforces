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

_ void source() {
    int n, m, c, k1 = 0, k2 = 0;
    vector<int> pref, suf;
    cin >> n >> m >> c;
    for (int i = 1; i <= m; i++) {
        assert(k1 < n);
        assert(k2 < n);
        int a;
        cin >> a;
        if (a > c / 2) {
            if (suf.empty()) {
                cout << n << endl;
                k2++;
                suf.pb(a);
            }
            else if (a <= suf[0]) {
                cout << n - k2 << endl;
                suf.ins(suf.begin(), a);
                k2++;
            }
            else {
                int p = suf.size(), cur = n;
                for (int j = p - 1; j >= 0; j--) {
                    if (a > suf[j]) {
                        suf[j] = a;
                        cout << cur << endl;
                        break;
                    }
                    cur--;
                }
            }
        }
        else {
            if (pref.empty()) {
                cout << 1 << endl;
                k1++;
                pref.pb(a);
            }
            else if (a >= pref[int(pref.size()) - 1]) {
                k1++;
                cout << k1 << endl;
                pref.pb(a);
            }
            else {
                for (int j = 0; j < pref.size(); j++) {
                    if (a < pref[j]) {
                        pref[j] = a;
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }
        }
        if (k1 + k2 == n) {
            exit(0);
        }
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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