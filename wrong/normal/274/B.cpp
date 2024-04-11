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

const int MAXV = 100050;
const int MAXE = 200050;
int adj[MAXE], next[MAXE], ptr[MAXV];
Int v[MAXV];

pair<Int, Int> dfs(int u, int p = -1)
{
    pair<Int, Int> res(0, 0);

    for (int z = ptr[u]; ~z; z = next[z]) {
        int v = adj[z];

        if (v != p) {
            pair<Int, Int> tmp = dfs(v, u);
            chmax(res.first, tmp.first);
            chmax(res.second, tmp.second);
        }
    }

    Int t = v[u] + res.first - res.second;
    if (t > 0) {
        res.second += t;
    } else {
        res.first += -t;
    }

    return res;
}

int main()
{
    int n;

    scanf("%d", &n);

    memset(ptr, ~0, sizeof(ptr));
    for (int i = 0, e = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;

        next[e] = ptr[a]; ptr[a] = e; adj[e] = b; ++e;
        next[e] = ptr[b]; ptr[b] = e; adj[e] = a; ++e;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &v[i]);
    }

    pair<Int, Int> res = dfs(0);
    printf("%I64d\n", res.first + res.second);

    return 0;
}