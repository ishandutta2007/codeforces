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

const int N = 110;

struct st {
    int f, sec, num;
};

bool cmp(st a, st b) {
    return a.f < b.f || (a.f == b.f && a.sec > b.sec);
}

st arr[N];
int ans[N];
_ void source() {
    int n, m, k, a, g;
    cin >> n >> k >> m >> a;
    int cur = m - a;
    for (int i = 1; i <= a; i++) {
        cin >> g;
        arr[g].f++;
        arr[g].sec = i;
    }
    for (int i = 1; i <= n; i++) {
        arr[i].num = i;
    }
    sort(arr + 1, arr + n + 1, cmp);
    int lim = arr[n - k + 1].f;
    for (int i = 1; i <= n; i++) {
        if ((!cur && !arr[i].f) || (i < (n - k + 1) && arr[i].f + cur <= lim)) {
            ans[arr[i].num] = 3;
            continue;
        }
        if (i < (n - k + 1) || arr[i].f == 0) {
            ans[arr[i].num] = 2;
            continue;
        }
        if (k == n) {
            ans[arr[i].num] = 1;
            continue;
        }
        int sum = 0;
        for (int j = i - 1; j >= n - k; j--) {
            sum += (arr[i].f - arr[j].f + 1);
        }
        if (sum <= cur) {
            ans[arr[i].num] = 2;
        }
        else {
            ans[arr[i].num] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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