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

const int N = 1e5 + 10;
int arr[N];
int f(int k) {
    return ((1LL << k) - 1) * (1LL << (k - 1));
}

_ void source() {
    int n, ans = 0;
    cin >> n;
    int cur = 1;
    while (f(cur) <= n) {
        arr[f(cur)] = true;
        cur++;
    }
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            if (arr[i]) {
                ans = max(ans, i);
            }
            if (arr[n / i]) {
                ans = max(ans, n / i);
            }
        }
    }
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    //freopen("input.txt", "r", stdin);
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