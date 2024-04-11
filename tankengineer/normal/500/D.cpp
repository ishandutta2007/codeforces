#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, u[N], v[N];

vector<int> edge[N];

int size[N];

double w[N];

void dfs(int u, int fa) {
    size[u] = 1;
    for (int j = 0; j < (int)edge[u].size(); ++j) {
        int v = edge[u][j];
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        size[u] += size[v];
    }
}

double coef[N];

double lfac[N];

double cb(int n, int m) {
    return lfac[n] - lfac[n - m];
}

double cal(int m) {
    double ret = 0;
    if (m > 1) {
        ret += exp(cb(m, 2) + cb(n - m, 1) - cb(n, 3));
    }
    if (n - m > 1) {
        ret += exp(cb(n - m, 2) + cb(m, 1) - cb(n, 3));
    }
    return ret * 6;
}

int main() {
    lfac[0] = 0;
    for (int i = 1; i < N; ++i) {
        lfac[i] = lfac[i - 1] + log(i);
    }
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%lf", u + i, v + i, w + i);
        --u[i], --v[i];
        edge[u[i]].push_back(v[i]);
        edge[v[i]].push_back(u[i]);
    }
    dfs(0, -1);
    double sum = 0;
    for (int i = 1; i < n; ++i) {
        coef[i] = cal(min(size[u[i]], size[v[i]]));
        sum += coef[i] * w[i];
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int id, ww;
        scanf("%d%d", &id, &ww);
        sum -= coef[id] * w[id];
        w[id] = ww;
        sum += coef[id] * w[id];
        printf("%.12f\n", sum);
    }
    return 0;
}