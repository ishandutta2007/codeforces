#include <cstdio>
#include <set>
#include <queue>
using namespace std;
set<int> map[200001];
int e[200001][2];
int ans[200001], v[200001];
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=m; i++) {
        scanf("%d%d", &e[i][0], &e[i][1]);
        map[e[i][0]].emplace(e[i][1]);
        map[e[i][1]].emplace(e[i][0]);
    }
    queue<int> Q;
    for(int i=1; i<=n; i++) {
        if(map[i].size() < k) {
            Q.emplace(i);
            v[i] = 1;
        }
    }
    int cnt = n;
    for(int i=m; i>=1; i--) {
        while(!Q.empty()) {
            cnt--;
            int x = Q.front(); Q.pop();
            for(auto e: map[x]) {
                map[e].erase(x);
                if(map[e].size() < k && !v[e]) {
                    v[e] = 1;
                    Q.emplace(e);
                }
            }
        }
        ans[i] = cnt;
        int x = e[i][0], y = e[i][1];
        map[x].erase(y);
        map[y].erase(x);
        if(map[x].size() < k && !v[x]) {
            v[x] = 1;
            Q.emplace(x);
        }
        if(map[y].size() < k && !v[y]) {
            v[y] = 1;
            Q.emplace(y);
        }
    }
    for(int i=1; i<=m; i++) printf("%d\n", ans[i]);
    return 0;
}