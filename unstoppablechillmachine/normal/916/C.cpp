#include <bits/stdc++.h>

/*#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")*/

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

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

bool check(int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

_ void source() {
    int n, m;
    cin >> n >> m;
    int need = n - 1;
    while (!check(need)) {
        need++;
    }
    cout << need << ' ' << need << endl;
    for (int i = 1; i < n - 1; i++) {
        cout << i << ' ' << i + 1 << ' ' << 1 << endl;
        need--;
    }
    cout << n - 1 << ' ' << n << ' ' << need << endl;
    m -= (n - 1);
    if (!m) {
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            cout << i << ' ' << j << ' ' << 1000000000 << endl;
            m--;
            if (!m) {
                exit(0);
            }
        }
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
    source();
    return 0;
}