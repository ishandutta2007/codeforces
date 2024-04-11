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

int l[N];
vector<int> arr;

int get(int val, int k, int x) {
    int res = val + x * k - val % x;
    if (val % x == 0) {
        res -= x;
    }
    return res;
}

_ void source() {
    int n, x, k;
    cin >> n >> x >> k;
    arr.rsz(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    l[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] == arr[i + 1]) {
            l[i] = l[i + 1];
        }
        else {
            l[i] = i + 1;
            if ((arr[i + 1] % x == 0 && k == 1) || (arr[i + 1] % x && !k)) ans += (l[i + 1] - (i + 1)) * (l[i + 1] - (i + 1));
        }
    }
    if ((arr[0] % x == 0 && k == 1) || (arr[1] % x && !k)) ans += l[0] * l[0];
    for (int i = 0; i < n; i++) {
        int cur_l = max(l[i], int(lower_bound(all(arr), get(arr[i], k, x)) - arr.begin())),
        cur_r = upper_bound(all(arr), get(arr[i], k + 1, x) - 1) - arr.begin() - 1;
        ans += max(ll(0), cur_r - cur_l + 1);
    }
    cout << ans << endl;
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