#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k, a[100001], tmp[100001];
void solve(int l, int r)
{
    if (!k || l + 1 == r)
    {
        return;
    }
    int mid = (l + r) >> 1, t = 0;
    for (int i = l; i < l + r - mid; i++)
    {
        tmp[++t] = a[i];
    }
    for (int i = l; i < mid; i++)
    {
        a[i] = a[i + r - mid];
    }
    for (int i = mid; i < r; i++)
    {
        a[i] = tmp[i - mid + 1];
    }
    k -= 2;
    solve(l, mid);
    solve(mid, r);
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &k);
    if (!(k % 2))
    {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    k--;
    solve(0, n);
    if (k)
    {
        printf("-1");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}