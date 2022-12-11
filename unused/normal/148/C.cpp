#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    if (b == 0)
    {
        if (n == 1) printf("1\n");
        else if (n == a + 1) printf("-1\n");
        else
        {
            printf("2 1 ");
            n -= 2;
            int last = 3;
            while (a--)
            {
                printf("%d ", last++);
                --n;
            }
            while (n--) printf("1 ");
            printf("\n");
        }
        return 0;
    }

    vector<int> ans;
    ans.push_back(1);
    --n;
    while (b--)
    {
        ans.push_back(1 << ans.size());
        --n;
    }
    while (a--)
    {
        ans.push_back(ans.back() + 1);
        --n;
    }
    while (n--) ans.push_back(1);

    for (int t : ans) printf("%d ", t);
    printf("\n");
}