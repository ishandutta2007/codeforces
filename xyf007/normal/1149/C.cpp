#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, q, sum[1000001], lmax[1000001], rmin[1000001], lans[1000001], rans[1000001], lrans[1000001], maxx[1000001];
char s[200001];
void pushup(int x)
{
    sum[x] = sum[x + x] + sum[x + x + 1];
    lmax[x] = max(lmax[x + x], sum[x + x] + lmax[x + x + 1]);
    rmin[x] = min(rmin[x + x + 1], sum[x + x + 1] + rmin[x + x]);
    lans[x] = max(lans[x + x], max(lans[x + x + 1] - sum[x + x], lrans[x + x] + lmax[x + x + 1]));
    rans[x] = max(rans[x + x + 1], max(rans[x + x] + sum[x + x + 1], lrans[x + x + 1] - rmin[x + x]));
    lrans[x] = max(lrans[x + x] + sum[x + x + 1], lrans[x + x + 1] - sum[x + x]);
    maxx[x] = max(max(maxx[x + x], maxx[x + x + 1]), max(rans[x + x] + lmax[x + x + 1], lans[x + x + 1] - rmin[x + x]));
}
void build(int l, int r, int x)
{
    if (l == r)
    {
        int t = (s[l] == '(') ? 1 : -1;
        sum[x] = t;
        lmax[x] = max(t, 0);
        rmin[x] = min(t, 0);
        lans[x] = rans[x] = lrans[x] = maxx[x] = abs(t);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, x + x);
    build(mid + 1, r, x + x + 1);
    pushup(x);
}
void modify(int l, int r, int p, int x)
{
    if (l == r)
    {
        int t = (s[l] == '(') ? 1 : -1;
        sum[x] = t;
        lmax[x] = max(t, 0);
        rmin[x] = min(t, 0);
        lans[x] = rans[x] = lrans[x] = maxx[x] = abs(t);
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
    {
        modify(l, mid, p, x + x);
    }
    else
    {
        modify(mid + 1, r, p, x + x + 1);
    }
    pushup(x);
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%s", &n, &q, s + 1);
    n = n * 2 - 2;
    build(1, n, 1);
    printf("%d\n", maxx[1]);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        swap(s[l], s[r]);
        modify(1, n, l, 1);
        modify(1, n, r, 1);
        printf("%d\n", maxx[1]);
    }
    return 0;
}