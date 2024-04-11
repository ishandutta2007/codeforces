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
#define int ll
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

_ void source() {
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;
    for (int i = 1;; i++) {
        if ((1 << i) == n) {
            cout << "Final!";
            exit(0);
        }
        if (a / (1 << i) == b / (1 << i)) {
            cout << i;
            exit(0);
        }
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r". stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}