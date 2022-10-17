#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ll long long
#define maxn 2000005
using namespace std;
int s[maxn], x, n, m, t[maxn];
const double pi = acos(-1);
struct cp
{
	cp (double xx = 0, double yy = 0){x = xx, y = yy;}
	double x, y;
	cp operator + (cp const & a) const
	{return cp(x + a.x, y + a.y);}
	cp operator - (cp const & a) const
	{return cp(x - a.x, y - a.y);}
	cp operator * (cp const & a) const
	{return cp(x * a.x - y * a.y, x * a.y + y * a.x);}
}a[maxn << 1], b[maxn << 1];
int tr[maxn << 1];
void fft(cp *f, bool flag)
{
	for (int i = 0; i < n; i++)
	{
		if(i < tr[i]) swap(f[i], f[tr[i]]);
	}
	for (int i = 2; i <= n; i <<= 1)
	{
		int len = i / 2;
		cp bas(cos(2 * pi / i), sin(2 * pi / i));
		if(!flag) bas.y *= -1;
		for (int j = 0; j < n; j += i)
		{
			cp now(1, 0);
			for (int k = j; k < j + len; k++)
			{
				cp tmp = now * f[k + len];
				f[k + len] = f[k] - tmp;
				f[k] = f[k] + tmp;
				now = now * bas;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &x);
	a[0].x = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &s[i]);
		if(s[i] < x) s[i] = 1;
		else s[i] = 0;
		s[i] += s[i - 1];
		a[s[i]].x++;
	}
	for (int i = 0; i <= n; i++)
	{
		b[i].x = a[n - i].x;
	}
//	for (int i = 0; i <= n; i++) printf("%.0f ", a[i].x);
//	printf("\n");
//	for (int i = 0; i <= n; i++) printf("%.0f ", b[i].x);
//	printf("\n");
	int m = 2 * n;
	for (n = 1; n <= m; n <<= 1);
	for (int i = 0; i < n; i++) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
	fft(a, 1), fft(b, 1);
	for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
	fft(a, 0);
	int last = 1;
	ll cnt = 0;
	for (int i = 1; i <= m / 2; i++)
	{
		if(s[i] > s[i - 1])
		{
			cnt += (ll)last * (last - 1) / 2;
			last = 0;
		}
		last++;
	}
	printf("%lld ", cnt + (ll)last * (last - 1) / 2);
	for (int i = m / 2 + 1; i <= m; i++)
	{
		printf("%lld ", (ll)(a[i].x / n + 0.49));
	}
	return 0;
}