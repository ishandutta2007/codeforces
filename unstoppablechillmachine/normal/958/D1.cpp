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
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define endl "\n"

#define right rightt
#define left leftt
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-9;

map<ld, int> mp;

ld get(string s) {
    s.ers(s.begin());
    int a1 = 0, a2 = 0;
    while (s[0] != '+') {
        a1 = a1 * 10 + (s[0] - '0');
        s.ers(s.begin());
    }
    s.ers(s.begin());
    while (s[0] != ')') {
        a2 = a2 * 10 + (s[0] - '0');
        s.ers(s.begin());
    }
    s.ers(s.begin());
    s.ers(s.begin());
    int d = 0;
    for (int i = 0; i < s.size(); i++) {
        d = d * 10 + (s[i] - '0');
    }
    return ld(a1 + a2) / ld(d);
}

_ void source() {
    int n;
    cin >> n;
    vector<ld> val(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        val[i] = get(s);
        mp[val[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << mp[val[i]] << ' ';
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