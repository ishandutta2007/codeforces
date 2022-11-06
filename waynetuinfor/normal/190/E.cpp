#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
vector<int> graf[maxn], pos[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    while (m--) {
        int a, b; scanf("%d %d", &a, &b);
        graf[a].push_back(b); graf[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) sort(graf[i].begin(), graf[i].end());
    set<int> cand;
    for (int i = 1; i <= n; ++i) cand.insert(i);
    int c = 0;
    while (cand.size()) {
        int s = *cand.begin(); cand.erase(s);
        ++c; pos[c].push_back(s);
        queue<int> q; q.push(s);
        while (q.size()) { 
            int x = q.front(); q.pop();
            auto it = cand.begin();
            while (it != cand.end()) {
                // printf("%d\n", *it);
                if (graf[x].size() > 0 && graf[x].back() >= *it && 
                    *(lower_bound(graf[x].begin(), graf[x].end(), *it)) == *it) { ++it; continue; }
                // printf("s = %d, u = %d\n", s, *it);
                pos[c].push_back(*it);
                q.push(*it);
                it = cand.erase(it);
            }
        }
    }
    printf("%d\n", c);
    for (int i = 1; i <= c; ++i) {
        printf("%d ", pos[i].size());
        for (int j = 0; j < pos[i].size(); ++j) printf("%d ", pos[i][j]);
        puts("");
    }
    return 0;
}