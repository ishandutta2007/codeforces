#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, a, b;

int num[N];
map<int, int> ord;
bool vis[N];
vector<int> edge[N];
int ans[N];

bool solve(int u) {
    vector<int> q;
    q.push_back(u);
    vis[u] = true;
    for (int i = 0; i < (int)q.size(); ++i) {
        int u = q[i];
        for (int j = 0; j < (int)edge[u].size(); ++j) {
            int v = edge[u][j];
            if (!vis[v]) {
                q.push_back(v);
                vis[v] = true;
            }
        }
    }
    for (int t = 0; t < (int)edge[u].size(); ++t) {
        for (int i = 0; i < (int)q.size(); ++i) {
            ans[q[i]] = -1;
        }
        int v = edge[u][t];
        ans[u] = ans[v] = num[u] + num[v] == b;
        bool flag = true;
        for (int i = 0; i < (int)q.size() && flag; ++i) {
            int u = q[i];
            if (ans[u] == -1) {
                for (int j = 0; j < (int)edge[u].size(); ++j) {
                    int v = edge[u][j];
                    if (ans[v] == -1) {
                        ans[u] = ans[v] = num[u] + num[v] == b;
                        break;
                    }
                }
            }
            if (ans[u] == -1) {
                flag = false;
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
        ord[num[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (ord.count(a - num[i])) {
            edge[i].push_back(ord[a - num[i]]);
        }
        if (ord.count(b - num[i])) {
            edge[i].push_back(ord[b - num[i]]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            if (!solve(i)) {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}