#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

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

const int N = 2010;
int dp[N][10][10][10], have[10];
pair<int, int> arr[N];

_ int solve(int start, int to1, int to2, int to3, int to4) {
    vector<int> cur;
    for (int j = 0; j < 10; j++) {
        have[j] = 0;
    }
    have[to1]++;
    have[to2]++;
    have[to3]++;
    have[to4]++;
    for (int i = 1; i < 10; i++) {
        if (have[i]) {
            cur.pb(i);
        }
    }
    int res = INF;
    do {
        int prev = start, cur_sum = 0;
        for (auto it : cur) {
            //cout << it << endl;
            cur_sum += abs(prev - it) + have[it];
            prev = it;
        }
        res = min(res, cur_sum);
    } while (next_permutation(all(cur)));
    return res;
}

_ void source() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].f >> arr[i].sec;
    }
    for (int i = 0; i <= n; i++) {
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                for (int c = 0; c < 10; c++) {
                    dp[i][a][b][c] = INF;
                }
            }
        }
    }
    dp[1][0][0][0] = arr[1].f;
    for (int i = 0; i < n; i++) {
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                for (int c = 0; c < 10; c++) {
                    if (dp[i][a][b][c] == INF) {
                        continue;
                    }
                    //cout << dp[i][a][b][c] << ' ' << i << ' ' << a << ' ' << b << ' ' << c << endl;
                    int d = arr[i].sec, e = arr[i + 1].f;
                    for (int j = 0; j < 10; j++) {
                        have[j] = 0;
                    }
                    //cout << i << ' ' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
                    have[a]++;
                    have[b]++;
                    have[c]++;
                    have[d]++;
                    have[e]++;
                    vector<int> cur;
                    int sz = 0;
                    for (int j = 1; j < 10; j++) {
                        if (have[j]) {
                            cur.pb(j);
                            sz += have[j];
                        }
                    }
                    do {
                        int prev = arr[i].f;
                        if (cur[0] == e && sz - have[e] >= 4) {
                            continue;
                        }
                        int cur_sz = sz, cur_sum = dp[i][a][b][c];
                        for (int k = 0; k < cur.size(); k++) {
                            cur_sum += abs(prev - cur[k]) + have[cur[k]];
                            prev = cur[k];
                            if (cur[k] == e) {
                                int to_sz = cur_sz - have[e] + 1;
                                if (to_sz == 1) {
                                    dp[i + 1][0][0][0] = min(dp[i + 1][0][0][0], cur_sum);
                                }
                                else if (to_sz == 2) {
                                    dp[i + 1][0][0][cur.back()] = min(dp[i + 1][0][0][cur.back()], cur_sum);
                                }
                                else if (to_sz == 3) {
                                    if (k + 1 == cur.size())  {
                                        dp[i + 1][0][cur.back()][cur.back()] = min(dp[i + 1][0][cur.back()][cur.back()], cur_sum);
                                    }
                                    else {
                                        dp[i + 1][0][cur[k + 1]][cur.back()] = min(dp[i + 1][0][cur[k + 1]][cur.back()], cur_sum);
                                    }
                                }
                                else {
                                    if (k + 2 == cur.size())  {
                                        dp[i + 1][cur.back()][cur.back()][cur.back()] = min(dp[i + 1][cur.back()][cur.back()][cur.back()], cur_sum);
                                    }
                                    else if (k + 4 == cur.size()) {
                                        dp[i + 1][cur[k + 1]][cur[k + 2]][cur[k + 3]] = min(dp[i + 1][cur[k + 1]][cur[k + 2]][cur[k + 3]], cur_sum);
                                    }
                                    else {
                                        //cout << k + 2 << ' ' << cur.size() << endl;
                                        if (have[cur[k + 1]] == 1) {
                                            dp[i + 1][cur[k + 1]][cur[k + 2]][cur[k + 2]] = min(dp[i + 1][cur[k + 1]][cur[k + 2]][cur[k + 2]], cur_sum);
                                        }
                                        else {
                                            dp[i + 1][cur[k + 1]][cur[k + 1]][cur[k + 2]] = min(dp[i + 1][cur[k + 1]][cur[k + 1]][cur[k + 2]], cur_sum);
                                        }
                                    }
                                }
                                break;
                            }
                            cur_sz -= have[cur[k]];
                        }
                    } while (next_permutation(all(cur)));
                }
            }
        }
    }
    int ans = INF;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                if (dp[n][a][b][c] != INF) ans = min(ans, dp[n][a][b][c] + solve(arr[n].f, a, b, c, arr[n].sec));
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
    source();
    return 0;
}