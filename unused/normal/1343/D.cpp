#include <bits/stdc++.h>
using namespace std;

int d[200005];
pair<int, int> pos[200005];
int u[200005];

void proc()
{
        int n, k;
        scanf("%d%d",&n,&k);
        map<int, int> sums;
        for (int i = 0; i < n; i++) scanf("%d",&d[i]);
        for (int i = 0; i < n / 2; i++) sums[d[i] + d[n - i - 1]]++;
        for (int i = 0; i < n / 2; i++) u[i] = 2;
        for (int i = 0; i < n / 2; i++)
        {
                pos[i * 2] = {d[i], i};
                pos[i * 2 + 1] = {d[n - 1 - i], i};
        }
        sort(pos, pos + n);

        int ans = n, two = n / 2;

        // both (upper OR significantly lower): 2
        // exactly same: 0
        // everything else: 1

        int fp1 = 0, fp2 = 0;

        for (int tr = 2; tr <= 2 * k; tr++)
        {
                while (fp1 < n && pos[fp1].first < tr)
                {
                        int x = pos[fp1].second;
                        if (u[x] == 2) --two;
                        --u[x];
                        ++fp1;
                }
                while (fp2 < n && pos[fp2].first < tr - k)
                {
                        int x = pos[fp2].second;
                        if (u[x] == 1) ++two;
                        ++u[x];
                        ++fp2;
                }

                ans = min(ans, n / 2 + two - sums[tr]);
        }

        printf("%d\n", ans);
}

int main()
{
        int t;
        scanf("%d",&t);
        while (t--) proc();
}