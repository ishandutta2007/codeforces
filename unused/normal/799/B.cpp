#include <bits/stdc++.h>
using namespace std;

int p[200005];
int a[200005];
int b[200005];
int c[200005];

multiset<pair<int, int>> fst[4];
multiset<pair<int, int>> snd[4];

int main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        fst[a[i]].emplace(p[i], b[i]);
        snd[b[i]].emplace(p[i], a[i]);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;

        auto itr1 = fst[x].begin();
        auto itr2 = snd[x].begin();
        if (itr1 == fst[x].end() && itr2 == snd[x].end())
        {
            printf("-1 ");
            continue;
        }
        else if (itr1 == fst[x].end())
        {
            secondbuy:
            int a, b;
            tie(a, b) = *itr2;
            printf("%d ", a);
            snd[x].erase(itr2);
            fst[b].erase(fst[b].find({a, x}));
        }
        else if (itr2 == snd[x].end())
        {
            firstbuy:
            int a, b;
            tie(a, b) = *itr1;
            printf("%d ", a);
            fst[x].erase(itr1);
            snd[b].erase(snd[b].find({a, x}));
        }
        else
        {
            if (itr1->first < itr2->first) goto firstbuy;
            else goto secondbuy;
        }
    }
    printf("\n");
}