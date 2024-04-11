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

const int N = 1e6 + 10;
const int lim = 20;

int C[N + 5][lim + 5], cnt, n, m;

_ void gen(int cur_sum, int pos) {
    if (!cur_sum) {
        cnt = (cnt + (C[m][pos - 1])) % MOD;
        return;
    }
    if (pos > m) {
        return;
    }
    for (int i = 1; i <= cur_sum; i++) {
        gen(cur_sum - i, pos + 1);
    }
}

int bpow(int b) {
    if (!b) {
        return 1;
    }
    if (b & 1) {
        int cur = bpow(b / 2);
        return (cur * cur * 2) % MOD;
    }
    else {
        int cur = bpow(b / 2);
        return (cur * cur) % MOD;
    }
}

_ int solve(int a, int b) {
    int a2 = a, res = 1;
    vector<int> arr;
    for (int i = 2; i <= sqrt(a2); i++) {
        int cur = 0;
        while (a2 % i == 0) {
            a2 /= i;
            cur++;
        }
        if (cur) {
            arr.pb(cur);
        }
    }
    if (a2 != 1) {
        arr.pb(1);
    }
    for (auto it : arr) {
        cnt = 0;
        gen(it, 1);
        res = (res * cnt) % MOD;
    }
    return (res * bpow(m - 1)) % MOD;
}

_ void source() {
    for (int i = 1; i <= N; i++) {
        C[i][1] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= min(i, lim); j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> m;
        cout << solve(n, m) << endl;
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