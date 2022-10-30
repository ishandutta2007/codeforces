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

int N, L;
int A[200050];

int dp[(1<<20) + 1], minv[21][1<<20], added;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        char a[22];
        cin >> a;
        L = strlen(a);

        A[i] = 0;
        for (int j = 0; j < L; ++j) {
            A[i] = (A[i] << 1) + a[j] - '0';
        }
    }

    const int NONE = 1<<L;

    for (int i = 0; i < (1<<L); ++i) {
        dp[i] = INF;
        for (int j = 0; j <= L; ++j) {
            minv[j][i] = INF;
        }
    }
    dp[NONE] = 0;
    minv[0][0] = 0;
    added = 0;

    for (int i = 0; i < N; ++i) {
        int cost = L;
        if (i > 0) {
            for (int j = 1; j <= L; ++j) {
                if ((A[i - 1] & ((1 << j) - 1)) == ((A[i] & (((1 << j) - 1) << (L - j))) >> (L - j))) {
                    cost = L - j;
                }
            }
        }
        added += cost;

        if (i == 0) {
            continue;
        }

        int mv = INF;
        chmin(mv, minv[0][0] + L + added);
        for (int j = 1; j <= L; ++j) {
            int mask = (A[i] & (((1 << j) - 1) << (L - j))) >> (L - j);
            chmin(mv, minv[j][mask] + L - j + added);
        }
        dp[A[i - 1]] = mv - added - cost;

        for (int j = 0; j <= L; ++j) {
            int mask = A[i - 1] & ((1 << j) - 1);
            chmin(minv[j][mask], dp[A[i - 1]]);
        }
    }

    cout << minv[0][0] + added << endl;

    return 0;
}