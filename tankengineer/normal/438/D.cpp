#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

const int N = 100005;
int a[N];

pair<int, int> maxs[N << 1];
long long sum[N << 1];

inline int getID(int l, int r) {
    return l + r | l != r;
}

void update(int l, int r) {
    int u = getID(l, r), m = l + r >> 1, lc = getID(l, m), rc = getID(m + 1, r);
    sum[u] = sum[lc] + sum[rc];
    maxs[u] = max(maxs[lc], maxs[rc]);
}

void insert(int l, int r, int pos, int x) {
    if (l == r) {
        int u = getID(l, r);
        sum[u] = x;
        maxs[u] = make_pair(x, l);
    } else {
        int m = l + r >> 1;
        if (pos <= m) {
            insert(l, m, pos, x);
        } else {
            insert(m + 1, r, pos, x);
        }
        update(l, r);
    }
}

pair<int, int> getmax(int l, int r, int a, int b) {
    if (a <= l && r <= b) {
        return maxs[getID(l, r)];
    }
    int m = l + r >> 1;
    if (m < a) {
        return getmax(m + 1, r, a, b);
    } else if (b <= m) {
        return getmax(l, m, a, b);
    } else {
        return max(getmax(l, m, a, b), getmax(m + 1, r, a, b));
    }
}

long long getans(int l, int r, int a, int b) {
    if (b < l || r < a) {
        return 0;
    }
    if (a <= l && r <= b) {
        return sum[getID(l, r)];
    }
    int m = l + r >> 1;
    return getans(l, m, a, b) + getans(m + 1, r, a, b);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        insert(0, n - 1, i, a[i]);
    }
    for (int i = 0; i < m; ++i) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, r;
            scanf("%d%d", &l, &r);
            --l, --r;
            printf("%I64d\n", getans(0, n - 1, l, r));
        } else if (op == 2) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            --l, --r;
            int pos = 0;
            while (a[pos = getmax(0, n - 1, l, r).second] >= x) {
                a[pos] %= x;
                insert(0, n - 1, pos, a[pos]);
            }
        } else {
            int k, x;
            scanf("%d%d", &k, &x);
            --k;
            a[k] = x;
            insert(0, n - 1, k, x);
        }
    }
    return 0;
}