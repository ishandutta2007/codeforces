#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
int p[N];
int change[N];

int main()
{
    int n;
    long long dev = 0;
    int diff = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", p + i);
        p[i]--;
        dev += abs(p[i] - i);
        if(p[i] < i)
        {
            diff--;
            change[i-p[i]]++;
        }
        else
        {
            diff++;
            change[n+i-p[i]]++;
        }
    }
//     printf("%d %lld %d\n", 0, dev, diff);
    pair<long long, int> ans(dev, 0);
    for(int i = 1; i < n; i++)
    {
        dev += diff;
        dev += (n - 1) - p[i-1] - (p[i-1] + 1);
        ans = min(ans, make_pair(dev, i));
        diff -= 2;
        diff += 2 * change[i];
//         printf("%d %lld %d\n", i, dev, diff);
    }
    printf("%lld %d\n", ans.first, (n - ans.second) % n);
}