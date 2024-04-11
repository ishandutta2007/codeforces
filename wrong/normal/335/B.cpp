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

char S[50050];
vector<int> appear[26];

int pos[50050][64], prev[50050][64];

int main()
{
    ios::sync_with_stdio(false);
    cin >> S;

    const int N = strlen(S);
    for (int i = 0; i < N; ++i) {
        appear[S[i] - 'a'].push_back(i);
    }

    for (int i = 0; i <= 50; ++i) {
        pos[0][i] = -1;
    }
    pos[0][0] = N;

    int longest = 1, li = 0, lj = -1;
    for (int i = 0; i < N; ++i) {
        int c = S[i] - 'a';
        pos[i + 1][0] = N;
        for (int j = 1; j <= 50; ++j) {
            pos[i + 1][j] = pos[i][j];
            prev[i + 1][j] = 0;
            if (pos[i][j - 1] != -1) {
                int npos = lower_bound(appear[c].begin(), appear[c].end(), pos[i][j - 1]) - appear[c].begin();
                if (npos > 0 && appear[c][npos - 1] > i) {
                    if (pos[i + 1][j] < appear[c][npos - 1]) {
                        int len = 2 * j + (i + 1 < appear[c][npos - 1] ? 1 : 0);
                        if (len > longest) {
                            longest = len;
                            li = i + 1;
                            lj = j;
                        }
                        pos[i + 1][j] = appear[c][npos - 1];
                        prev[i + 1][j] = 1;
                    }
                }
            }
        }
        if (pos[i + 1][50] != -1) {
            char res[128];
            int cnt = 0;
            for (int ii = i + 1, jj = 50; ii > 0; ) {
                if (prev[ii][jj] == 0) {
                    --ii;
                } else {
                    res[50 - cnt - 1] = res[50 + cnt] = S[ii - 1];
                    --ii;
                    --jj;
                    ++cnt;
                }
            }
            res[100] = '\0';
            cout << res << endl;
            return 0;
        }
    }

    char res[128];
    int ptr = longest / 2 - 1;
    for (int ii = li, jj = lj; ii > 0; ) {
        if (prev[ii][jj] == 0) {
            --ii;
        } else {
            res[ptr--] = S[ii - 1];
            --ii;
            --jj;
        }
    }

    for (int i = 0; i < longest / 2; ++i) {
        cout << res[i];
    }
    if (longest % 2 == 1) {
        cout << S[li];
    }
    for (int i = longest / 2 - 1; i >= 0; --i) {
        cout << res[i];
    }
    cout << endl;

    return 0;
}