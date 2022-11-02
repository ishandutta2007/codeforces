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
typedef unsigned long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

Int prs[] = {999948011, 999950377, 999952489, 999954677, 999956593, 999958577, 999960551, 999962563, 999964417, 999966731, 999968707, 999970691, 999972661, 999974669, 999977081, 999979129, 999981179, 999983339, 999985249, 999987299, 999989321, 999991453, 999993811, 999995701, 999997967, 1000000007, 1000002089, 1000004251, 1000006099, 1000008277, 1000010303, 1000012339, 1000014583, 1000016863, 1000019003, 1000020953, 1000023247, 1000025269, 1000027429, 1000029227, 1000031339, 1000033427, 1000035389, 1000037329, 1000039577, 1000041719, 1000043767, 1000045909, 1000048013, 1000049989, 1000052069};
Int prspow[51], target[51];

const int MAXV = 400050, MAXE = 2 * MAXV;
int adj[MAXE], next[MAXE], ptr[MAXV], chr[MAXE], es;
char tmp[300050];

void addedge(int u, int v, int c)
{
    next[es] = ptr[u]; ptr[u] = es; adj[es] = v; chr[es] = c; ++es;
    next[es] = ptr[v]; ptr[v] = es; adj[es] = u; chr[es] = c; ++es;
}

int m, stk[300050], sptr, res;
Int hash[51];

void dfs(int u, int p = -1)
{
    bool ok = true;
    for (int i = 0; i < 51; ++i) {
        ok &= hash[i] == target[i];
    }
    if (ok) {
        ++res;
    }

    for (int z = ptr[u]; ~z; z = next[z]) {
        int v = adj[z];
        if (v == p) {
            continue;
        }

        Int restore[51];
        stk[sptr++] = chr[z];
        for (int i = 0; i < 51; ++i) {
            restore[i] = hash[i];
            hash[i] = hash[i] * prs[i] + chr[z];
            if (sptr > m) {
                hash[i] -= stk[sptr - m - 1] * prspow[i];
            }
        }
        dfs(v, u);
        for (int i = 0; i < 51; ++i) {
            hash[i] = restore[i];
        }
        --sptr;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(ptr, ~0, sizeof(ptr));
    for (int i = 1, av = n; i < n; ++i) {
        int par;
        scanf("%d%s", &par, tmp);
        --par;

        int length = strlen(tmp);
        for (int j = 0; j < length; ++j) {
            int u = j == 0 ? par : av++;
            int v = j == length - 1 ? i : av;
            addedge(u, v, tmp[j]);
        }
    }

    scanf("%s", tmp);
    m = strlen(tmp);
    for (int i = 0; i < 51; ++i) {
        prspow[i] = 1;
        for (int j = 0; j < m; ++j) {
            prspow[i] *= prs[i];
            target[i] = target[i] * prs[i] + tmp[j];
        }
    }

    dfs(0);
    printf("%d\n", res);

    return 0;
}