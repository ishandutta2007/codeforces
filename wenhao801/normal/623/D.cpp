#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 110;
int n; double p[MAXN], cur[MAXN];

double nex (int i) { return (1 - (1 - p[i]) * cur[i]) / (1 - cur[i]); }
struct node { int id; bool operator < (const node &t) const { return nex(id) < nex(t.id); } };
priority_queue <node> pq;

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) p[i] = read() / 100.0;
    double ans = 0, sum = 1;
    for (i = 1; i <= n; i++) cur[i] = 1 - p[i], pq.push({i}), sum *= p[i];
    ans += n * sum; double last;
    for (int it = n + 1; it <= n + 200000; it++) {
        int i = pq.top().id; pq.pop();
        last = sum;
        sum /= 1 - cur[i]; cur[i] *= 1 - p[i]; sum *= 1 - cur[i];
        ans += it * (sum - last);
        pq.push({i});
    }
    printf("%.7lf\n", ans);
    return 0;
}