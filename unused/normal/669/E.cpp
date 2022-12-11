#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <map>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct query
{
        int a, t, x;
};

map<int, int> xidx;
ordered_set pst[100005];
ordered_set mst[100005];
query dat[100005];

int main()
{
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
                scanf("%d%d%d", &dat[i].a, &dat[i].t, &dat[i].x);
                xidx.emplace(dat[i].x, 0);
        }

        int tmp = 0;
        for (auto &&e : xidx)
        {
                e.second = tmp++;
        }

        for (int i = 0; i < n; i++)
        {
                if (dat[i].a == 1) pst[xidx[dat[i].x]].insert({dat[i].t,i});
                else if (dat[i].a == 2) mst[xidx[dat[i].x]].insert({dat[i].t,i});
                else
                {
                        int idx = xidx[dat[i].x];
                        printf("%d\n",(int)(pst[idx].order_of_key({dat[i].t+1,-1})-mst[idx].order_of_key({dat[i].t+1,-1})));
                }
        }
}