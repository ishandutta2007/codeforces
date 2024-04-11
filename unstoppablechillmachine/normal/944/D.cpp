#include <bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast", "no-stack-protector")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "tune=native", "abm")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define rsz resize
//#define int ll
#define forn(i, n) for (int i(1); i <= n; i++)
#define fore(i, n) for (int i(0); i < n; i++)

#define next nextt
#define prev prevv
#define left leftt
#define right rightt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const ll BINF = 1e18 + 10;
const ld EPS = 1e-6;

mt19937 Random(int(time(0)));

const int lim = 26 * 26 + 25;

int cnt[5010][lim + 10];
int f[26], sum[26][5010];
ld ver[26];

_ int get_num(char a, char b) {
    int aa = a - 'a', bb = b - 'a';
    return aa * 26 + bb;
}

_ void source() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int first_letter = int(s[0] - 'a');
        f[first_letter]++;
        for (int j = 1; j < n; j++) {
            int p = get_num(s[0], s[j]);
            //cout << first_letter << ' ' << j << ' ' << p << endl;
            cnt[j][p]++;
        }
        char ch = s[0];
        s.ers(s.begin());
        s += ch;
    }
    for (int i = 0; i < 26; i++) {
        ver[i] = ld(f[i]) / ld(n);
        //cout << ver[i] << endl;
    }
    ld ans = 0;
    for (int first_letter = 0; first_letter < 26; first_letter++) {
        if (!f[first_letter]) {
            continue;
        }
        int mx = 0, l = first_letter * 26, r = first_letter * 26 + 25;
        for (int pos = 1; pos < n; pos++) {
            int cur = 0;
            for (int i = l; i <= r; i++) {
                if (cnt[pos][i] == 1) {
                    cur++;
                }
            }
            mx = max(mx, cur);
        }
        ans += ver[first_letter] * ld(mx) / ld(f[first_letter]);
    }
    cout << fixed << setprecision(10) << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}