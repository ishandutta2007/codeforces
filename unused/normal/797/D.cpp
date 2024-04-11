#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

int l[100005], r[100005], v[100005];
bool notparent[100005];
int ans;

void recur(int t, ordered_set &st)
{
    if (t == -1 || st.empty())
    {
        ans += st.size();
        return;
    }

    auto cnt1 = st.order_of_key(make_pair(v[t], 0));
    auto cnt2 = st.size() - st.order_of_key(make_pair(v[t], 1000000000));

    if (cnt1 >= st.size() / 2)
    {
        ordered_set st2;
        for (auto itr = prev(st.end()); itr->first >= v[t];)
        {
            if (itr->first > v[t]) st2.insert(*itr);
            itr = st.erase(itr);
            if (itr == st.begin()) break;
            --itr;
        }

        recur(l[t], st);
        recur(r[t], st2);
    }
    else if (cnt2 >= st.size() / 2)
    {
        ordered_set st2;
        for (auto itr = st.begin(); itr != st.end() && itr->first <= v[t]; itr = st.erase(itr))
        {
            if (itr->first < v[t]) st2.insert(*itr);
        }
        recur(l[t], st2);
        recur(r[t], st);
    }
    else
    {
        ordered_set st1;
        for (auto itr = st.begin(); itr != st.end() && itr->first < v[t]; itr++) st1.insert(*itr);
        recur(l[t], st1);

        ordered_set st2;
        for (auto itr = st.rbegin(); itr != st.rend() && itr->first > v[t]; itr++) st2.insert(*itr);
        recur(r[t], st2);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    int parent;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d",&v[i],&l[i],&r[i]);
        if (l[i] != -1) notparent[l[i]] = true;
        if (r[i] != -1) notparent[r[i]] = true;
    }

    for (int i = 1; i <= n; i++) if (!notparent[i]) parent = i;

    ordered_set st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(make_pair(v[i], i));
    }

    recur(parent, st);

    printf("%d\n", ans);
}