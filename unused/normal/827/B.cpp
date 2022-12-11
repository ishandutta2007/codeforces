#include <bits/stdc++.h>
using namespace std;

vector<int> vt[200005];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);

    for (int i = 2; i <= n; i++)
    {
        vt[(i - 2) % k].push_back(i);
    }

    printf("%zd\n", vt[0].size() + vt[1].size());

    for (int i = 0; i < k; i++)
    {
        printf("1 %d\n", vt[i][0]);
        for (int j = 1; j < vt[i].size(); j++)
        {
            printf("%d %d\n", vt[i][j - 1], vt[i][j]);
        }
    }
}