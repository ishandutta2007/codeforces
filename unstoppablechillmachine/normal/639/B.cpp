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
    int n, h, d;
    cin >> n >> d >> h;
    if (d > 2 * h) {
        cout << -1;
        exit(0);
    }
    if (d == 1 && n != 2) {
        cout << -1;
        exit(0);
    }
    if (h == d) {
        for (int i = 1; i < h; i++) {
            cout << i << ' ' << i + 1 << endl;
        }
        for (int i = h + 1; i <= n; i++) {
            cout << h << ' ' << i << endl;
        }
        exit(0);
    }
    int a = min(d - 1, h);
    for (int i = 1; i <= a; i++) {
        cout << i << ' ' << i + 1 << endl;
    }
    d -= (a + 1);
    a++;
    cout << 1 << ' ' << a + 1 << endl;
    a++;
    for (int i = a; i <= a + d - 1; i++) {
        cout << i << ' ' << i + 1 << endl;
    }
    for (int i = a + d + 1; i <= n; i++) {
        cout << 1 << ' ' << i << endl;
    }
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