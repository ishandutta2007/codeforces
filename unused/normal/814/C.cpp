#include <bits/stdc++.h>
using namespace std;

char str[1505];
int mp[26][1505];
vector<pair<int, int>> vt[26];

int main()
{
    int n;
    scanf("%d%s", &n, str + 1);

    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = 0;
            for (int k = 0; k + j <= n; k++)
            {
                if (str[k + j] == i + 'a') ++x;

                mp[i][k + 1 - x] = max(mp[i][k + 1 - x], k + 1);
            }
        }

        for (int j = 0; j <= 1500; j++)
        {
            if (mp[i][j]) vt[i].emplace_back(j, mp[i][j]);
        }
    }

    int q;
    scanf("%d",&q);
    while (q--)
    {
        int a; char c;
        scanf("%d %c", &a, &c);
        printf("%d\n", prev(upper_bound(vt[c - 'a'].begin(), vt[c - 'a'].end(), make_pair(a, INT_MAX)))->second);
    }

    fflush(stdout);
    _Exit(0);
}