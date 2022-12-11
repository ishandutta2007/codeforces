#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
        int n, d, m;
        scanf("%d%d%d",&n,&d,&m);
        vector<int> small, large;
        for (int i = 0; i < n; i++)
        {
                int x;
                scanf("%d",&x);
                if (x > m) large.push_back(x);
                else small.push_back(x);
        }

        sort(small.begin(), small.end(), greater<>());
        sort(large.begin(), large.end());

        vector<long long> presum(large.size() + 1);
        for (int i = 1; i <= large.size(); i++)
        {
                presum[i] = presum[i - 1] + large[i - 1];
        }

        long long sum = 0;
        long long ans = 0;
        for (int i = 0;; i++)
        {
                // left: n - i
                //  (n-i+d)/(d+1)    .
                ans = max(ans, sum + presum[large.size()] - presum[max(0, (int)large.size() - (n - i + d) / (d + 1))]);
                if (i == small.size()) break;
                sum += small[i];
        }

        printf("%lld\n", ans);
}