#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

struct Edge {
    int from, to, len, nom;
    Edge() {}
    Edge(int from, int to, int len, int nom) : from(from), to(to), len(len), nom(nom) {}
    bool operator < (const Edge& u) const {
        return len < u.len;
    }
};

const int N = 1e6;
const long long INF = 1e18;

int n, m, st, pr[N];
vector< Edge > g[N];
vector< Edge > e;
long long dst[N];
bool used[N];
vector<int> v;

void dfs(int x) {
    if (used[x]) return;
    used[x] = true;
    for (int i = 0; i < g[x].size(); i++) {
        if (dst[x] + g[x][i].len == dst[g[x][i].to]) {
            dfs(g[x][i].to);
        }
    }
    v.push_back(x);
}

bool cmp(int x, int y) {
    return e[x] < e[y];
}

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        --x; --y;
        e.push_back(Edge(x, y, z, i));
        g[x].push_back(Edge(x, y, z, i));
        g[y].push_back(Edge(y, x, z, i));
    }   
    scanf("%d", &st);
    --st;
    for (int i = 0; i < n; i++) dst[i] = 1e18;
    dst[st] = 0;
    priority_queue< pair<long long, int> > q;
    q.push(make_pair(0, st));
    while (!q.empty()) {
        int x = q.top().second;
        long long z = -q.top().first;
        q.pop();
        if (z != dst[x]) continue;
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i].to;
            long long cur = z + g[x][i].len;
            if (cur < dst[y]) {
                dst[y] = cur;
                q.push(make_pair(-cur, y));
            }
        }
    }
    dfs(st);
    reverse(v.begin(), v.end());
    long long sum = 0;
    vector<int> ans;
    memset(used, 0, sizeof(used));
    used[st] = 1;
    for (int it = 1; it < n; it++) {
        int x = v[it];
        used[x] = 1;
        int cur = 1e9 + 1;
        int nom = -1;
        for (int j = 0; j < g[x].size(); j++) {
            int y = g[x][j].to;
            if ((dst[y] + g[x][j].len == dst[x]) && (used[y])) {
                if (g[x][j].len < cur) {
                    cur = g[x][j].len;
                    nom = g[x][j].nom;
                }
            }
        }
        sum += cur;
        ans.push_back(nom + 1);
    }
    cout << sum << endl;
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    puts("");
}