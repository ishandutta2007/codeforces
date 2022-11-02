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

const int MAXD = 80;

const int BIAS = 32;
int mincost[32][64];

struct mat {
    Int X[MAXD][MAXD];
};
mat mul(const mat& A, const mat& B) {
    mat C;
    for (int i = 0; i < MAXD; ++i) {
        for (int j = 0; j < MAXD; ++j) {
            C.X[i][j] = INFLL;
        }
    }
    for (int k = 0; k < MAXD; ++k) {
        for (int i = 0; i < MAXD; ++i) {
            for (int j = 0; j < MAXD; ++j) {
                chmin(C.X[i][j], A.X[i][k] + B.X[k][j]);
            }
        }
    }
    return C;
}

mat pow(mat X, Int e)
{
    mat V;
    for (int i = 0; i < MAXD; ++i) {
        for (int j = 0; j < MAXD; ++j) {
            V.X[i][j] = (i == j ? 0 : INFLL);
        }
    }
    for (; e; e >>= 1, X = mul(X, X)) {
        if (e & 1) {
            V = mul(V, X);
        }
    }
    return V;
}

int main()
{
    int n, m, A[32], B[32];
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 64; ++j) {
            mincost[i][j] = INF;
        }
    }

    for (int i = 0; i < (1<<n); ++i) {
        int need_dep = 0, dep = 0, cost = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                dep++;
                cost += A[j];
            } else {
                dep--;
                cost += B[j];
            }
            chmin(need_dep, dep);
        }
        need_dep = -need_dep;
        chmin(mincost[need_dep][dep + BIAS], cost);
    }

    mat D;
    for (int i = 0; i < MAXD; ++i) {
        for (int j = 0; j < MAXD; ++j) {
            D.X[i][j] = INFLL;
        }
    }
    for (int i = 0; i < MAXD; ++i) {
        for (int nd = 0; nd <= i && nd < 32; ++nd) {
            for (int dd = 0; dd < 64; ++dd) {
                int newd = i + dd - BIAS;
                if (newd < 0 || newd >= MAXD) continue;
                chmin(D.X[i][newd], (Int)mincost[nd][dd]);
            }
        }
    }

    mat R = pow(D, m);
    cout << R.X[0][0] << endl;

    return 0;
}