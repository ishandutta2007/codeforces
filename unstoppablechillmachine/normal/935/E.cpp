#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
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

int lim;

pair<vector<int>, vector<int> > solve(string s, bool t) {
    int sz = s.size();
    vector<int> mx(lim + 1), mn(lim + 1);
    if (sz == 1) {
        mx[0] = s[0] - '0';
        mn[0] = s[0] - '0';
        for (int i = 1; i <= lim; i++) {
            mx[i] = -INF;
            mn[i] = INF;
        }
        return mk(mx, mn);
    }
    int bal = 0, mid;
    for (int i = 0; i < sz; i++) {
        if (s[i] == '(') {
            bal++;
        }
        if (s[i] == ')') {
            bal--;
        }
        if (s[i] == '?' && bal == 1) {
            mid = i;
            break;
        }
    }
    string s1, s2;
    for (int i = 1; i < mid; i++) {
        s1 += s[i];
    }
    for (int i = mid + 1; i + 1 < sz; i++) {
        s2 += s[i];
    }
    pair<vector<int>, vector<int> > calc_left = solve(s1, t), calc_right = solve(s2, t);
    for (int i = 0; i <= lim; i++) {
        mx[i] = -INF;
        mn[i] = INF;
    }
    for (int i = 0; i <= lim; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 2; k++) {
                if (j + k > i) {
                    continue;
                }
                if (!(t ^ k)) {
                    mn[i] = min(mn[i], calc_left.sec[j] + calc_right.sec[i - j - k]);
                    mx[i] = max(mx[i], calc_left.f[j] + calc_right.f[i - j - k]);
                }
                else {
                    mn[i] = min(mn[i], calc_left.sec[j] - calc_right.f[i - j - k]);
                    mx[i] = max(mx[i], calc_left.f[j] - calc_right.sec[i - j - k]);
                }
            }
        }
    }
    return mk(mx, mn);
}

_ void source() {
    string s;
    int a, b;
    cin >> s >> a >> b;
    if (a <= 100) {
        lim = a;
        vector<int> mx = solve(s, 1).f;
        cout << mx[a];
    }
    else {
        lim = b;
        vector<int> mx = solve(s, 0).f;
        cout << mx[b];
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