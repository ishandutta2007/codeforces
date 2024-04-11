//I_l_M_P
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
#define int ll
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

const int N = 1010;
bool arr1[N], arr2[N];
int dp[N][2][2];

bool get(char x) {
    return x == 'X';
}

_ void source() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    for (int i = 1; i <= n; i++) {
        arr1[i] = get(s1[i - 1]);
        arr2[i] = get(s2[i - 1]);
    }
    for (int i = 0; i <= n; i++) {
        for (int pos1 = 0; pos1 < 2; pos1++) {
            for (int pos2 = 0; pos2 < 2; pos2++) {
                dp[i][pos1][pos2] = -INF;
            }
        }
    }
    dp[0][arr1[1]][arr2[1]] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int pos1 = 0; pos1 < 2; pos1++) {
            for (int pos2 = 0; pos2 < 2; pos2++) {
                if (pos1 < arr1[i + 1] || pos2 < arr2[i + 1]) {
                    continue;
                }
                bool kek1 = (!pos1 && !pos2), kek2 = (!pos1|| !pos2);
                for (int pos3 = 0; pos3 < 2; pos3++) {
                    for (int pos4 = 0; pos4 < 2; pos4++) {
                        if (pos3 >= arr1[i + 2] && pos4 >= arr2[i + 2]) {
                            if (pos3 == arr1[i + 2] && pos4 == arr2[i + 2]) {
                                dp[i + 1][pos3][pos4] = max(dp[i + 1][pos3][pos4], dp[i][pos1][pos2]);
                            }
                            else if (pos3 > arr1[i + 2] && pos4 > arr2[i + 2]) {
                                dp[i + 1][pos3][pos4] = max(dp[i + 1][pos3][pos4], dp[i][pos1][pos2] + kek2);
                            }
                            else {
                                dp[i + 1][pos3][pos4] = max(dp[i + 1][pos3][pos4], dp[i][pos1][pos2] + kek1);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int pos1 = 0; pos1 < 2; pos1++) {
        for (int pos2 = 0; pos2 < 2; pos2++) {
            ans = max(ans, dp[n - 1][pos1][pos2]);
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
    source();
    return 0;
}