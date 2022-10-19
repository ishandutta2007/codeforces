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
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 1e5 + 10;

int arr[N], dp[75][(1 << 19) + 10], pw[N];

bool prime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

_ void source() {
    pw[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        pw[i] = (pw[i - 1] * 2) % MOD;
    }
    vector<int> p, calc(100);
    for (int i = 2; i <= 70; i++) {
        if (prime(i)) {
            p.pb(i);
        }
    }
    for (int i = 1; i <= 70; i++) {
        int c = 0;
        for (int j = 0; j < p.size(); j++) {
            int a = i, sum = 0;
            while (a % p[j] == 0) {
                sum++;
                a /= p[j];
            }
            if (sum % 2) c |= (1 << j);
        }
        calc[i] = c;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    vector<pair<int, int> > cur;
    for (int i = 1; i <= n; i++) {
        if (cur.empty() || arr[i] != cur.back().f) {
            cur.pb(mk(arr[i], 1));
        }
        else {
            int a = cur.size();
            cur[a - 1].sec++;
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < cur.size(); i++) {
        for (int mask = 0; mask < (1 << 19); mask++) {
            dp[i + 1][mask] = (1LL * dp[i + 1][mask] + 1LL * dp[i][mask] * pw[cur[i].sec - 1]) % MOD;
            dp[i + 1][mask ^ calc[cur[i].f]] = (1LL * dp[i + 1][mask ^ calc[cur[i].f]] + 1LL * dp[i][mask] * pw[cur[i].sec - 1]) % MOD;
        }
    }
    cout << (dp[int(cur.size())][0] - 1 + MOD) % MOD;
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