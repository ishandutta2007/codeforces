#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], c[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) ++c[a[i]];
    
    int mode = max_element(c, c + maxn) - c;
    // printf("mode = %d\n", mode);

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mode)
            q.push(i);
    }

    printf("%d\n", n - c[mode]);

    while (q.size()) {
        int x = q.front(); q.pop();
        if (x > 0 && a[x - 1] != a[x]) {
            printf("%d %d %d\n", (a[x] < a[x - 1]) + 1, x, x + 1);
            a[x - 1] = a[x];
            q.push(x - 1);
        }
        if (x + 1 < n && a[x + 1] != a[x]) {
            printf("%d %d %d\n", (a[x + 1] > a[x]) + 1, x + 2, x + 1);
            a[x + 1] = a[x];
            q.push(x + 1);
        }
    }
}