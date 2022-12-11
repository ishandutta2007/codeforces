#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

struct radio
{
    int x,r,f;
    bool operator<(const radio &rh) const
    {
        return r < rh.r;
    }
};

ordered_set<int> sets[10005];
radio dat[100005];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d",&dat[i].x,&dat[i].r,&dat[i].f);
        sets[dat[i].f].insert(dat[i].x);
    }

    sort(dat, dat + n);

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = max(1, dat[i].f - k); j <= min(10000, dat[i].f + k); j++)
        {
            ans += sets[j].order_of_key(dat[i].x + dat[i].r + 1) - sets[j].order_of_key(dat[i].x - dat[i].r);
        }

        sets[dat[i].f].erase(dat[i].x);
    }

    printf("%lld\n", ans - n);
}