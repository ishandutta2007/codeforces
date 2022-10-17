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

#define TASK "pocnitoare"

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ int bp(int b, int a) {
    if (!a) {
        return 1;
    }
    if (a % 2 == 0) {
        int now = bp(b, a / 2);
        return (now * now) % MOD;
    }
    else {
        int now = bp(b, a / 2);
        return ((now * now) % MOD * b) % MOD;
    }
}

_ void source() {
    int a, b, k;
    cin >> a >> b >> k;
    if (a > b) {
        swap(a, b);
    }
    if (k == -1 && a % 2 != b % 2) {
        cout << 0;
        exit(0);
    }
    cout << bp(bp(2, a - 1) % MOD, b - 1) % MOD;
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