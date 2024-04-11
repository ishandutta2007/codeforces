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
#define endl "\n"

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 2010;
int arr[N], pref[N][N];

_ void source() {
    int n, cnt = 0;
    cin >> n;
    forn(i, n) {
        cin >> arr[i];
        if (arr[i] == 1) {
            cnt++;
        }
    }
    if (cnt) {
        cout << n - cnt;
        exit(0);
    }
    for (int l = 1; l <= n; l++) {
        pref[l][l] = arr[l];
        for (int r = l + 1; r <= n; r++) {
            pref[l][r] = __gcd(pref[l][r - 1], arr[r]);
        }
    }
    int cur = INF;
    for (int len = 1; len <= n; len++) {
        if (cur < INF) {
            break;
        }
        for (int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            if (pref[l][r] == 1) {
                cur = min(cur, len);
                break;
            }
        }
    }
    if (cur >= INF) {
        cout << -1;
    }
    else {
        cout << cur + n - 2 << endl;
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