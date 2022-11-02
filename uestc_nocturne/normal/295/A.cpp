/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
LL tr[V];
int N;
void update(int k, LL v)
{
    while(k <= N)
    {
        tr[k] += v;
        k += k & -k;
    }
}
LL read(int k)
{
    LL ret = 0;
    while(k)
    {
        ret += tr[k];
        k -= k & -k;
    }
    return ret;
}
int l[V], r[V], a[V], n, m, K, x, y;
LL d[V];
int main()
{
    while(~scanf("%d%d%d", &n, &m, &K))
    {
        N = m;
        for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
        memset(tr, 0, sizeof(tr));
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%I64d", &l[i], &r[i], &d[i]);
        }
        for(int i = 0; i < K; i++)
        {
            scanf("%d%d", &x, &y);
            update(x, 1);
            update(y + 1, -1);
        }
        for(int i = 1; i <= m; i++)
        d[i] *= read(i);
        N = n;
        memset(tr, 0, sizeof(tr));
        for(int i = 1; i <= m; i++)
        {
            update(l[i], d[i]);
            update(r[i] + 1, -d[i]);
        }
        for(int i = 1; i <= n; i++)
        printf("%I64d ", a[i] + read(i));
    }
}