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

int n, m, k;

pair<int, int> next(int a, int b) {
    if (b + 2 > m) {
        return mk(a + 1, 1);
    }
    else {
        return mk(a, b + 2);
    }
}

_ void source() {
    cin >> n >> m >> k;
    int need = n * m;
    if (k == 1) {
        cout << n * m << ' ';
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                for (int j = 1; j <= m; j++) {
                        cout << i << ' ' << j << ' ';
                }
            }
            else {
                for (int j = m; j >= 1; j--) {
                    cout << i << ' ' << j << ' ';
                }
            }
        }
        exit(0);
    }
    if (m & 1) {
        if (need - n >= 2 * (k - 1)) {
            cout << n << ' ';
            for (int i = 1; i <= n; i++) {
                cout << i << ' ' << m << ' ';
            }
            need -= n;
            m--;
            k--;
            cout << endl;
        }
    }
    int cur = 0;
    pair<int, int> start = mk(1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + 1 <= m; j += 2) {
            if (cur == k - 1) {
                break;
            }
            start = next(i, j);
            cout << 2 << ' ' << i << ' ' << j << ' ' << i << ' ' << j + 1 << endl;
            need -= 2;
            cur++;
        }
    }
    if (cur < k - 1) {
        int last = 1;
        while (cur < k - 1) {
            cout << 2 << ' ' << last << ' ' << m << ' ' << last + 1  << ' ' << m << endl;
            last += 2;
            cur++;
            need -= 2;
        }
        cout << need << ' ';
        for (int i = last; i <= n; i++) {
            cout << i << ' ' << m << ' ';
        }
        exit(0);
    }
    cout << need << ' ';
    for (int j = start.sec; j <= m; j++) {
        cout << start.f << ' ' << j << ' ';
    }
    for (int i = start.f + 1; i <= n; i++) {
        if (i % 2 == start.f % 2) {
            for (int j = 1; j <= m; j++) {
                cout << i << ' ' << j << ' ';
            }
        }
        else {
            for (int j = m; j >= 1; j--) {
                cout << i << ' ' << j << ' ';
            }
        }
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