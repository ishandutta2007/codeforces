#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

vector<int> z_function(string s) {
    int n = s.size(), l = 0, r = 1;
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        z[i] = min(z[i - l], max(r - i, 0));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

const int N = 1e5 + 10;
int dp[N][2], pref[N];

_ void source() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> z = z_function(t + s);
    dp[0][0] = 1;
    pref[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= (int)t.size() && z[i] >= (int)t.size()) {
            add(dp[i][1], pref[i - (int)t.size()]);
        }
        else {
            dp[i][1] = dp[i - 1][1];
        }
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][0] %= MOD;
        pref[i] = pref[i - 1];
        add(pref[i], dp[i][0]);
        add(pref[i], dp[i][1]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(ans, dp[i][1]);
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