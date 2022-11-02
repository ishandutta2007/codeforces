#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
int f[N], g[N];

const int M = 2005;
int n, m, a[N], b[M], goleft[N], goright[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        goleft[i + 1] = i + 1;
        if (i && a[i - 1] == a[i] - 1) {
            goleft[i + 1] = goleft[i];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        goright[i + 1] = i + 1;
        if (i + 1 < n && a[i] + 1 == a[i + 1]) {
            goright[i + 1] = goright[i + 2];
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", b + i);
    }
    sort(b, b + m);
    for (int i = 1; i <= n; ++i) {
        int pos = upper_bound(b, b + m, a[i - 1]) - b, k = 0;
        while (true) {
            int j = k == 0 ? i : i - max(0, a[i - 1] - b[pos]);
            if (j < 0) {
                break;
            }
            j = goleft[j] - 1;
            if (j < 0) {
                break;
            }
            f[i] = max(f[i], k + g[j]);
            --pos, ++k;
            if (pos < 0) {
                break;
            }
        }
        //g[i] = max(g[i], g[goleft[i - 1]]);
        //g[i] = max(g[i], f[i]);
        pos = upper_bound(b, b + m, a[i - 1]) - b - 1, k = 0;
        while (pos < m) {
            int j = k == 0 ? i : i + b[pos] - a[i - 1];
            if (j > n) {
                break;
            }
            j = goright[j];
            g[j] = max(g[j], f[i] + k);
            ++pos, ++k;
        }
//cout << i << ' ' << f[i] << ' ' << g[i] << endl;
    }
    printf("%d\n", g[n]);
    return 0;
}