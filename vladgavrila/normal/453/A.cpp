#include <cstdio>

using namespace std;

int n, m;
double sol, sum;

double lgput(double x, int exp)
{
    if(exp==0)
        return 1.0;

    double aux = lgput(x, exp/2);

    if(exp%2)
        return aux*aux*x;
    return aux*aux;
}

int main()
{
  //  freopen("a.in", "r", stdin);
  //  freopen("b.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(int i=1; i<=n; ++i)
    {
        sol+=(lgput(double(i)/n, m)-lgput(double(i-1)/n, m))*i;
    }

    printf("%.9lf\n", sol);

    return 0;
}