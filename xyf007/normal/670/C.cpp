#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define id(a, i) lower_bound(v.begin(), v.end(), a[i]) - v.begin()
using namespace std;
int n, m, a[200001], b[200001], c[200001], sum[600001];
vector<int> v;
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
        v.push_back(b[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &c[i]);
        v.push_back(c[i]);
    }
    sort(v.begin(), v.end());
    unique(v.begin(), v.end()) - v.begin();
    int max1 = -1, max2 = -1, t = -1;
    for (int i = 1; i <= n; i++)
    {
        sum[id(a, i)]++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (sum[id(b, i)] > max1)
        {
            max1 = sum[id(b, i)];
            max2 = sum[id(c, i)];
            t = i;
        }
        else
        {
            if (sum[id(b, i)] == max1 && sum[id(c, i)] > max2)
            {
                max2 = sum[id(c, i)];
                t = i;
            }
        }
    }
    printf("%d", t);
    return 0;
}//