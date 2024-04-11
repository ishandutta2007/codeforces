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

int a[100050], b[100050], qx[100050], qy[100050], qk[100050];

int val[800050];
void upd(int l, int r, int v, int x, int L, int R)
{
    if (l == L && r == R) {
        val[x] = v;
        return;
    }
    int mid = (L + R) / 2;
    if (l < mid) upd(l, min(mid, r), v, 2 * x + 0, L, mid);
    if (r > mid) upd(max(l, mid), r, v, 2 * x + 1, mid, R);
}
int query(int k, int x, int L, int R)
{
    if (R - L == 1) {
        return val[x];
    }
    int mid = (L + R) / 2, res = val[x];
    if (k < mid) chmax(res, query(k, 2 * x + 0, L, mid));
    if (k >= mid) chmax(res, query(k, 2 * x + 1, mid, R));
    return res;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < 800050; ++i) {
        val[i] = -1;
    }

    int us = 0;
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            scanf("%d%d%d", &qx[us], &qy[us], &qk[us]);
            --qx[us]; --qy[us];
            upd(qy[us], qy[us] + qk[us], us, 1, 0, n);
            us++;
        } else {
            int x;
            scanf("%d", &x);
            --x;

            int v = query(x, 1, 0, n);
            if (v < 0) {
                printf("%d\n", b[x]);
            } else {
                printf("%d\n", a[qx[v] + x - qy[v]]);
            }
        }
    }

    return 0;
}