#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[105];
int b[105];
int ans[105];

int main()
{
    cin.sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;
    sort(a+1, a+1+n);

    for (int i = 1; i <= n; i++)
    {
        b[i] = (a[i].first + 1) / 2;
        w -= b[i];
    }

    if (w < 0)
    {
        printf("-1\n");
        return 0;
    }

    for (int i = n; i >= 1; i--)
    {
        int diff = min(w, a[i].first - b[i]);
        b[i] += diff;
        w -= diff;
    }

    if (w > 0)
    {
        printf("-1\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) ans[a[i].second] = b[i];
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}