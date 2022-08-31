#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double INF = 1e10;
const int IT = 200;
const int N = 200100;
int n;
double a[N];
double b[N];

double calcMax()
{
    double res = 0;
    double bal = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, bal);
        bal += b[i];
        bal = max(bal, 0.);
    }
    return max(res, bal);
}
double calcMin()
{
    double res = 0;
    double bal = 0;
    for (int i = 0; i < n; i++)
    {
        res = min(res, bal);
        bal += b[i];
        bal = min(bal, 0.);
    }
    return min(res, bal);
}

bool check(double x)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i] - x;
    double A = calcMax();
    double B = calcMin();
    return (-B > A);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &a[i]);
    double L = -INF, R = INF;
    for (int it = 0; it < IT; it++)
    {
        double x = (L + R) / 2;
        if (check(x))
            R = x;
        else
            L = x;
    }
    for (int i = 0; i < n; i++)
        b[i] = a[i] - L;
    printf("%.12lf\n", calcMax());

    return 0;
}