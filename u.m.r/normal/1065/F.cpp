#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n, K;
int fa[MAXN], dep[MAXN];
vector<int> E[MAXN];

int surv[MAXN], dead[MAXN], hp[MAXN];

void dfs(int u) {
    dep[u] = dep[fa[u]] + 1;
    if (E[u].size() == 0) {
        surv[u] = 1;
        hp[u] = K;
        dead[u] = 1;
    }
    else {
        surv[u] = 0;
        hp[u] = 0;
        dead[u] = 0;
        for (auto &v : E[u]) {
            dfs(v);
            if (hp[v] >= 1) {
                surv[u] += surv[v];
                hp[u] = max(hp[u], hp[v] - 1);
            }
        }
        dead[u] = surv[u];
        for (auto &v : E[u]) {
            dead[u] = max(dead[u], surv[u] - surv[v] + dead[v]);
        }
    }
    if (hp[u] == 0) surv[u] = 0;
    // cout << u << ' ' << dep[u] << ' ' << surv[u] << ' ' << hp[u] << ' ' << dead[u] << endl;
}

void solve(int casi) {
    scanf("%d%d", &n, &K);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]);
        E[fa[i]].push_back(i);
    }
    fa[1] = 0;
    dep[0] = -1;
    dfs(1);
    printf("%d\n", dead[1]);
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}