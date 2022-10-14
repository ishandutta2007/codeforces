#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <time.h>
#include <sstream>
#include <random>
#include <utility>
#define MOD 1000000007
using namespace std;
vector<int> f;
int l, n, q, a[100500], tin[100500], tout[100500], up[100500][22], came[100500], timer;
int rmqmin[500500][22], rmqmax[500500][22], lg2[2000500], level[100500];
vector<int> g[100500];
void dfs(int v, int lvl, int p) {

    up[v][0] = p;
    for (int i = 1; i <= 20; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    came[timer] = v;
    tin[v] = timer++;
    for (auto to : g[v]) {
        if (to != p)
            dfs(to, lvl+1, v);
    }
    tout[v] = timer;
    level[v] = lvl;
}

int get_min(int l, int r) {
    if (l > r)
        return MOD;
    int k = lg2[r-l+1];
    return min(rmqmin[l][k], rmqmin[r-(1<<k)+1][k]);
}

int get_max(int l, int r) {
    if (l > r)
        return -MOD;
    int k = lg2[r-l+1];
    return max(rmqmax[l][k], rmqmax[r-(1<<k)+1][k]);
}
int main() {
    //freopen("input.txt", "w", stdout);
    for (int i = 0; i < 20; i++)
        lg2[1<<i] = i;
    for (int i = 1; i < 1000000; i++)
        lg2[i] = max(lg2[i], lg2[i-1]);
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int x;
        scanf("%d", &x);
        g[i+2].push_back(x);
        g[x].push_back(i+2);
    }
    dfs(1, 0, 1);
    for (int i = 0; i <= n; i++) {
        rmqmin[i][0] = rmqmax[i][0] = tin[i];
    }

    for (int j = 1; j < 18; j++) {
        for (int i = 0; i <= n-(1<<j)+1; i++) {
            rmqmin[i][j] = min(rmqmin[i][j-1], rmqmin[i+(1<<(j-1))][j-1]);
            rmqmax[i][j] = max(rmqmax[i][j-1], rmqmax[i+(1<<(j-1))][j-1]);
        }
    }



    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        int mn = get_min(l, r), mx = get_max(l, r);
        int p = came[mn];
        int mn1 = min(get_min(l, p-1), get_min(p+1, r));
        int mx1 = max(get_max(l, p-1), get_max(p+1, r));
        int v1 = p-1;
        if (p - 1 < l)
            v1 = p+1;
        for (int j = 20; j >= 0; j--) {
            int v = up[v1][j];
            if (tin[v] <= mn1 && tout[v] > mx1) {

            } else {
                v1 = v;
            }
        }
        if (tin[v1] <= mn1 && tout[v1] > mx1) {

        } else {
            v1 = up[v1][0];
        }
        int ans = level[v1], curv = p;

        p = came[mx];
        mn1 = min(get_min(l, p-1), get_min(p+1, r));
        mx1 = max(get_max(l, p-1), get_max(p+1, r));
        v1 = p-1;
        if (p - 1 < l)
            v1 = p+1;
        for (int j = 20; j >= 0; j--) {
            int v = up[v1][j];
            if (tin[v] <= mn1 && tout[v] > mx1) {

            } else {
                v1 = v;
            }
        }
        if (tin[v1] <= mn1 && tout[v1] > mx1) {

        } else {
            v1 = up[v1][0];
        }
        if (level[v1] > ans) {
            ans = max(ans, level[v1]), curv = p;
        }
        printf("%d %d\n", curv, ans);
    }
    return 0;
}