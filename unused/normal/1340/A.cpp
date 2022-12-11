#include <bits/stdc++.h>
using namespace std;

int d[100005];
int siz[100005];

void proc()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        d[x] = i;
    }

    for (int i = 0; i < n; i++)
    {
        siz[i] = 1;
    }

    multiset<int> rem;
    set<int> alive;
    for (int i = 0; i < n; i++)
    {
        rem.insert(1);
        alive.insert(i);
    }

    for (int i = 1; i <= n; i++)
    {
        int cur = d[i];
        if (siz[cur] != *rem.rbegin())
        {
            printf("No\n");
            return;
        }
        rem.erase(prev(rem.end()));
        alive.erase(cur);
        auto itr = alive.lower_bound(cur);
        if (itr == alive.end()) continue;
        rem.erase(rem.find(siz[*itr]));
        siz[*itr] += siz[cur];
        rem.insert(siz[*itr]);
    }

    printf("Yes\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) proc();
}