#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

double k[4];
const double inf = 1e10;

bool check(double d)
{
    double mn = inf, mx = -inf;
    for(int i = 0; i < 16; i++)
    {
	double t[2] = { 1, 1 };
	for(int j = 0; j < 4; j++)
	    t[j / 2] *= k[j] + (d * ((i & (1 << j)) ? 1 : -1));
	double a = t[0] - t[1];
	mn = min(a, mn);
	mx = max(a, mx);
    }
//     printf("%lf: mn = %lf, mx = %lf\n", d, mn, mx);
    return mn <= 0 && mx >= 0;
}

int main()
{
    scanf("%lf %lf %lf %lf", k + 0, k + 2, k + 3, k + 1);
    double ans = max(min(fabs(k[0]), fabs(k[1])), min(fabs(k[2]), fabs(k[3])));
    double a = 0, b = ans, c;
//     if(k[0] * k[1] * k[2] * k[3] >= 0)
    {
	for(int i = 0; i < 70; i++)
	{
	    c = (a + b) / 2;
	    if(check(c)) b = c;
	    else a = c;
	}
	ans = a;
    }
    printf("%.10lf\n", ans);
}