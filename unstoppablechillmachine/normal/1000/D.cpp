//I_l_M_P
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

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
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 998244353;//NEED_CHANGE
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1e3 + 10;
int C[N][N];

_ void add(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

_ int mult(int a, int b) {
    return (a * b) % MOD;
}

_ void precalc() {
    int MX = 1e3;
    for (int i = 1; i <= MX; i++) {
        C[i][1] = i;
        C[i][2] = (i * (i - 1) / 2) % MOD;
    }
    for (int i = 1; i <= MX; i++) {
        for (int j = 3; j <= MX; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

_ int get(int n, int k) {
    if (k > n || k <= 0) {
        return 0;
    }
    return C[n][k];
}

_ void source() {
    precalc();
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j <= n; j++) {
            add(dp[j], mult((dp[i] + 1), get(j - i - 1, arr[i + 1])));
        }
    }
    cout << dp[n];
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