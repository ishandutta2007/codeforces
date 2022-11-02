#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LEN;
const LEN INF = 1ll << 60;

struct Point {
    LEN x, y;

    Point(LEN x = 0, LEN y = 0) : x(x), y(y) {}
};

const int N = 1000005;

int n;
Point p[N];

int ord[N];

bool byX(const int &i, const int &j) {
    return p[i].x < p[j].x;
}

bool byY(const int &i, const int &j) {
    return p[i].y < p[j].y;
}

inline LEN sqr(LEN x) {
    return x * x;
}

LEN dis(const int &i, const int &j) {
    return sqr(p[i].x - p[j].x) + sqr(p[i].y - p[j].y);
}

int tmp[N];

LEN brute(int ord[], int n) {
    sort(ord, ord + n, byY);
    LEN ret = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ret = min(ret, dis(ord[i], ord[j]));
        }
    }
    return ret;
}

LEN solve(int ord[], int n) {
    if (n == 1) {
        return INF;
    }
    if (n < 10) {
        return brute(ord, n);
    }
    int left = (n + 1) / 2; 
    LEN midx = p[ord[left]].x, delta = min(solve(ord, left), solve(ord + left, n - left));
    {
        int i = 0, j = left, k = 0;
        while (i < left || j < n) {
            if (i != left && (j == n || p[ord[i]].y < p[ord[j]].y)) {
                tmp[k++] = ord[i++];
            } else {
                tmp[k++] = ord[j++];
            }
        }
        memcpy(ord, tmp, sizeof(int) * n);
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        int u = ord[i];
        if (sqr(p[u].x - midx) < delta) {
            tmp[k++] = u;
        }
    }
    LEN ret = delta;
    for (int i = 0; i < k; ++i) {
        int u = tmp[i];
        for (int j = i + 1; j < k; ++j) {
            int v = tmp[j];
            if (sqr(p[u].y - p[v].y) >= ret) {
                break;
            }
            ret = min(ret, dis(u, v));
        }
    }
    return ret;
}

LEN solve() {
    for (int i = 0; i < n; ++i) {
        ord[i] = i;
    } 
    sort(ord, ord + n, byX);
    return solve(ord, n);
}

int a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        if (i) {
            a[i] += a[i - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        p[i].x = i, p[i].y = a[i];
    }
    cout << solve() << endl;
    return 0;
}