#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

ll getC(ll n, int k)
{
    if (k > n) return 0;
    ll res = 1;
    for (int i = 0; i < k; i++)
    {
        res *= n - i;
        res /= i + 1;
    }
    return res;
}

ll pw(ll x, ll p)
{
    if (p < 0) return 0;
    ll r = 1;
    while(p--)
        r *= x;
    return r;
}

int main()
{
	double PI = 4 * atan(1.);
	int n;
	scanf("%d", &n);
	double L = 2 * sin(PI / n * (n / 2));
	double l1 = L - L * L / (L + 2 * sin(PI / n * (n / 2 - 1)));
	double x1 = 2 * sin(PI / n), x2 = 2 * sin(PI / n * 2);
	double l2 = L * x1 / (x1 + x2);
//	printf("%.5lf %.5lf\n", l1, l2);
	double S = n * l1 * l2 * sin(PI / n) / 2;
	L -= 2 * l1;
	double R = L / 2 / sin(PI / n);
	S += n * R * R * sin(2 * PI / n) / 2;
	scanf("%lf", &R);
	S *= R * R;
	printf("%.13lf\n", S);

    return 0;
}