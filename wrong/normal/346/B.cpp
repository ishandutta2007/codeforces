#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int dp[111][111][111];
int prev[111][111][111][3];
string S[2], V;

int next[111][26];
int next_pos[111][26];

int main()
{
    cin >> S[0] >> S[1] >> V;

    for (int i = 0; i <= V.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            string tmp = V.substr(0, i) + string(1, 'A' + j);
            next[i][j] = 0;
            for (int k = 1; k <= tmp.size(); ++k) {
                if (tmp.substr(tmp.size() - k) == V.substr(0, k)) {
                    next[i][j] = k;
                }
            }
        }
    }

    for (int i = 0; i < S[1].size(); ++i) {
        for (int j = 0; j < 26; ++j) {
            next_pos[i][j] = -1;
            for (int k = i; k < S[1].size(); ++k) {
                if (S[1][k] == 'A' + j) {
                    next_pos[i][j] = k;
                    break;
                }
            }
        }
    }

    memset(dp, ~0, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i < S[0].size(); ++i) {
        for (int j = 0; j < S[1].size(); ++j) {
            for (int k = 0; k < V.size(); ++k) {
                if (~dp[i][j][k]) {
                    for (int ni = i; ni < S[0].size(); ++ni) {
                        if (next_pos[j][S[0][ni] - 'A'] >= 0) {
                            int nj = next_pos[j][S[0][ni] - 'A'];
                            int &target = dp[ni + 1][nj + 1][next[k][S[0][ni] - 'A']];
                            int val = dp[i][j][k] + 1;
                            if (target < val) {
                                target = val;
                                prev[ni + 1][nj + 1][next[k][S[0][ni] - 'A']][0] = i;
                                prev[ni + 1][nj + 1][next[k][S[0][ni] - 'A']][1] = j;
                                prev[ni + 1][nj + 1][next[k][S[0][ni] - 'A']][2] = k;
                            }
                        }
                    }
                }
            }
        }
    }

    int res_len = 0;
    int res_i, res_j, res_k;
    for (int i = 1; i <= S[0].size(); ++i) {
        for (int j = 1; j <= S[1].size(); ++j) {
            for (int k = 0; k < V.size(); ++k) {
                if (res_len < dp[i][j][k]) {
                    res_len = dp[i][j][k];
                    res_i = i; res_j = j; res_k = k;
                }
            }
        }
    }

    if (res_len == 0) {
        cout << 0 << endl;
    } else {
        char sol[111];
        sol[res_len] = '\0';
        for (int i = res_i, j = res_j, k = res_k, p = res_len - 1; p >= 0; --p) {
            sol[p] = S[0][i - 1];
            int ii = prev[i][j][k][0], jj = prev[i][j][k][1], kk = prev[i][j][k][2];
            i = ii; j = jj; k = kk;
        }
        cout << sol << endl;
    }

    return 0;
}