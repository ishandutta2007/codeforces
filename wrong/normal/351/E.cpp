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

int dp[2048][2048];

int main()
{
    int n, P[2048];
    pair<int, int> Q[2048];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
        Q[i] = make_pair(P[i] = abs(P[i]), i);
    }

    for (int i = 0; i < 2048; ++i) {
        for (int j = 0; j < 2048; ++j) {
            dp[i][j] = INF;
        }
    }

    sort(Q, Q + n);
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        int pi = Q[i].second;
        bool next_same = (i + 1 < n) && (Q[i + 1].first == Q[i].first);
        
        int same = 0;
        for (int j = 0; j < pi; ++j) {
            if (P[pi] == P[j]) {
                ++same;
            }            
        }

        int prec = 0, behind = 0;
        for (int j = 0; Q[j].first != Q[i].first; ++j) {
            int pj = Q[j].second;
            if (pi < pj) ++behind;
            else ++prec;
        }

        for (int j = 0; j <= same; ++j) {
            chmin(dp[i + 1][next_same ? j + 1 : 0], dp[i][j] + behind);
            chmin(dp[i + 1][next_same ? j : 0], dp[i][j] + prec + j);
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}