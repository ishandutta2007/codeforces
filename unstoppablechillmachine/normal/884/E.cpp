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

const int N = (1 << 15) + 10;

int p[N], rk[N];

_ void make(int v) {
    p[v] = v;
    rk[v] = 1;
}

_ int find(int v) {
    if (p[v] == v) {
        return v;
    }
    return p[v] = find(p[v]);
}

_ bool merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
        return false;
    }
    if (rk[a] < rk[b]) {
        swap(a, b);
    }
    else if (rk[a] == rk[b]) {
        rk[a]++;
    }
    p[b] = a;
    return true;
}

_ void source() {
    int n, m, ans = 0;
    vector<int> arr[2];
    cin >> n >> m;
    int lim = m / 4, a = 0, lim2 = 2 * m;
    for (int i = 1; i <= lim; i++) {
        char ch;
        int pp;
        cin >> ch;
        if (ch <= '9') {
            pp = ch - '0';
        }
        else {
            pp = ch - 'A' + 10;
        }
        for (int j = 3; j >= 0; j--) {
            int ppp = (pp >> j) & 1;
            if (ppp) {
                ans++;
            }
            arr[1].pb(ppp);
            a++;
            make(a + m);
        }
    }
    for (int i = 1; i < m; i++) {
        if (arr[1][i] && arr[1][i - 1]) {
            ans -= merge(i + m, i + m + 1);
        }
    }
    for (int i = 2; i <= n; i++) {
        int col[lim2 + 10];
        vector<int> now(lim2 + 10, 0);
        for (int j = m + 1; j <= lim2; j++) {
            col[j] = find(j);
        }
        for (int j = 1; j <= lim2; j++) {
            make(j);
        }
        for (int j = 1; j <= m; j++) {
            if (!arr[1][j - 1]) {
                continue;
            }
            if (now[col[j + m]]) {
                merge(j, now[col[j + m]]);
            }
            else {
                now[col[j + m]] = j;
            }
        }
        arr[0] = arr[1];
        arr[1].clear();
        for (int j = 0; j < lim; j++) {
            char ch;
            int pp;
            cin >> ch;
            if (ch <= '9') {
                pp = ch - '0';
            }
            else {
                pp = ch - 'A' + 10;
            }
            for (int k = 3; k >= 0; k--) {
                int ppp = (pp >> k) & 1;
                if (ppp) {
                    ans++;
                }
                arr[1].pb(ppp);
            }
        }
        if (arr[0][0] && arr[1][0]) {
            ans -= merge(1, m + 1);
        }
        for (int j = 1; j < m; j++) {
            if (!arr[1][j]) {
                continue;
            }
            if (arr[0][j]) {
                ans -= merge(j + 1, j + m + 1);
            }
            if (arr[1][j - 1]) {
                ans -= merge(j + m, j + m + 1);
            }
        }
    }
    cout << ans;
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