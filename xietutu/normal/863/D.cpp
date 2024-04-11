#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
const int maxn = 200010;
typedef pair<int, int> pii;
pii op[maxn];
int n, q, m, a[maxn], type[maxn];
int main() {
    scanf("%d%d%d", &n, &q, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d%d", type + i, &op[i].F, &op[i].S);
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        scanf("%d", &x);
        for (int i = q; i >= 1; --i) {
            int l = op[i].F, r = op[i].S;
            if (x >= l && x <= r) {
                if (type[i] == 1) {
                    if (x == l) x = r;
                    else x = x - 1;
                }
                if (type[i] == 2) {
                    x = r - (x - l);
                }
            }
        }
        printf("%d%c", a[x], i == m ? '\n' : ' ');
    }
}