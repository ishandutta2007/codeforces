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

int dp[1010][11][11];
pair<int, int> from[1010][11][11];

_ void source() {
    int m;
    vector<int> arr;
    for (int i = 1; i <= 10; i++) {
        char ch;
        cin >> ch;
        if (ch == '1') {
            arr.pb(i);
            dp[1][i][i] = true;
        }
    }
    cin >> m;
    for (int i = 1; i < m; i++) {
        for (int last = 1; last <= 10; last++) {
            for (int delta = 1; delta <= 10; delta++) {
                if (!dp[i][last][delta]) {
                    continue;
                }
                for (auto &it : arr) {
                    if (it != last && it > delta) {
                        dp[i + 1][it][it - delta] = true;
                        from[i + 1][it][it - delta] = mk(last, delta);
                    }
                }
            }
        }
    }
    pair<int, int> now = mk(0, 0);
    vector<int> ans;
    for (int last = 1; last <= 10; last++) {
        for (int delta = 1; delta <= 10; delta++) {
            if (dp[m][last][delta]) {
                now = mk(last, delta);
            }
        }
    }
    if (!now.f) {
        cout << "NO";
        exit(0);
    }
    cout << "YES" << endl;
    for (int i = m; i >= 1; i--) {
        ans.pb(now.f);
        now = from[i][now.f][now.sec];
    }
    reverse(all(ans));
    for (auto &it : ans){
        cout << it << ' ';
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