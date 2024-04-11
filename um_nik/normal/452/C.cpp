#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int n, m;
double ans;
vector<double> a, b;

int main()
{
    scanf("%d%d", &n, &m);
    ans = 0.;
    for (int k = 1; k <= min(m, n); k++)
    {
        a.clear();
        b.clear();
        double tmp = (double)n;
        for (int i = k + 1; i <= n; i++)
            a.push_back((double)i);
        for (int i = 1; i <= n - k; i++)
            b.push_back((double)i);
        for (int i = m - k + 1; i <= m; i++)
            a.push_back((double)i);
        for (int i = m * n - n + 1; i <= m * n; i++)
            b.push_back((double)i);
        for (int i = m * n - n - m + k + 1; i <= m * n - m; i++)
            a.push_back((double)i);
        int it1 = 0, it2 = 0;
        while (it1 < a.size() || it2 < b.size())
        {
            if (tmp < n + 1 && it1 < a.size())
            {
                tmp *= a[it1];
                it1++;
            }
            else
            {
                tmp /= b[it2];
                it2++;
            }
        }
        tmp *= (double)k / (double)n;
        tmp *= (double)k / (double)n;
        ans += tmp;
    }
    printf("%.10lf\n", ans);
    return 0;
}