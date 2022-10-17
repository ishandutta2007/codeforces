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

int dp[11][110][2100];

_ bool check(int x, int mod) {
    vector<int> cnt(mod);
    while (x) {
        cnt[x % mod]++;
        x /= mod;
    }
    for (int i = 0; i < mod; i++) {
        if (cnt[i] & 1) {
            return false;
        }
    }
    return true;
}

_ int slow_solve(int mod, int l, int r) {
    int res = 0;
    for (int i = l; i <= r; i++) {
        res += check(i, mod);
    }
    return res;
}

_ void precalc() {
    for (int mod = 2; mod <= 10; mod++) {
        dp[mod][0][0] = 1;
        int lim = 100;
        for (int cnt = 0; cnt < lim; cnt++) {
            for (int mask = 0; mask < (1 << mod); mask++) {
                for (int digit = 0; digit < mod; digit++) {
                    dp[mod][cnt + 1][mask ^ (1 << digit)] += dp[mod][cnt][mask];
                }
            }
        }
    }
}

_ int fast_solve(int mod, int to) {
    if (to == 0) {
        return 0;
    }
    vector<int> arr;
    while (to) {
        arr.pb(to % mod);
        to /= mod;
    }
    reverse(all(arr));
    /*for (auto it : arr) {
        cout << it;
    }
    cout << endl;*/
    int ans = 0;
    for (int i = 1; i < arr.size(); i++) {
        for (int first_digit = 1; first_digit < mod; first_digit++) {
            ans += dp[mod][i - 1][1 << first_digit];
        }
    }
    //cout << ans << endl;
    int cur_mask = 0;
    for (int digit = 1; digit <= arr.size(); digit++) {
        if (digit > 1 && arr[digit - 1] > 0) {
            ans += dp[mod][(int)arr.size() - digit][cur_mask ^ 1];
        }
        for (int i = 1; i < arr[digit - 1]; i++) {
            ans += dp[mod][(int)arr.size() - digit][cur_mask ^ (1 << i)];
        }
        cur_mask ^= 1 << arr[digit - 1];
        //cout << ans << endl;
    }
    if (!cur_mask) {
        ans++;
    }
    //cout << endl << endl << endl;
    return ans;
}

_ void source() {
    precalc();
    /*for (int i = 0; i < 100; i++) {
        int mod = 10, l = Random() % 1000 + 1, r = Random() % 1000 + 1;
        if (l > r) {
            swap(l, r);
        }

        if (slow_solve(mod, l, r) != fast_solve(mod, r) - fast_solve(mod, l - 1)) {
            cout << "ERROR" << endl;
            cout << "TEST: " << mod << ' ' << l << ' ' << r << endl;
            cout << "MY ANSWER: " << fast_solve(mod, r) - fast_solve(mod, l - 1) << endl;
            cout << "CORRECT ANSWER: " << slow_solve(mod, l, r) << endl;
            exit(0);
        }
    }*/
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int mod, l, r;
        cin >> mod >> l >> r;
        cout << fast_solve(mod, r) - fast_solve(mod, l - 1) << endl;
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
    source();
    return 0;
}