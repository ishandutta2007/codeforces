#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <memory.h>
#include <cassert>
#include <set>
#include <map>
#include <vector>
#include <ctime>

#define N 1500

using namespace std;

int k, len, n;
vector<int> v;
vector<int> g[N];
int ans[N][N];

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    scanf("%d", &k);
    while (k) {
        v.push_back(k % 2);
        k /= 2;
    }
    reverse(v.begin(), v.end());
    g[0].push_back(1);
    n = 1;
    len = 1;
    for (int i = 1; i < v.size(); i++) {
        n++;
        g[n].clear();
        for (int x = 0; x < g[0].size(); x++) 
            g[n].push_back(g[0][x]);
        n++;
        g[n].clear();
        for (int x = 0; x < g[0].size(); x++)
            g[n].push_back(g[0][x]);
        g[0].clear();
        g[0].push_back(n);
        g[0].push_back(n - 1);
        len++;
        if (v[i] == 1) {
            int u = 0;
            for (int x = 0; x < len - 1; x++) {
                n++;
                g[u].push_back(n);
                u = n;
            }
            g[n].push_back(1);
        }
    }
    ++n;
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++) 
            ans[i][g[i][j]] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (ans[i][j])
                ans[j][i] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (ans[i][j])
                putchar('Y');
            else
                putchar('N');
        puts("");
    }
}