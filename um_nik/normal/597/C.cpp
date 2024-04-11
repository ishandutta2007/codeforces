#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 3;
const int K = 13;
ll t[K][N];
int n, k;

void add(int id, int v, ll d)
{
    for (; v < N; v = (v | (v + 1)))
        t[id][v] += d;
    return;
}
ll get(int id, int r)
{
    ll res = 0;
    for (; r > 0; r = (r & (r + 1)) - 1)
        res += t[id][r];
    return res;
}

int main()
{
    scanf("%d%d", &n, &k);
    k++;
    add(0, 0, 1);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        for (int t = k; t > 0; t--)
            add(t, x, get(t - 1, x));
    }
    printf("%lld\n", get(k, n));
    return 0;
}