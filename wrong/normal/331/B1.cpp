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

int n;
int A[300050], P[300050];

int B[300050], J[300050];

void add(int x, int v)
{
    while (x <= 300000) {
        B[x] += v;
        x += x & -x;
    }
}

int sum(int x)
{
    int s = 0;
    while (x > 0) {
        s += B[x];
        x -= x & -x;
    }
    return s;
}

void check(int u)
{
    if (u == 1 || u > n) return;
    if (P[u] < P[u - 1] && J[u] == 0) {
        add(u, 1);
        J[u] = 1;
    } else if (P[u] > P[u - 1] && J[u] == 1) {
        add(u, -1);
        J[u] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        P[A[i]] = i;
    }

    for (int i = 2; i <= n; ++i) {
        if (P[i] < P[i - 1]) {
            add(i, 1);
            J[i] = 1;
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int p, x, y;
        cin >> p >> x >> y;

        if (p == 1) {
            cout << sum(y) - sum(x) + 1 << endl;
        } else {
            --x; --y;
            swap(A[x], A[y]);
            swap(P[A[x]], P[A[y]]);
            check(A[x]); check(A[x] + 1);
            check(A[y]); check(A[y] + 1);
        }
    }

    return 0;
}