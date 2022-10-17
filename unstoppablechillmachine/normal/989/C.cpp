#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

char ans[55][55];
bool used[55][55];

vector<pair<int, int> > delta = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(int a, int b) {
    used[a][b] = true;
    for (auto it : delta) {
        int a2 = a + it.f, b2 = b + it.sec;
        if (!used[a2][b2] && ans[a][b] == ans[a2][b2]) {
            dfs(a2, b2);
        }
    }
}

void solve(int a, int b, int c, int d, char kek) {
    int cur1 = 1, cur2 = 1, cnt;
    if (kek == 'A') {
        cnt = a;
    }
    else if (kek == 'B') {
        cnt = b;
    }
    else if (kek == 'C') {
        cnt = c;
    }
    else {
        cnt = d;
    }
    bool was = false;
    if (cnt > 1) {
        was = true;
    }
    while (cnt > 1) {
        bool t = false;
        vector<char> have = {'A', 'B', 'C', 'D'};
        do {
            ans[cur1][cur2] = have[0];
            ans[cur1 + 1][cur2] = have[1];
            ans[cur1 + 2][cur2] = have[2];
            ans[cur1 + 3][cur2] = have[3];
            t = true;
            for (int i = cur1; i < cur1 + 4; i++) {
                if (ans[i][cur2] == ans[i][cur2 - 1] || ans[i][cur2] == ans[i - 1][cur2]) {
                    t = false;
                    break;
                }
            }
            if (t) {
                break;
            }
        } while (next_permutation(all(have)));
        assert(t);
        cnt--;
        if (cur1 == 45) {
            ans[50][cur2] = ans[49][cur2] = ans[48][cur2];
            cur2++;
            cur1 = 1;
        }
        else {
            cur1 += 4;
        }
    }
    char lol;
    if (kek != 'A') {
        lol = 'A';
    }
    else if (kek != 'B') {
        lol = 'B';
    }
    else if (kek != 'C') {
        lol = 'C';
    }
    else if (kek != 'D') {
        lol = 'D';
    }
    if (was) {
        if (cur1 > 1) {
            for (int i = cur1; i <= 50; i++) {
                ans[i][cur2] = lol;
            }
            cur2++;
        }
        for (int i = 1; i <= 50; i++) {
            ans[i][cur2] = lol;
        }
        cur2++;
        for (int i = 1; i <= 50; i++) {
            ans[i][cur2] = kek;
        }
        cur2++;
    }
    for (int j = 1; j <= cur2; j++) {
        for (int i = 1; i <= 50; i++) {
            if (!used[i][j] && isalpha(ans[i][j])) {
                dfs(i, j);
                if (ans[i][j] == 'A') {
                    a--;
                }
                if (ans[i][j] == 'B') {
                    b--;
                }
                if (ans[i][j] == 'C') {
                    c--;
                }
                if (ans[i][j] == 'D') d--;
            }
        }
    }
    //cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    for (int j = cur2; j <= 50; j++) {
        for (int i = 1; i <= 50; i++) {
            if (j % 2 == cur2 % 2) {
                if (i & 1) {
                    ans[i][j] = kek;
                }
                else {
                    if ('A' != kek && a) {
                        ans[i][j] = 'A';
                        a--;
                    }
                    else if ('B' != kek && b) {
                        ans[i][j] = 'B';
                        b--;
                    }
                    else if ('C' != kek && c) {
                        ans[i][j] = 'C';
                        c--;
                    }
                    else if ('D' != kek && d) {
                        ans[i][j] = 'D';
                        d--;
                    }
                    else {
                        ans[i][j] = kek;
                    }
                }
            }
            else {
                ans[i][j] = kek;
            }
        }
    }
}

_ void source() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b && a <= c && a <= d) {
        solve(a, b, c, d, 'A');
    }
    else if (b <= a && b <= c && b <= d) {
        solve(a, b, c, d, 'B');
    }
    else if (c <= a && c <= b && c <= d) {
        solve(a, b, c, d, 'C');
    }
    else {
        solve(a, b, c, d, 'D');
    }
    cout << 50 << ' ' << 50 << endl;
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            cout << ans[i][j];
        }
        cout << endl;
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
    source();
    return 0;
}