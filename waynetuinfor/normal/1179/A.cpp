#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], res[maxn];
int fa[maxn], fb[maxn];

int main() {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int x = *max_element(a, a + n);
    deque<int> dq(a, a + n);

    int op = 0;

    while (true) {
        int a = dq[0];
        int b = dq[1];

        if (a == x) {
            for (int i = 1; i < n; ++i) 
                res[i - 1] = dq[i];
            break;
        }

        dq.pop_front();
        dq.pop_front();

        if (a > b) {
            dq.push_front(a);
            dq.push_back(b);
        } else {
            dq.push_front(b);
            dq.push_back(a);
        }

        fa[op] = a;
        fb[op] = b;
        ++op;
    }

    while (q--) {
        long long t; scanf("%lld", &t); --t;
        if (t < op) 
            printf("%d %d\n", fa[t], fb[t]);
        else
            printf("%d %d\n", x, res[(t - op) % (n - 1)]);
    }
}