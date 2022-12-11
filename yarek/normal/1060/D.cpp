#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100001;
int l[N];
int r[N];

int main()
{
    int n;
    scanf("%d", &n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", l + i, r + i);
        ans += l[i] + r[i];
    }
    sort(l, l + n);
    sort(r, r + n);
    for(int i = 0; i < n; i++)
        ans += abs(l[i] - r[i]);
    printf("%lld\n", ans / 2 + n);
}