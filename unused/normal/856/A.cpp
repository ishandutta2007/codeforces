#include <bits/stdc++.h>
using namespace std;

int a[105];
bitset<1000001> z;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        z.reset();
        sort(a, a + n);

        set<int> diffs;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) diffs.insert(a[j] - a[i]);
        vector<int> ans;
        for (int i = 1; i <= 1000000 && ans.size() < n; i++)
        {
            if (z[i] == false)
            {
                ans.push_back(i);
                for (int j : diffs)
                {
                    if (i + j > 1000000) break;
                    z[i + j] = true;
                }
            }
        }

        if (ans.size() < n) printf("NO\n");
        else
        {
            printf("YES\n");
            for (int t : ans) printf("%d ", t);
            printf("\n");
        }
    }
}