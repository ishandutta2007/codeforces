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

int g[128][128];

int U[128];
void init(int n)
{
    for (int i = 0; i < n; ++i) {
        U[i] = i;
    }
}
int find(int x)
{
    if (U[x] != x) {
        U[x] = find(U[x]);
    }
    return U[x];
}
void uni(int x, int y)
{
    U[find(x)] = find(y);
}

int main()
{
    int n, m, r = 0;

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        if (k == 0) {
            ++r;
            --n;
            --i;
            continue;
        }

        for (int j = 0; j < k; ++j) {
            int a;
            cin >> a;

            g[i][a - 1] = 1;
        }
    }

    init(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                if (g[i][k] && g[j][k]) {
                    uni(i, j);
                }
            }
        }
    }

    set<int> S;
    for (int i = 0; i < n; ++i) {
        S.insert(find(i));
    }

    if (S.size() == 0) {
        cout << r << endl;
    } else {
        cout << r + S.size() - 1 << endl;
    }

    return 0;
}