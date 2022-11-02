#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

#define N 500500

using namespace std;

int a[N], b[N], ans, n, m, cost[N], prime[N], h[N];
vector<int> p;

int cnt(int x) {
    int res = 0;
    for (int i = 0; i < m; i++)
    while (x % b[i] == 0) {
        res--;
        x /= b[i];
    }
    int y = x;
    for (int i = 0; p[i] * p[i] <= y; i++)
    while (x % p[i] == 0) {
        x /= p[i];
        res++;
    }
    if (x != 1)
    res++;
    return res;
}

int gcd(int x, int y) {
    while ((x != 0) && (y != 0)) 
    if (x > y)
        x %= y;
        else
        y %= x;
    return x + y;
}

int main() {
    //    freopen("input.txt", "r", stdin);
    for (int i = 2; i < N; i++)
    prime[i] = 1;
    for (int i = 2; i < N; i++)
    if (prime[i]) {
        p.push_back(i);
        for (int j = i + i; j < N; j += i)
        prime[j] = 0;
    }
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
    scanf("%d", &b[i]);
    int u = 0, gt = 0;
    for (int i = 0; i < n; i++) {   
    ans += cnt(a[i]);
    gt = gcd(gt, a[i]);
    h[i] = gt;
    }
    int o = 1;
    for (int i = n - 1; i >= 0; i--) {
    int cr = cnt(h[i] / o);
    if (cr < 0) {
        o = h[i];
        ans -= cr * (i + 1);
    }
    }
    //    printf("%d\n", u);
    printf("%d\n", ans - u);
}