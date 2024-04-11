#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

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
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long double EPS = 1e-9;
const long double PI = acos(-1);

string get(int n) {
    string res;
    while (n) {
        res += char('0' + n % 2);
        n /= 2;
    }
    reverse(all(res));
    return res;
}

int get2(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res *= 2;
        if (s[i] == '1') {
            res++;
        }
    }
    return res;
}

int solve(int l, int r) {
    int cur = -1, res = 0;
    for (int i = l; i <= r; i++) {
        if (__builtin_popcount(i) > cur) {
            cur = __builtin_popcount(i);
            res = i;
        }
    }
    return res;
}

int get_cnt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            res++;
        }
    }
    return res;
}

_ void source() {
    int t, l, r;
    cin >> t;
    //t = 10000;
    for (int i = 0; i < t; i++) {
        cin >> l >> r;
        //l = rand(), r = rand();
        if (l > r) {
            swap(l, r);
        }
        string s1 = get(l), s2 = get(r);
        int cur = get_cnt(s2), ans = r, a = s2.size();
        if (s1.size() != s2.size()) {
            if (a - 1 >= cur) {
                cur = a - 1;
                ans = (1LL << (a - 1)) - 1;
            }
            cout << ans << endl;
            continue;
        }
        for (int j = 0; j < a; j++) {
            if (s1[j] != s2[j]) {
                for (int j2 = j + 1; j2 <= a; j2++) {
                    s1[j2] = '1';
                }
                break;
            }
        }
        int now = get2(s1);
        if ((get_cnt(s1) > cur) || (get_cnt(s1) == cur && now < ans)) {
            ans = now;
        }
        cout << ans << endl;
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
    srand(time(0));
    source();
    return 0;
}