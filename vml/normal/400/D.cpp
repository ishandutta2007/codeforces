#pragma comment (linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int MAX_N = 100100;
const int MAX_K = 510;
const int inf = 1000000000;

vector <int> g_free[MAX_N];
vector <pair <int, int> > g[MAX_N];
int new_g[MAX_K][MAX_K];
int num[MAX_N];
int cnt[MAX_K];
bool used[MAX_N];
int type[MAX_N];

void dfs_component(int v, int number) {
    used[v] = true;
    num[v] = number;
    for (int i = 0; i < (int)g_free[v].size(); i++) {
        int u = g_free[v][i];
        if (!used[u]) {
            dfs_component(u, number);
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int last = 0;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &cnt[i]);
        for (int j = last + 1; j <= last + cnt[i]; j++) {
            type[j] = i;
        }
        last += cnt[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v, x;
        scanf("%d %d %d", &u, &v, &x);
        if (x == 0) {
            g_free[u].push_back(v);
            g_free[v].push_back(u);
        }
        g[u].push_back(make_pair(v, x));
        g[v].push_back(make_pair(u, x));
    }
    int number = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs_component(i, number);
            number++;
        }
    }
    last = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = last + 2; j <= last + cnt[i]; j++) {
            if (num[j] != num[j - 1]) {
                printf("No");
                return 0;
            }
        }
        last += cnt[i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            new_g[i][j] = inf;
        }
        new_g[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            int u = g[i][j].first;
            int cost = g[i][j].second;
            if (type[i] != type[u]) {
                new_g[type[i]][type[u]] = min(new_g[type[i]][type[u]], cost);
            }
        }
    }
    printf("Yes\n");
    for (int c = 1; c <= k; c++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                if (new_g[i][c] != inf && new_g[c][j] != inf) {
                    new_g[i][j] = min(new_g[i][j], new_g[i][c] + new_g[c][j]);
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (new_g[i][j] == inf) {
                new_g[i][j] = -1;
            }
            printf("%d ", new_g[i][j]);
        }
        printf("\n");
    }
    return 0;
}