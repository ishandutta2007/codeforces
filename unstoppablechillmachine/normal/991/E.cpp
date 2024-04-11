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

int fact[20];

int solve(vector<int> cnt) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += cnt[i];
    }
    int res = fact[sum];
    for (int i = 0; i < 10; i++) {
        res /= fact[cnt[i]];
    }
    return res;
}

int f(int step, vector<int> have, vector<int> start, bool kek) {
    if (step == 10) {
        return solve(have);
    }
    if (start[step] == 0) {
        have.pb(0);
        return f(step + 1, have, start, kek);
    }
    else {
        int ans = 0;
        for (int i = 1; i <= start[step]; i++) {
            have.pb(i);
            ans += f(step + 1, have, start, kek);
            have.pop_back();
        }
        if (!step && kek) {
            have.pb(0);
            ans += f(step + 1, have, start, kek);
            have.pop_back();
        }
        return ans;
    }
}

_ void source() {
    fact[0] = 1;
    for (int i = 1; i <= 19; i++) {
        fact[i] = fact[i - 1] * i;
    }
    int n;
    cin >> n;
    vector<int> cnt(10);
    while (n) {
        cnt[n % 10]++;
        n /= 10;
    }
    int ans = f(0, {}, cnt, false);
    if (cnt[0]) {
        cnt[0]--;
        ans -= f(0, {}, cnt, true);
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