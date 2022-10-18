#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int n, p[MAXN], posP[MAXN], q[MAXN];

struct Node {
    int minX;
    int val;
};

struct IT {
private:
    int n;
    vector<Node> t;

    void propagate(int id, int l, int r) {
        int &x = t[id].val;
        if (x != 0) {
            for(int child = 2*id; child <= 2*id+1; ++child) {
                t[child].val += x;
                t[child].minX += x;
            }        
            x = 0;
        }
    }

    void update(int id, int l, int r, int i, int j, int x) {
        // printf("%d %d %d %d %d\n", id, l, r, t[id].minX, t[id].val);
        if (i > r || j < l)
            return;
        if (i <= l && r <= j) {
            t[id].minX += x;
            t[id].val += x;
            return;
        }

        propagate(id, l, r);

        int m = (l + r) / 2;
        update(2*id, l, m, i, j, x); update(2*id+1, m+1, r, i, j, x);
        t[id].minX = min(t[2*id].minX, t[2*id+1].minX);
    }

public:
    IT(int n): n(n) {
        t.assign(4*n+1, {0, 0});        
    }

    void update(int i, int j, int x) {
        // printf("update: %d %d %d\n", i, j, x);
        update(1, 1, n, i, j, x);
        // printf("query: %d\n", t[1].minX);
    }

    int query() {
        return t[1].minX;
    }
};

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
        posP[p[i]] = i;
    }
    for(int i = 1; i <= n; ++i)
        scanf("%d", &q[i]);

    IT t(n);

    int x = n;
    printf("%d", x);
    for(int i = 2; i <= n; ++i) {
        t.update(1, q[i-1], 1);

        // printf("i: %d\n", i);
        while (x > 0 && t.query() >= 0) {
            t.update(1, posP[x], -1);
            // printf("x, posP[x], query: %d %d\n", x, posP[x], t.query());
            --x;
        }
        if (t.query() < 0) {
            ++x;
            t.update(1, posP[x], 1);
        }

        printf(" %d", x);
    }
    puts("");

    return 0;
}