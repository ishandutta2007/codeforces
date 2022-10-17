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

int have[110];
bool used[110];

_ void source() {
    int m, n;
    cin >> m >> n;
    vector<int> attack, defence;
    for (int i = 1; i <= m; i++) {
        string s;
        int val;
        cin >> s >> val;
        if (s == "ATK") {
            attack.pb(val);
        }
        else {
            defence.pb(val);
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> have[i];
    }
    sort(have + 1, have + n + 1);
    sort(all(defence));
    sort(all(attack));
    int ptr = 1, ans = 0;
    bool t = true;
    for (auto it : defence) {
        while (ptr <= n && have[ptr] <= it) {
            ptr++;
        }
        if (ptr > n) {
            t = false;
            break;
        }
        used[ptr] = true;
        ptr++;
    }
    if (t) {
        ptr = 1;
        int sum = 0;
        for (auto it : attack) {
            while (ptr <= n && (have[ptr] < it || used[ptr])) {
                ptr++;
            }
            if (ptr > n) {
                t = false;
                break;
            }
            used[ptr] = true;
            sum += have[ptr] - it;
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                sum += have[i];
            }
        }
        if (t) {
            ans = max(ans, sum);
        }
    }
    reverse(have + 1, have + n + 1);
    int sum = 0;
    for (int i = 1; i <= min(n, (int)attack.size()); i++) {
        if (have[i] < attack[i - 1]) {
            break;
        }
        sum += have[i] - attack[i - 1];
    }
    ans = max(ans, sum);
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