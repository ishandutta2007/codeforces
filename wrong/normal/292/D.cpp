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

struct UF {
    int v[512];
    UF(int n = 0) {
        for (int i = 0; i < n; ++i) {
            v[i] = -1;
        }
    }
    int root(int x) {
        return v[x] < 0 ? x : v[x] = root(v[x]);
    }
    bool uni(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (v[y] < v[x]) swap(x, y);
            v[x] += v[y]; v[y] = x;
        }
        return x != y;
    }
} fw[10050], bw[10050];

int x[10050], y[10050];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> y[i];
        --x[i]; --y[i];
    }

    fw[0] = UF(n);
    for (int i = 0; i < m; ++i) {
        fw[i + 1] = fw[i];
        fw[i + 1].uni(x[i], y[i]);
    }
    bw[m] = UF(n);
    for (int i = m - 1; i >= 0; --i) {
        bw[i] = bw[i + 1];
        bw[i].uni(x[i], y[i]);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;

        UF u = fw[l - 1];
        for (int j = 0; j < n; ++j) {
            u.uni(j, bw[r].root(j));
        }

        int sz = 0;
        for (int j = 0; j < n; ++j) {
            sz += !!(j == u.root(j));
        }
        cout << sz << endl;
    }

    return 0;
}