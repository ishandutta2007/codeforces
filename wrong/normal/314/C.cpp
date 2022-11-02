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

const int MO = 1000000007;

struct BIT {
    Int B[1<<20];
    BIT() {
        memset(B, 0, sizeof(B));
    }
    void upd(int x, Int v) {
        while (x <= 1000000) {
            B[x] += v;
            if (B[x] >= MO) B[x] -= MO;
            x += x & -x;
        }
    }
    Int sum(Int x) {
        Int res = 0;
        while (x > 0) {
            res += B[x];
            if (res >= MO) res -= MO;
            x -= x & -x;
        }
        return res;
    }
} S;

int A[100050], prev[100050];
int pos[1<<20];
Int sum[100050];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        pos[A[i]] = -1;
    }

    for (int i = 0; i < N; ++i) {
        prev[i] = pos[A[i]];
        pos[A[i]] = i;
    }

    Int res = 0;
    for (int i = 0; i < N; ++i) {
        sum[i] = S.sum(A[i]);
        Int ps = sum[i];
        ps -= (prev[i] >= 0 ? sum[prev[i]] : -1);
        ps = (ps + MO) % MO;
        ps = ps * A[i] % MO;
        res += ps;
        res %= MO;
        S.upd(A[i], ps);
    }

    cout << res << endl;

    return 0;
}