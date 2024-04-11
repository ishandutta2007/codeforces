#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
int n, k;
map<vector<pair<int, int> >, int> mp;
int main()
{
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        vector<pair<int, int> > v1, v2;
        for (int j = 2; j * j <= x; j++)
        {
            int sum = 0;
            while (!(x % j))
            {
                sum++;
                x /= j;
            }
            if (sum % k)
            {
                v1.push_back(make_pair(j, sum % k));
            }
        }
        if (x > 1)
        {
            v1.push_back(make_pair(x, 1));
        }
        for (int j = 0; j < (int)v1.size(); j++)
        {
            v2.push_back(make_pair(v1[j].first, k - v1[j].second));
        }
        ans += mp[v2];
        mp[v1]++;
    }
    printf("%lld", ans);
    return 0;
}