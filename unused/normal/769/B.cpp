#include <bits/stdc++.h>
using namespace std;

pair<int,int> d[111];
vector<int> s[111];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&d[i].first);
        d[i].second = i;
    }
    sort(d+1,d+n,greater<>());

    int last = 1;
    int sum = d[0].first;

    for (int i = 0; i < d[0].first; i++)
    {
        if (last == n) s[0].push_back(1);
        else s[0].push_back(last++);
    }

    for (int i = 1; i < n; i++)
    {
        if (last <= i)
        {
            printf("-1\n");
            return 0;
        }
        for (int j = 0; j < d[i].first; j++)
        {
            if (last == n) s[i].push_back(0);
            else s[i].push_back(last++);
        }
        sum += d[i].first;
    }
    printf("%d\n", sum);
    for (int i = 0; i < n; i++)
    {
        for (int j : s[i]) printf("%d %d\n", d[i].second + 1, d[j].second + 1);
    }
}