#include <bits/stdc++.h>
using namespace std;

set<int> L, R;
int nxt[200005];
bool vis[200005];

int main()
{
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            L.insert(i);
            R.insert(i);
        }
        nxt[i] = -1;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            auto itr1 = L.lower_bound(i);
            if (itr1 == L.begin())
            {
                printf("-1\n");
                return 0;
            }
            nxt[*prev(itr1)] = i;
            L.erase(prev(itr1));

            auto itr2 = R.lower_bound(i);
            if (itr2 == R.end())
            {
                printf("-1\n");
                return 0;
            }

            nxt[i] = *itr2;
            R.erase(itr2);
        }
    }

    vector<vector<int>> ans;

    for (int ii = 0; ii < s.size(); ii++)
    {
        int i = ii;
        if (vis[i]) continue;
        vector<int> vt;
        for (;;)
        {
            vis[i] = true;
            vt.push_back(i);
            if (nxt[i] == -1) break;
            i = nxt[i];
        }
        ans.emplace_back(move(vt));
    }

    printf("%zd\n", ans.size());
    for (auto &vt : ans)
    {
        printf("%zd", vt.size());
        for (int t : vt) printf(" %d", t + 1);
        printf("\n");
    }
}