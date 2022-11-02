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

const int N = 666;

struct Edge {
    int from, to, flow, cap;
    Edge() {}
    Edge(int from, int to, int cap) : from(from), to(to), flow(0), cap(cap) {}

    void print() {
        printf("%d %d %d %d\n", from, to, flow, cap);
    }
};

int n, m, ss, ff, ans[N][N];
vector<int> g[N];
vector<Edge> e;
int pr[N], can[N];

void addE(int x, int y, int cap) {
    g[x].push_back(e.size());
    e.push_back(Edge(x, y, cap));
    g[y].push_back(e.size());
    e.push_back(Edge(y, x, 0));
}

bool way() {
    queue<int> q;
    for (int i = 0; i <= ff; i++) {
        pr[i] = -1;
        can[i] = 0;
    }
    q.push(ss); 
    pr[ss] = -2;
    can[ss] = N;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); i++) {
            int id = g[x][i];
            if ((pr[e[id].to] == -1) && (e[id].flow < e[id].cap)) {
                pr[e[id].to] = id;
                can[e[id].to] = min(can[x], e[id].cap - e[id].flow);
                q.push(e[id].to);
            }
        }
    }
    // cerr << can[ff] << endl;
    if (can[ff] == 0) return false;
    int mn = can[ff];
    for (int x = ff; x != ss; x = e[pr[x]].from) {
        int id = pr[x];
        e[id].flow += mn;
        e[id^1].flow -= mn;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);  
    vector<int> a, b;
    a.resize(n); b.resize(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        sum -= b[i];
    }
    if (sum != 0) {
        puts("NO");
        return 0;
    }
    ss = 2 * n;
    ff = 2 * n + 1;
    for (int i = 0; i < n; i++) addE(ss, i, a[i]);
    for (int i = 0; i < n; i++) addE(n + i, ff, b[i]);
    for (int i = 0; i < n; i++) addE(i, n + i, N);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        addE(x, n + y, N);
        addE(y, n + x, N);
    }
    // for (int i = 0; i < e.size(); i++) e[i].print();
    while (way()) {}
    for (int i = 0; i < g[ss].size(); i++) {
        int id = g[ss][i];
        if (e[id].flow != e[id].cap) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int id = g[i][j];
            if ((e[id].to >= n) && (e[id].to < n + n)) {
                ans[i][e[id].to - n] += e[id].flow;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", ans[i][j]);
        puts("");
    }
}