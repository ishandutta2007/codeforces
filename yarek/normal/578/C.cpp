#include <cstdio>
#include <algorithm>
using namespace std;

int a[200000];
int n;

double f(double x)
{
    double mn = 0, mx = 0, cmn = 0, cmx = 0;
    for(int i = 0; i < n; i++)
    {
	cmn = min(cmn + a[i] - x, a[i] - x);
	cmx = max(cmx + a[i] - x, a[i] - x);
	mn = min(mn, cmn);
	mx = max(mx, cmx);
    }
    return max(-mn, mx);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
	scanf("%d", a + i);
    double a = -10000, b = 10000;
    for(int i = 0; i < 90; i++)
    {
	double c1 = (a + a + b) / 3, c2 = (a + b + b) / 3;
	if(f(c1) > f(c2))
	    a = c1;
	else b = c2;
    }
    printf("%.10lf", f(a));
}