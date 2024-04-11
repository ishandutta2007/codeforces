#include <iostream>
#include <algorithm>
using namespace std;

const double eps = 1e-10;

int n;
double p[200];
double sum;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &p[i]);
        if (p[i] + eps >= 1.0)
        {
            printf("1.0000000000\n");
            return 0;
        }
    }
    sort(p, p + n);
    reverse(p, p + n);
    int x = 0;
    while (x < n && sum < 1.)
    {
        sum += p[x] / (1 - p[x]);
        x++;
    }
    for (int i = 0; i < x; i++)
        sum *= (1 - p[i]);
    printf("%.10lf\n", sum);
    return 0;
}