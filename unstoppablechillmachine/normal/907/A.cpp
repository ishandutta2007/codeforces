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

_ void source() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k < j; k++) {
                if (a <= i && 2 * a >= i && b <= j && 2 * b >= j && c <= k && 2 * c >= k && d <= k && 2 * d >= k && 2 * d < j) {
                    cout << i << endl << j << endl << k << endl;
                    exit(0);
                }
            }
        }
    }
    cout << -1;
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