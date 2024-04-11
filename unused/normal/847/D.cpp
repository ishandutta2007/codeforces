#include <bits/stdc++.h>
using namespace std;

int dat[200005];
map<int, int> mp;

int main()
{
    int n, t;
    scanf("%d%d",&n,&t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&dat[i]);
        if (t - i <= max(0, dat[i] - i)) continue;

        mp[max(0, dat[i] - i)]++;
        mp[t - i]--;

        // dat[i]    : max(0, dat[i] - i)
        // dat[i]   : t - i
    }

    int ans = 0, now = 0;
    for (auto &e : mp)
    {
        now += e.second;
        ans = max(ans, now);
    }

    printf("%d\n", ans);
}