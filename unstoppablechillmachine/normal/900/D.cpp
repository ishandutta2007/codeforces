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

unordered_map<int, int> ans;

_ int bpow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b & 1) {
        return (a * bpow(a, b - 1)) % MOD;
    }
    int k = bpow(a, b / 2);
    return (k * k) % MOD;
}

_ int solve(int n) {
    if (ans[n]) {
        return ans[n];
    }
    if (n == 1) {
        return 1;
    }
    int res = bpow(2, n - 1);
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res = (res - solve(i) + 2 * MOD) % MOD;
            if (i != n / i && i != 1) {
                res = (res - solve(n / i) + 2 * MOD) % MOD;
            }
        }
    }
    ans[n] = res;
    return res;
}

_ void source() {
    int a, b;
    cin >> a >> b;
    if (b % a) {
        cout << 0;
        exit(0);
    }
    cout << solve(b / a);
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