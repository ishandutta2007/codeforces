#pragma GCC target("arch=haswell")
#include <bits/stdc++.h>
using namespace std;

int dat[100005];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);

    if (k == 1) printf("%d\n", *min_element(dat, dat + n));
    else if (k == 2)
    {
        multiset<int> st1(dat, dat + n), st2;
        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            st2.insert(dat[i]);
            st1.erase(st1.find(dat[i]));
            ans = max({ans, *st1.begin(), *st2.begin()});
        }
        printf("%d\n", ans);
    }
    else printf("%d\n", *max_element(dat, dat + n));
}