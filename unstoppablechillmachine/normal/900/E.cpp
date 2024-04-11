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
#define int ll
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

const int N = 1e5 + 10;

int pr[N][3][3], pref[N];

pair<int, int> get(pair<int, int> a, pair<int, int> b) {
    if (a.f != b.f) {
        return max(a, b);
    }
    return min(a, b);
}

bool check(int l, int r) {
    if (l % 2 == 0) {
        return pr[r][1][1] - pr[l - 1][1][1] + pr[r][2][2] - pr[l - 1][2][2] == 0;
    }
    return pr[r][1][2] - pr[l - 1][1][2] + pr[r][2][1] - pr[l - 1][2][1] == 0;
}

_ void source() {
    int n, k;
    string s;
    cin >> n >> s;
    s.ins(s.begin(), ' ');
    cin >> k;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i] == '?');
        pr[i][1][1] = pr[i - 1][1][1];
        pr[i][1][2] = pr[i - 1][1][2];
        pr[i][2][1] = pr[i - 1][2][1];
        pr[i][2][2] = pr[i - 1][2][2];
        if (i & 1) {
            if (s[i] == 'a') {
                pr[i][1][1]++;
            }
            if (s[i] == 'b') {
                pr[i][2][1]++;
            }
        }
        else {
            if (s[i] == 'a') {
                pr[i][1][2]++;
            }
            if (s[i] == 'b') {
                pr[i][2][2]++;
            }
        }
    }
    vector<pair<int, int> > dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = mk(-INF, INF);
    }
    dp[0] = mk(0, 0);
    for (int i = 0; i < n; i++) {
        //cout << dp[i].f << ' ' << dp[i].sec << endl;
        dp[i + 1] = get(dp[i + 1], dp[i]);
        if (i + k <= n && check(i + 1, i + k)) {
            //cout << i << endl;
            dp[i + k] = get(dp[i + k], mk(dp[i].f + 1, dp[i].sec + pref[i + k] - pref[i]));
        }
    }
    cout << dp[n].sec;
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