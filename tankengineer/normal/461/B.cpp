#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int n;

int col[N];
vector<int> edge[N];

vector<int> child[N];

int f[N][2];

const int MOD = 1000000007;

int inverse(int a) {
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

void dfs(int u, int fa) {
    for (int j = 0; j < (int)edge[u].size(); ++j) {
        int v = edge[u][j];
        if (v == fa) {
            continue;
        }
        child[u].push_back(v);
        dfs(v, u);
    }
    if (child[u].size() == 0) {
        if (col[u] == 0) {
            f[u][0] = 1;
            f[u][1] = 0;
        } else {
            f[u][0] = 0;
            f[u][1] = 1;
        }
    } else {
        if (col[u] == 0) {
            f[u][0] = 1;
            for (int i = 0; i < (int)child[u].size(); ++i) {
                int v = child[u][i];
                f[u][0] = (long long)f[u][0] * ((f[v][0] + f[v][1]) % MOD) % MOD;
            }
            f[u][1] = 0;
            for (int i = 0; i < (int)child[u].size(); ++i) {
                int v = child[u][i];
                f[u][1] = (f[u][1] + (long long)f[u][0] * inverse((f[v][0] + f[v][1]) % MOD) % MOD * f[v][1] % MOD) % MOD;
            }
        } else {
            f[u][0] = 0;
            f[u][1] = 1;
            for (int i = 0; i < (int)child[u].size(); ++i) {
                int v = child[u][i];
                f[u][1] = (long long)f[u][1] * ((f[v][0] + f[v][1]) % MOD) % MOD;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u = i + 1, v;
        scanf("%d", &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", col + i);
    }
    dfs(0, -1);
    printf("%d\n", f[0][1]);
    return 0;
}