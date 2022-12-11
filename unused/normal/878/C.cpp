#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vt;

struct comp
{
    template <typename T, typename V>
    bool operator()(T &&a, V &&b) const
    {
        if (&a == &vt)
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i].first < b[i].second) return true;
            }
            return false;
        }
        else if (&b == &vt)
        {
            return !operator()(b, a);
        }
        else return a < b;
    }
};

map<vector<pair<int, int>>, int, comp> mp;

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);

    for (int i = 0; i < n; i++)
    {
        vt.clear();
        for (int j = 0; j < k; j++)
        {
            int x; scanf("%d",&x); vt.emplace_back(x, x);
        }

        int sum = 1;
        auto itr = mp.lower_bound(vt);
        while (itr != mp.end())
        {
            bool c1 = false, c2 = false;
            for (int j = 0; j < k; j++)
            {
                if (itr->first[j].second >= vt[j].first) c1 = true;
                if (vt[j].second >= itr->first[j].first) c2 = true;
            }
            if (c1 == false || c2 == false) break;

            for (int j = 0; j < k; j++)
            {
                vt[j].first = min(vt[j].first, itr->first[j].first);
                vt[j].second = max(vt[j].second, itr->first[j].second);
            }

            sum += itr->second;
            itr = mp.erase(itr);
        }

        mp.emplace(move(vt), sum);

        printf("%d\n", mp.rbegin()->second);
    }
}