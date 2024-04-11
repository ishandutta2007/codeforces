#include <iostream>
using namespace std;

double x;
double a[20][20];
double eps = 2e-6;

int main()
{
    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++)
        {
            double x = (double)i;
            double y = (double)j;
            a[i][j] = x * y / sqrt(x * x + 4. * y * y);
        }
    scanf("%lf", &x);
    for (int i = 1; i < 11; i++)
        for (int j = 1; j < 11; j++)
        {
            if (fabs(x - a[i][j]) < eps)
            {
                printf("%d %d\n", i, j);
                //cin >> x;
                return 0;
            }
        }

    return 0;
}