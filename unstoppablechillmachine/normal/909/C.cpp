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
const long long BINF = 1e18 + 10;

const int N = 5010;

int dp[N][N][2];

_ void source() {
    int n, ans = 0;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> p(n + 10, 0);
        for (int ot = 0; ot <= n; ot++) {
            //cout << i << ' ' << ot << ' ' << dp[i][ot][0] << ' ' << dp[i][ot][1] << endl;
            if (arr[i] == 's') {
                dp[i + 1][ot][1] = (((dp[i + 1][ot][1] + dp[i][ot][0]) % MOD) + dp[i][ot][1]) % MOD;
                if (ot) p[ot - 1] = ((p[ot - 1] + dp[i][ot][1]) % MOD + dp[i][ot][0]) % MOD;
            }
            else {
                dp[i + 1][ot + 1][0] = (((dp[i + 1][ot + 1][0] + dp[i][ot][1]) % MOD) + dp[i][ot][0]) % MOD;
                //if (ot) dp[i + 1][ot][0] = (dp[i + 1][ot][0] + dp[i][ot][1]) % MOD;
            }
        }
        int cur = 0;
        for (int j = n; j >= 0; j--) {
            cur = (cur + p[j]) % MOD;
            dp[i + 1][j][1] = (dp[i + 1][j][1] + cur) % MOD;
        }
    }
    cout << dp[n][0][1] << endl;
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