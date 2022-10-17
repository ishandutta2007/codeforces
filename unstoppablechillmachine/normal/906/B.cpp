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
const long double PI = acos(-1);

const int N = 1e5 + 10;

int n, m;
vector<vector<int> > arr;
set<int> sm[N];
bool check(vector<int> r) {
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] = r[cur];
            cur++;
        }
    }
    cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i > 1) {
                if (sm[r[cur]].find(arr[i - 1][j]) != sm[r[cur]].end()) {
                    return false;
                }
            }
            if (j > 1) {
                if (sm[r[cur]].find(arr[i][j - 1]) != sm[r[cur]].end()) {
                    return false;
                }
            }
            if (i < n) {
                if (sm[r[cur]].find(arr[i + 1][j]) != sm[r[cur]].end()) {
                    return false;
                }
            }
            if (j < m) {
                if (sm[r[cur]].find(arr[i][j + 1]) != sm[r[cur]].end()) {
                    return false;
                }
            }
            cur++;
        }
    }
    return true;
}

void out(vector<int> r) {
    cout << "YES" << endl;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << r[cur] << ' ';
            cur++;
        }
        cout << endl;
    }
}

_ void source() {
    vector<int> r;
    cin >> n >> m;
    arr.rsz(n + 10);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        arr[i].rsz(m + 10);
        for (int j = 1; j <= m; j++) {
            cur++;
            arr[i][j] = cur;
        }
    }
    cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cur++;
            if (i > 1) {
                sm[cur].ins(arr[i - 1][j]);
            }
            if (j > 1) {
                sm[cur].ins(arr[i][j - 1]);
            }
            if (i < n) {
                sm[cur].ins(arr[i + 1][j]);
            }
            if (j < m) {
                sm[cur].ins(arr[i][j + 1]);
            }
        }
    }
    if (m % 2 == 0 && n != 1) {
        int L = 1, R = n * m;
        for (int i = 1; i <= n * m; i++) {
            if (i & 1) {
                r.pb(L);
                L++;
            }
            else {
                r.pb(R);
                R--;
            }
        }
        if (check(r)) {
            out(r);
            exit(0);
        }
    }
    else {
        int L = n * m - 1, R = n * m;
        if (L & 1) {
            swap(L, R);
        }
        while (L > 0) {
            r.pb(L);
            L -= 2;
        }
        while (R > 0) {
            r.pb(R);
            R -= 2;
        }
        if (check(r)) {
            out(r);
            exit(0);
        }
    }

    for (;;) {
        if (clock() / (double) CLOCKS_PER_SEC >= 1.9) {
            cout << "NO" << endl;
            exit(0);
        }
        random_shuffle(all(r));
        if (check(r)) {
            out(r);
            exit(0);
        }
    }
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