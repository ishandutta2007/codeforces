#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, a, b;
        scanf("%d%d%d", &n, &b, &a);
        if (a > b + 1 || a + 1 < b)
        {
            printf("-1\n");
            continue;
        }
        if (a + b > n - 2)
        {
            printf("-1\n");
            continue;
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++) ans.push_back(i);

        if (a < b)
        {
            for (int i = 0; i < b; i++) swap(ans.rbegin()[i * 2], ans.rbegin()[i * 2 + 1]);
        }
        else if (a > b)
        {
            for (int i = 0; i < a; i++) swap(ans[i * 2], ans[i * 2 + 1]);
        }
        else
        {
            for (int i = 0; i < a; i++) swap(ans[i * 2 + 1], ans[i * 2 + 2]);
        }

        for (int t : ans) printf("%d ", t);
        printf("\n");
    }
}