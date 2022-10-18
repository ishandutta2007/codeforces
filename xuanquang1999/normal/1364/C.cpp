#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int nTest, n, a[MAXN], b[MAXN];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]);

    stack<int> pos;
    int cur = 0;
    for(int i = 1; i <= n; ++i) {
        if (a[i] == a[i-1])
            pos.push(i);
        else {
            b[i] = cur++;
            while (cur < a[i]) {
                // printf("%d %d\n", pos.top(), cur);
                b[pos.top()] = cur++;
                pos.pop();
            }
        }
    }

    while (!pos.empty()) {
        b[pos.top()] = 1e6;
        pos.pop();
    }

    for(int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    puts("");

    return 0;
}