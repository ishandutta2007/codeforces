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

int N, X[100050], A, B;
int S[1<<20];

struct BIT {
    int V[1<<20];
    BIT() {
        for (int i = 0; i < (1<<20); ++i) {
            V[i] = INF;
        }
    }
    void update(int idx, int val) {
        while (idx <= A - B) {
            chmin(V[idx], val);
            idx += (idx & -idx);
        }
    }
    int getmin(int idx) {
        int s = INF;
        chmin(idx, A - B);
        while (idx > 0) {
            chmin(s, V[idx]);
            idx -= (idx & -idx);
        }
        return s;
    }
} T;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &X[i]);
    }
    scanf("%d%d", &A, &B);
    sort(X, X + N);
    N = unique(X, X + N) - X;

    if (A == B) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = B; i <= A; ++i) {
        S[i - B] = 2;
    }
    for (int i = 0; i < N; ++i) {
        int p = B / X[i] * X[i];
        while (p <= A) {
            if (B <= p) chmax(S[p - B], X[i]);
            p += X[i];
        }
    }

    T.update(A - B, 0);
    for (int i = A - 1; i >= B; --i) {
        int v = T.getmin(i - B + S[i - B] - 1);
        if (i == B) {
            cout << v + 1 << endl;
        } else {
            T.update(i - B, v + 1);
        }
    }

    return 0;
}