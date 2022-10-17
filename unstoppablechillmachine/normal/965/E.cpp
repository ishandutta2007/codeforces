#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define endl "\n"

#define right rightt
#define left leftt
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));
mt19937 rnd(0);

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-9;

const int root = 1;
const int N = 1e5 + 10;
map<char, int> mp[N];
bool en[N];
int dp[N], cnt = 1;
multiset<int> cur[N];

_ void add(string s) {
    int v = root;
    for (int i = 0; i < s.size(); i++) {
        if (!mp[v][s[i]]) {
            cnt++;
            mp[v][s[i]] = cnt;
        }
        v = mp[v][s[i]];
    }
    en[v] = true;
}

_ void dfs(int v, int cur_h) {
    if (en[v]) {
        cur[v].ins(cur_h);
        dp[v] += cur_h;
        for (auto u : mp[v]) {
            dfs(u.sec, cur_h + 1);
            dp[v] += dp[u.sec];
            for (auto it : cur[u.sec]) {
                cur[v].ins(it);
            }
        }
    }
    else {
        for (auto u : mp[v]) {
            dfs(u.sec, cur_h + 1);
            dp[v] += dp[u.sec];
            for (auto it : cur[u.sec]) {
                cur[v].ins(it);
            }
        }
        if (!cur[v].empty()) {
            int val = *(--cur[v].end());
            dp[v] -= val;
            cur[v].ers(--cur[v].end());
            dp[v] += cur_h;
            cur[v].ins(cur_h);
        }
    }
}

_ void source() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s);
    }
    int ans = 0;
    for (auto u : mp[root]) {
        dfs(u.sec, 1);
        ans += dp[u.sec];
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