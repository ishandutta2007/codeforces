#include <bits/stdc++.h>
using namespace std;
 
const int Maxl = 1 << 16 | 5, Maxn = 105;
int n, m, t, x, u[Maxn], v[Maxn], c[Maxn], rev[Maxl], G[Maxn][Maxn];
double f[Maxn][Maxl], g[Maxn][Maxl], p[Maxn][Maxl];
void get_rev(int len)
{
	for (int i = 0; i < len; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
}
struct Complex
{
	double Re, Im;
	Complex operator + (const Complex &A) const
	{
		return (Complex){Re + A.Re, Im + A.Im};
	}
	Complex operator - (const Complex &A) const
	{
		return (Complex){Re - A.Re, Im - A.Im};
	}
	Complex operator * (const Complex &A) const
	{
		return (Complex){Re * A.Re - Im * A.Im, Re * A.Im + Im * A.Re};
	}
	Complex inv(void) const
	{
		double D = Re * Re + Im * Im;
		return (Complex){Re / D, -Im / D};
	}
	Complex operator / (const Complex &A) const
	{
		return *this * A.inv();
	}
	Complex(double _re, double _im)
	{
		Re = _re, Im = _im;
	}
	Complex()
	{
		Im = Re = 0;
	}
} unit[Maxl], a[Maxl], b[Maxl];
const double pi = acos(-1.0);
void FFT(Complex now[], int len, bool type = false)
{
	for (int i = 0; i < len; i++)
		if (i < rev[i]) swap(now[i], now[rev[i]]);
	if (type) reverse(unit + 1, unit + len);
	for (int i = 1; i < len; i <<= 1)
	{
		Complex w = Complex(cos(2 * pi / (i << 1)), (type ? -1 : 1) * sin(2 * pi / (i << 1)));
		for (int j = 0; j < len; j += i << 1)
		{
			Complex l = Complex(1, 0);
			for (int k = j; k < i + j; k++, l = l * w)
			{
				Complex x = now[i + k] * l, y = now[k];
				now[k] = x + y;
				now[i + k] = y - x;
			}
		}
	}
	if (type)
	{
		reverse(unit + 1, unit + len);
		Complex inv = Complex(len, 0).inv();
		for (int i = 0; i < len; i++)
			now[i] = now[i] * inv;
	}
}
void multi(Complex x[], Complex y[], int len)
{
	get_rev(len);
	FFT(x, len), FFT(y, len);
	for (int i = 0; i < len; i++)
		x[i] = x[i] * y[i];
	FFT(x, len, true);
}
int lower(int x)
{
	int tmp = 1;
	for (; tmp < x; tmp <<= 1);
	return tmp;
}
void work(int lt, int rt)
{
	if (lt == t) return ;
	if (lt == rt)
	{
		for (int i = 1; i <= m; i++)
			f[u[i]][lt] = min(f[u[i]][lt], g[i][lt] + c[i]);
		return ;
	}
	int mid = (lt + rt) >> 1;
	work(mid + 1, rt);
	for (int i = 1; i <= m; i++)
	{
		int len = lower(rt - lt + rt - mid);
		memset(a, 0, sizeof(Complex[len]));
		memset(b, 0, sizeof(Complex[len]));
		for (int j = 1; j <= rt - lt + 1; j++)
			a[j - 1] = Complex(p[i][j], 0);
		for (int j = mid + 1; j <= rt; j++)
			b[j - mid - 1] = Complex(f[v[i]][j], 0);
		reverse(a, a + rt - lt + 1);
		multi(a, b, len);
		for (int j = lt; j <= mid; j++)
			g[i][j] += a[rt - lt + j - mid].Re;
	}
	work(lt, mid);
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &t, &x);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= t; j++)
			f[i][j] = 1e18;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			G[i][j] = 0x3f3f3f3f;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &c[i]);
		G[u[i]][v[i]] = c[i];
		for (int j = 1; j <= t; j++)
			scanf("%lf", &p[i][j]), p[i][j] /= 100000;
		if (u[i] == n) i--, m--;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	for (int i = 1; i < 2 * t; i++)
		f[n][i] = i > t ? x : 0;
	for (int i = 1; i < n; i++)
		for (int j = t; j < 2 * t; j++)
			f[i][j] = G[i][n] + x;
	work(0, 2 * t - 1);
	printf("%.10lf", f[1][0]);
	return 0;
}