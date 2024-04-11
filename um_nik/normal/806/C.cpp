#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int K = 42;
int a[K];
int b[K];

void read()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        ll x;
        scanf("%lld", &x);
        int k = 0;
        while((1LL << k) < x) k++;
        if ((1LL << k) == x)
            a[k]++;
        else
            b[k]++;
    }
    return;
}

bool solve(int m)
{
    int k = a[0] - m + b[0];
    for (int i = 1; i < K; i++)
    {
        k += b[i];
        k -= max(0, m - a[i]);
        k = max(k, 0);
        m = min(m, a[i]);
        k += a[i] - m;
    }
    return k == 0;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();

    bool ok = false;

    for (int i = 1; i <= a[0]; i++)
        if (solve(i))
        {
            printf("%d ", i);
            ok = true;
        }

    if (!ok)
        printf("-1");
    printf("\n");
    
    return 0;
}