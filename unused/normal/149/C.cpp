#include <bits/stdc++.h>
using namespace std;

pair<int,int> dat[100005];
set<pair<int,int>> s1, s2;

int main()
{
    int n;
    scanf("%d",&n);
    int maxval = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&dat[i].first);
        dat[i].second = i + 1;
        maxval = max(maxval, dat[i].first);
    }

    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < n / 2; i++)
    {
        s1.insert(dat[i]);
        sum1 += dat[i].first;
    }
    for (int i = n / 2; i < n; i++)
    {
        s2.insert(dat[i]);
        sum2 += dat[i].first;
    }

    if (sum1 < sum2) swap(sum1, sum2), swap(s1, s2);

    while (sum1 > sum2 + maxval)
    {
        auto a1 = *s1.rbegin();
        auto a2 = *s2.begin();

        s1.erase(a1);
        s2.erase(a2);

        sum1 -= a1.first;
        sum2 -= a2.first;
        sum1 += a2.first;
        sum2 += a1.first;

        s1.insert(a2);
        s2.insert(a1);
    }

    printf("%zd\n", s1.size());
    for (auto &&e : s1) printf("%d ", e.second);
    printf("\n%zd\n", s2.size());
    for (auto &&e : s2) printf("%d ", e.second);
    printf("\n");
}