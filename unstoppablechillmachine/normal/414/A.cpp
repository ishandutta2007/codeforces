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

const int N = 5010;
pair<int, int> row[N], st[N];

_ void source() {
    int lim = 2e6;
    vector<bool> prime(2e6 + 10, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= lim; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= lim; j += i) {
                prime[j] = false;
            }
        }
    }
    vector<int> arr;
    for (int i = 2; i <= lim; i++) {
        if (prime[i]) {
            arr.pb(i);
        }
    }
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        if (k == 0) {
            cout << 1;
        }
        else {
            cout << -1;
        }
        exit(0);
    }
    if (n / 2 > k) {
        cout << -1;
        exit(0);
    }
    int cnt = n / 2 - 1;
    cout << k - cnt << ' ' << (k - cnt) * 2 << ' ';
    for (int i = 3; i <= n; i++) {
        if (arr[i] == k - cnt || arr[i] == (k - cnt) * 2) {n++;}else cout << arr[i] << ' ';
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