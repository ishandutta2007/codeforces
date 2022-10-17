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

mt19937 Random((int)time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const long long BINF = 1e18 + 10;

const int N = 1510;

int pref[N][N], dp[N][N];

_ void source() {
    int n;
    cin >> n;
    vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j - 1] + (pos[j] <= i);
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r] = (dp[l + 1][r] + pref[r][arr[l]] - pref[l][arr[l]]) & 1;
        }
    }
    int cur = dp[1][n], m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        cur = (cur + len * (len - 1) / 2 - 2 * dp[l][r] + 100) & 1;
        cout << (cur ? "odd" : "even") << endl;
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