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

bool check(string s) {
    int cnt = 0, last = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'F') {
            cnt++;
            last = i + 1;
        }
    }
    return cnt == last;
}

int slow_solve(string s) {
    for (int i = 0;; i++) {
        if (check(s)) {
            return i;
        }
        string ns = s;
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == 'F' && s[j - 1] == 'M') {
                swap(ns[j], ns[j - 1]);
            }
        }
        s = ns;
    }
}

int fast_solve(string s) {
    while (!s.empty() && s.back() == 'M') {
        s.ers(--s.end());
    }
    if (s.empty()) {
        return 0;
    }
    int res = 0;
    for (auto it : s) {
        if (it == 'M') {
            res++;
        }
    }
    reverse(all(s));
    while (!s.empty() && s.back() == 'F') {
        s.ers(--s.end());
    }
    reverse(all(s));
    if (s.empty()) {
        return res;
    }
    int prev_ans = 0, cntm = 0;
    bool was_f = 0;
    for (auto it : s) {
        if (it == 'F') {
            if (was_f) {
                prev_ans = max(0, prev_ans - cntm + 1);
            }
            was_f = true;
            cntm = 0;
        }
        else {
            cntm++;
        }
    }
    return res + prev_ans;
}

_ void source() {
    string s;
    cin >> s;
    cout << fast_solve(s);
    /*string s;
    int T = 100;
    for (int i = 0; i < T; i++) {
        if (!i) {
            cin >> s;
        }
        else {
            s.clear();
            for (int j = 0; j < 10; j++) {
                if (Random() & 1) {
                    s += "F";
                }
                else {
                    s += "M";
                }
            }
        }
        if (fast_solve(s) != slow_solve(s)) {
            cout << "ERROR" << endl;
            cout << "TEST " << s << endl;
            cout << "CORRECT ANSWER " << slow_solve(s) << endl;
            cout << "MY ANSWER " << fast_solve(s);
            exit(0);
        }
    }*/
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