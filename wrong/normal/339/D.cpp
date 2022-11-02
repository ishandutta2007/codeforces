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

int N, M;
int V[18][1<<17];

int main()
{
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < (1<<N); ++i) {
        cin >> V[0][i];
    }

    for (int i = 1, K = (1<<(N-1)); K >= 1; ++i, K>>=1) {
        for (int j = 0; j < K; ++j) {
            int X = V[i - 1][2 * j], Y = V[i - 1][2 * j + 1];
            V[i][j] = (i % 2 == 1 ? (X | Y) : (X ^ Y));
        }
    }

    for (int i = 0; i < M; ++i) {
        int p, b;
        cin >> p >> b;
        --p;

        V[0][p] = b;
        for (int i = 1; i <= N; ++i) {
            p >>= 1;
            int X = V[i - 1][2 * p], Y = V[i - 1][2 * p + 1];
            V[i][p] = (i % 2 == 1 ? (X | Y) : (X ^ Y));
        }

        cout << V[N][0] << endl;
    }

    return 0;
}