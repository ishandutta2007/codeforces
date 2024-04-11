#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

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

bool sqr[1010 * 1010];

_ void source() {
    for (int i = 1; i <= 1000; i++) {
        sqr[i * i] = true;
    }
    int a, b;
    cin >> a >> b;
    if (a < b) {
        swap(a, b);
    }
    vector<int> can;
    for (int i = 1; i < a * a; i++) {
        if (sqr[i] && sqr[a * a - i]) {
            can.pb(i);
        }
    }
    for (auto it : can) {
        pair<int, int> cur = {sqrt(a * a - it), sqrt(it)};
        if ((cur.f * b) % a != 0 || (cur.sec * b) % a != 0) {
            continue;
        }
        cur.f = cur.f * b / a;
        cur.sec = cur.sec * b / a;
        if (cur.sec != a * a - it) {
            cout << "YES" << endl;
            cout << 0 << ' ' << 0 << endl;
            cout << -sqrt(it) << ' ' << sqrt(a * a - it) << endl;
            cout << cur.f << ' ' << cur.sec << endl;
            exit(0);
        }
    }
    cout << "NO";
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