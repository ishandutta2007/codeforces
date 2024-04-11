#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

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

int C[1010][1010], dp[1010];

_ void source() {
    dp[1] = 0;
    for (int i = 2; i <= 1000; i++) {
        dp[i] = dp[__builtin_popcount(i)] + 1;
    }
    for (int i = 1; i <= 1000; i++) {
        C[i][0] = 1;
        C[i][1] = i;
    }
    C[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 2; j <= 1000; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    string s;
    int k;
    cin >> s >> k;
    if (k == 0) {
        cout << 1;
        exit(0);
    }
    int n = s.size();
    s.ins(s.begin(), ' ');
    vector<int> arr;
    for (int i = 1; i <= 1000; i++) {
        if (dp[i] == k - 1) {
            arr.pb(i);
        }
    }
    int ans = 0, al = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            continue;
        }
        else {
            for (auto it : arr) {
                if (it >= al) {
                    ans += C[n - i][it - al];
                    ans %= MOD;
                }
            }
            al++;
        }
    }
    for (auto it : arr) {
        if (it == al) {
            ans++;
            break;
        }
    }
    ans %= MOD;
    if (k == 1) {
        ans = (ans - 1 + MOD) % MOD;
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
    source();
    return 0;
}