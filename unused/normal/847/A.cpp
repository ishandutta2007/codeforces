#include <bits/stdc++.h>
using namespace std;

int nxt[105], prv[105];
list<int>::iterator itr[105];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d",&prv[i],&nxt[i]);
    }

    list<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (prv[i]) continue;

        list<int> lst;
        int now = i;
        for (;;)
        {
            lst.push_back(now);
            if (nxt[now] == 0) break;
            now = nxt[now];
        }

        ans.splice(ans.end(), lst);
    }

    for (auto it = ans.begin(); it != ans.end(); ++it) itr[*it] = it;

    for (int i = 1; i <= n; i++)
    {
        if (itr[i] == ans.begin()) prv[i] = 0;
        else prv[i] = *prev(itr[i]);
        if (itr[i] == prev(ans.end())) nxt[i] = 0;
        else nxt[i] = *next(itr[i]);

        printf("%d %d\n", prv[i], nxt[i]);
    }
}