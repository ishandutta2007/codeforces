#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = (int)1e5;
double p[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &p[i]);
    sort(p, p + n);
    if (p[n - 1] == 1.)
    {
        printf("%.10lf", p[n - 1]);
        return 0;
    }
    double ans = 0;
    for (int i = 0; i < n; i++)
        for (int s = i; s < n; s++)
        {
            double pr = 1;
            for (int q = i; q <= s; q++)
            {
                pr *= 1 - p[q];
            }
            double sum = 0;
            for (int q = i; q <= s; q++)
                sum += p[q] / (1 - p[q]);
            ans = max(ans, pr * sum);
        }
    printf("%.10lf", ans);
    return 0;
}