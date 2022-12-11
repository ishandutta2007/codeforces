#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

// tree<key_type, value_type(set if null), comparator, ...>
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag ,
tree_order_statistics_node_update >;

ordered_set st;

vector<ordered_set::iterator> vt[200005];
vector<int> pos[100005];

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        pos[x].push_back(i);
    }

    for (int i = 1, pre = 1e9, now = 1; i <= 100000; i++)
    {
        if (pos[i].empty()) continue;
        if (pre < pos[i].front() || pos[i].back() < pre)
        {
            for (int j : pos[i]) vt[now].push_back(st.insert(j).first);
            pre = pos[i].back();
            ++now;
        }
        else
        {
            for (int j : pos[i]) if (j > pre) vt[now].push_back(st.insert(j).first);
            ++now;
            int nxt = -1;
            for (int j : pos[i]) if (j < pre) nxt = max(nxt, j), vt[now].push_back(st.insert(j).first);
            ++now;
            pre = nxt;
        }
    }

    int p = 0;
    long long ans = 0;

    for (int i = 1; i <= 200000; i++)
    {
        for (auto it : vt[i])
        {
            int odr = st.order_of_key(*it);
            ans += (st.order_of_key(*it) - p + st.size()) % st.size() + 1;
            st.erase(*it);
            if (st.size()) p = odr % st.size();
        }
    }

    printf("%lld\n", ans);
}