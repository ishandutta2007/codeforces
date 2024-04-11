#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

int getsum() {return 0;}
int getmax() {return -INF;}
int getmin() {return INF;}
template<typename Arg, typename... Args>
int getsum(Arg first, Args... rest) {
    return first + getsum(rest...);
}
template<typename Arg, typename... Args>
int getmax(Arg first, Args... rest) {
    return max(first, getmax(rest...));
}
template<typename Arg, typename... Args>
int getmin(Arg first, Args... rest) {
    return min(first, getmin(rest...));
}

const int N = 3e5 + 10;
const int root = 1;
map<char, int> mp[N];
int f[N], cnt = 1, en[N];

void add(string s) {
    vector<int> arr;
    int v = root;
    for (int i = 0; i < s.size(); i++) {
        if (!mp[v][s[i]]) {
            cnt++;
            mp[v][s[i]] = cnt;
        }
        v = mp[v][s[i]];
        arr.pb(v);
    }
    en[v] = true;
    reverse(all(arr));
    for (auto it : arr) {
        f[it] = en[it];
        for (auto it2 : mp[it]) {
            f[it] += f[it2.sec];
        }
    }
}

string go(int v) {
    string res;
    while (!mp[v].empty()) {
        char ch = mp[v].begin()->f;
        res += ch;
        v = mp[v][ch];
    }
    return res;
}

_ int get(string s) {
    int v = root, res = 0;
    string pref;
    for (int i = 0; i < s.size(); i++) {
        if (mp[v].find(s[i]) == mp[v].end()) {
            add(s);
            return int(s.size());
        }
        v = mp[v][s[i]];
        pref += s[i];
        res++;
        if (f[v] == 1) {
            string ss;
            for (int j = 0; j <= i; j++) {
                ss += s[j];
            }
            ss += go(v);
            bool t = true;
            if (ss.size() > s.size()) {
                add(s);
                return int(s.size());
            }
            for (int j = 0; j < ss.size(); j++) {
                if (s[j] != ss[j]) {
                    t = false;
                    break;
                }
            }
            if (t) {
                add(s);
                res++;
                res += int(s.size()) - int(ss.size());
                return min(res, int(s.size()));
            }
            else {
                add(s);
                return int(s.size());
            }
        }
    }
    add(s);
    return int(s.size());
}

_ void source() {
    string s;
    int ans = 0;
    while (cin >> s) {
        ans++;
        string cur;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                cur += s[i];
            }
            else {
                if (!cur.empty()) {
                    int a = get(cur);
                    //cout << cur << ' ' << a << endl;
                    ans += a;
                }
                cur.clear();
                ans++;
            }
        }
        if (!cur.empty()) {
            int a = get(cur);
            //cout << cur << ' ' << a << endl;
            ans += a;
        }
    }
    cout << ans << endl;
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