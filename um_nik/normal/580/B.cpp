#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;
#define mp make_pair
#define X first
#define Y second

const int N = 100100;
int n;
int d;
pil a[N];
ll ans;
ll sum[N];

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%d%lld", &a[i].X, &a[i].Y);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i].Y;
    int r = 0;
    for (int l = 0; l < n; l++)
    {
        while(r < n && a[r].X < a[l].X + d) r++;
        ans = max(ans, sum[r] - sum[l]);
    }
    printf("%lld\n", ans);

    return 0;
}