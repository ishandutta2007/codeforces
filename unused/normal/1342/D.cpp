#include <bits/stdc++.h>
using namespace std;

int cnt[200005];
int c[200005];
int n, k;

bool check(int t, bool print = false)
{
        vector<int> vt[t];

        int ptr = 0;
        for (int i = k; i >= 1; i--)
        {
                for (int j = 0; j < cnt[i]; j++)
                {
                        vt[ptr].push_back(i);
                        if (vt[ptr].size() > c[i]) return false;
                        ++ptr;
                        if (ptr == t) ptr = 0;
                }
        }

        if (print)
        {
                printf("%d\n", t);
                for (int i = 0; i < t; i++)
                {
                        printf("%zd", vt[i].size());
                        for (int x : vt[i]) printf(" %d", x);
                        printf("\n");
                }
        }

        return true;
}

int main()
{
        scanf("%d%d",&n,&k);
        for (int i = 0; i < n; i++)
        {
                int x;
                scanf("%d", &x);
                cnt[x]++;
        }
        for (int i = 1; i <= k; i++) scanf("%d", &c[i]);

        int lo = 1, hi = n - 1, ans = n;
        while (lo <= hi)
        {
                int mid = (lo + hi) >> 1;
                if (check(mid))
                {
                        ans = mid;
                        hi = mid - 1;
                }
                else
                {
                        lo = mid + 1;
                }
        }

        check(ans, true);
}