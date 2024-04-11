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
mt19937 rnd(0);

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-9;

const int N = 110;
bool arr[N][N];
int pref[N][N], pref2[N][N], sum[N][N];

_ int getsum1(int num, int l, int r) {
    return pref[num][r] - pref[num][l - 1];
}

_ int getsum2(int num, int up, int down) {
    return pref2[down][num] - pref2[up - 1][num];
}

_ void source() {
    int n, m, k;
    cin >> n >> k;
    m = n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            arr[i][j] = (ch == '#');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i][j - 1] + arr[i][j];
            pref2[i][j] = pref2[i - 1][j] + arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + k - 1 <= m; j++) {
            if (getsum1(i, j, j + k - 1) == 0) {
                for (int pp = j; pp <= j + k - 1; pp++) {
                    sum[i][pp]++;
                }
            }
        }
    }
    if (k != 1) {
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i + k - 1 <= n; i++) {
                if (getsum2(j, i, i + k - 1) == 0) {
                    for (int pp = i; pp <= i + k - 1; pp++) {
                        sum[pp][j]++;
                    }
                }
            }
        }
    }
    pair<int, pair<int, int> > best;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            best = max(best, mk(sum[i][j], mk(i, j)));
        }
    }
    cout << best.sec.f << ' ' << best.sec.sec;
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