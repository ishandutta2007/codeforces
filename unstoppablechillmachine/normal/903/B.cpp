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
    int a1, b1, c1, b2, a2;
    vector<int> ans;
    cin >> a1 >> b1 >> c1 >> a2 >> b2;
    for (;;) {
        if (a1 > b2 || b1 >= a2) {
            ans.pb(1);
            a2 -= b1;
            if (a2 <= 0) {
                break;
            }
            a1 -= b2;
        }
        else {
            ans.pb(2);
            a1 += c1;
            a1 -= b2;
        }
    }
    cout << ans.size() << endl;
    for (auto &it : ans) {
        if (it == 1) {
            cout << "STRIKE" << endl;
        }
        else {
            cout << "HEAL" << endl;
        }
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