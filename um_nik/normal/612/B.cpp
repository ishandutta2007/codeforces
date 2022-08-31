#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 200200;
int n;
ll a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        a[x] = i;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++)
        ans += abs(a[i] - a[i + 1]);
    printf("%lld\n", ans);

    return 0;
}