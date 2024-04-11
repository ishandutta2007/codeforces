#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn], l[maxn], r[maxn], dis[maxn];
int tl[maxn], tr[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &l[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &r[i]);
    for (int i = 0; i < n; ++i) tl[i] = l[i], tr[i] = r[i];
    queue<int> q;
    memset(dis, -1, sizeof(dis));
    for (int i = 0; i < n; ++i) {
        if (l[i] == 0 && r[i] == 0) {
            dis[i] = 0;
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < x; ++i) {
            if (dis[i] == -1) {
                --r[i];
                if (l[i] == 0 && r[i] == 0) {
                    dis[i] = dis[x] + 1;
                    q.push(i);
                }
            }
        }
        for (int i = x + 1; i < n; ++i) {
            if (dis[i] == -1) {
                --l[i];
                if (l[i] == 0 && r[i] == 0) {
                    dis[i] = dis[x] + 1;
                    q.push(i);
                }
            }
        }
    }
    int k = *max_element(dis, dis + n);
    for (int i = 0; i < n; ++i) a[i] = k - dis[i] + 1;
    // for (int i = 0; i < n; ++i) printf("%d ", dis[i]); puts("");
    for (int i = 0; i < n; ++i) {
        int lt = 0, rg = 0;
        for (int j = 0; j < i; ++j) if (a[j] > a[i]) ++lt;
        for (int j = i + 1; j < n; ++j) if (a[j] > a[i]) ++rg;
        if (lt != tl[i] || rg != tr[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    puts("");
    return 0;
}