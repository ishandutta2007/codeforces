#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

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

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const long double PI = acos(-1);

_ void source() {
    int mask = (1 << 26) - 1;
    int n, sum = 0;
    bool t = false;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (t) {
            if (s1 == "!" || (s1 == "?" && i < n)) {
                sum++;
            }
        }
        if (s1 == ".") {
            for (int j = 0; j < s2.size(); j++) {
                int pp = s2[j] - 'a';
                if ((mask >> pp) & 1) {
                    mask ^= (1 << pp);
                }
            }
        }
        else if (s1 == "!") {
            int cur = 0;
            for (int j = 0; j < s2.size(); j++) {
                int pp = s2[j] - 'a';
                cur |= (1 << pp);
            }
            mask &= cur;
        }
        else {
            int pp = s2[0] - 'a';
            if ((mask >> pp) & 1) {
                mask ^= (1 << pp);
            }
        }
        if (__builtin_popcount(mask) == 1) {
            t = true;
        }
    }
    cout << sum;
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