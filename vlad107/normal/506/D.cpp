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

const int N = 1e5;
const int C = 444;

int n, m, deg[N], used[N], qqq, fst[N];
vector<pair<int, pair<int, int>>> e;
vector<int> g[N], q, gt[N];
map<pair<int, int>, int> mm, ans;

void dfs(int x) {
    used[x] = qqq;
    q.push_back(x);
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (used[y] != qqq) dfs(y);
    }
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int z, x, y;
        scanf("%d%d%d", &x, &y, &z);
        --x; --y;
        e.push_back(make_pair(z, make_pair(x, y)));
        gt[x].push_back(z);
        gt[y].push_back(z);
        deg[x]++; deg[y]++;
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < e.size(); ) {
        int j = i;
        set<int> ver;
        fst[e[i].first] = i;
        while ((j < e.size()) && (e[i].first == e[j].first)) {
            int x = e[j].second.first;
            int y = e[j].second.second;
            g[x].push_back(y);
            g[y].push_back(x);
            ver.insert(x);
            ver.insert(y);
            ++j;
        }
        qqq++;
        int cnt = 0;
        for (auto u : ver) {
            q.clear();
            if (used[u] != qqq) dfs(u);
            cnt++;
            vector<int> qq;
            for (int x : q) {
                mm[make_pair(x, i)] = cnt;
                if (deg[x] > C) {
                    qq.push_back(x);
                }
            }
            for (int x : qq) for (int y : qq) {
                ans[make_pair(x, y)]++;
            }
        }
        for (auto u : ver) g[u].clear();
        i = j;
    }
//  for (auto u : mm) cerr << u.first.first << " " << u.first.second << " " << u.second << endl;
    int k;
    scanf("%d", &k);
    while (k--) {   
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        if ((deg[x] > C) && (deg[y] > C)) printf("%d\n", ans[make_pair(x, y)]); else {
            if (deg[x] > deg[y]) swap(x, y);
            qqq++;
            int ans = 0;
            for (int z : gt[x]) {   
                if (used[z] == qqq) continue;
                used[z] = qqq;
                if ((mm.count(make_pair(y, fst[z])) > 0) && (mm[make_pair(x, fst[z])] == mm[make_pair(y, fst[z])])) ans++;
            }
            printf("%d\n", ans);
        }
    }
}