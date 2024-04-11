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

const int MAXV = 200050;
const int MAXE = 400050;
int adj[MAXE], next[MAXE], ptr[MAXV];
pair<int, int> row[100050];

int order[MAXV], oc, color[MAXV];

bool visit(int v)
{
    color[v] = 1;

    for (int z = ptr[v]; ~z; z = next[z]) {
        int w = adj[z];
        if (color[w] == 2) {
            continue;
        }
        if (color[w] == 1) {
            return false;
        }
        if (!visit(w)) {
            return false;
        }
    }

    order[oc++] = v;
    color[v] = 2;

    return true;
}

bool topological_sort(int n)
{
    memset(color, 0, sizeof(color));
    oc = 0;

    for (int u = 0; u < n; ++u) {
        if (!color[u] && !visit(u)) {
            return false;
        }
    }
    reverse(order, order + oc);

    return true;
}

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    memset(ptr, ~0, sizeof(ptr));

    int vs = m, es = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &row[j].first);
            row[j].second = j;
        }
        sort(row, row + m);

        int s = 0;
        while (s < m && row[s].first == -1) {
            ++s;
        }

        int t = s;
        while (t < m && row[t].first == row[s].first) {
            ++t;
        }

        while (t < m) {
            int nt = t;
            while (nt < m && row[nt].first == row[t].first) {
                ++nt;
            }

            for (int k = s; k < t; ++k) {
                next[es] = ptr[row[k].second]; ptr[row[k].second] = es; adj[es] = vs; ++es;
            }
            for (int k = t; k < nt; ++k) {
                next[es] = ptr[vs]; ptr[vs] = es; adj[es] = row[k].second; ++es;
            }
            ++vs;
            s = t; t = nt;
        }
    }

    if (!topological_sort(vs)) {
        puts("-1");
        return 0;
    }

    int pd = 0;
    for (int i = 0; i < oc; ++i) {
        if (order[i] < m) {
            printf("%d%c", order[i]+1, ++pd == m ? '\n' : ' ');
        }
    }

    return 0;
}