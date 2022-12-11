#include <bits/stdc++.h>
using namespace std;

map<int, vector<tuple<int, int, int>>> event;
map<int, int> L;
map<int, multiset<int>> R;

int main()
{
    int n, x;
    scanf("%d%d",&n,&x);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        event[a].emplace_back(-1, b - a + 1, c);
        event[b].emplace_back(1, b - a + 1, c);
        R[b - a + 1].insert(c);
    }

    int ans = INT_MAX;

    for (auto &e : event)
    {
        sort(e.second.begin(), e.second.end());
        for (auto &p : e.second)
        {
            int a, b, c;
            tie(a, b, c) = p;
            if (a == -1)
            {
                R[b].erase(R[b].find(c));
                if (R[b].empty()) R.erase(b);
            }
            else
            {
                int &z = L.emplace(b, INT_MAX).first->second;
                z = min(z, c);
                auto itr = R.find(x - b);
                if (itr != R.end()) ans = min(ans, c + *itr->second.begin());
            }
        }
    }

    if (ans == INT_MAX) printf("-1\n");
    else printf("%d\n", ans);
}