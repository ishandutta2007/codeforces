#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-9;

int hs[2010][2010], hs2[2010][2010], p_pow[2010 * 2010], n, m;

_ int get_hash1(int a, int b, int a2, int b2) {
    return (hs[a2][b2] - hs[a2][b - 1] - hs[a - 1][b2] + hs[a - 1][b - 1]) * p_pow[n * m - ((a2 - 1) * m + b2)];
}

_ int get_hash2(int a, int b, int a2, int b2) {
    return (hs2[a2][b2] - hs2[a2][b - 1] - hs2[a - 1][b2] + hs2[a - 1][b - 1]) * p_pow[n * m - ((b2 - 1) * m + a2)];
}

_ void source() {
    p_pow[0] = 1;
    for (int i = 1; i <= 2000 * 2000; i++) {
        p_pow[i] = p_pow[i - 1] * P;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            hs[i][j] = hs[i][j - 1] + (ch - 'a' + 1) * p_pow[(i - 1) * m + j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            hs[i][j] += hs[i - 1][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            hs2[i][j] = hs2[i - 1][j] + (ch - 'a' + 1) * p_pow[1 + m * (i - 1)];
        }
    }
    int start = 0;
    int cur_pow = m - 1;
    for (int i = n; i >= n - m + 1; i--) {
        start += hs2[m][i] * p_pow[cur_pow];
        cur_pow--;
    }
    for (int i = 1; i + m - 1 <= n; i++) {
        int cur_hash = start;
        if (get_hash1(i, 1, i + m - 1, m) == cur_hash * p_pow[n * m - m * m]) {
            cout << i << ' ' << n - m + 1;
            exit(0);
        }
        for (int j = n - m; j >= 1; j--) {
            cur_hash -= hs2[m][j + m] * p_pow[m - 1];
            cur_hash = cur_hash * P + hs2[m][j];
            if (get_hash1(i, 1, i + m - 1, m) == cur_hash * p_pow[n * m - m * m]) {
                cout << i << ' ' << j;
                exit(0);
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
    source();
    return 0;
}