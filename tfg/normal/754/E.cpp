#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <algorithm>
#include <iomanip>

const double PI = acos(-1.0);
typedef std::complex<double> Complex;
typedef std::vector<Complex> CVector;

CVector fft(CVector x, bool inv = false)
{
	int n = x.size();

	for(int i=0;i<n;i++)
	{
		int to = 0, on = i, bits = n-1;
		while(bits)
		{
			to = (to << 1) | (on & 1);
			on >>= 1;
			bits >>= 1;
		}
		if(i<to)
			std::swap(x[i], x[to]);
	}

	for(int len=1;len<n;len<<=1)
	{
		double angle = PI / len;
		if(inv)
			angle = -angle;
		Complex root = Complex(cos(angle), sin(angle));

		for(int i=0;i<n;i+=len<<1)
		{
			Complex cur_root = Complex(1.0, 0.0);
			for(int j=0;j<len;j++)
			{
				Complex a = x[i + j];
				Complex b = x[i + j + len];
				Complex c = cur_root * b;
				x[i + j] = a + c;
				x[i + j + len] = a - c;
				cur_root = cur_root * root;
			}
		}
	}
	if(inv)
	{
		for(int i=0;i<n;i++)
			x[i] /= n;
	}
	return x;
}

std::vector<CVector> fft2d(std::vector<CVector> a, bool inv = false)
{
	for(int i=0;i<a.size();i++)
		a[i] = fft(a[i], inv);
	for(int j=0;j<a[0].size();j++)
	{
		CVector b(a.size(), 0);
		for(int i=0;i<a.size();i++)
			b[i] = a[i][j];
		b = fft(b, inv);
		for(int i=0;i<a.size();i++)
			a[i][j] = b[i];
	}
	return a;
}

const int ms=1024;

int main()
{
	std::vector<CVector> a, b;
	a = b = std::vector<CVector> (ms, CVector(ms, 0));

	int n, m;
	std::cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		std::string str;
		std::cin >> str;
		for(int j=0;j<m;j++)
		{
			if(str[j] != '?')
			{
				double angle = 2 * PI * (str[j] - 'a') / ('z' - 'a' + 1);
				a[i][j] = Complex(cos(angle), sin(angle));
			}
		}
	}

	int r, c;
	std::cin >> r >> c;

	for(int i=0;i<=std::max(r+r, n+n);i++)
	{
		for(int j=0;j<=std::max(c+c, m+m);j++)
		{
			if(i>=n)
				a[i][j] = a[i - n][j];
			else if(j>=m)
				a[i][j] = a[i][j - m];
		}
	}
	int count = 0;
	for(int i=0;i<r;i++)
	{
		std::string str;
		std::cin >> str;
		for(int j=0;j<c;j++)
		{
			if(str[j] != '?')
			{
				double angle = 2 * PI * (str[j] - 'a') / ('z' - 'a' + 1);
				angle = -angle;
				b[r - i - 1][c - j - 1] = Complex(cos(angle), sin(angle));
				count++;
			}
		}
	}

	a = fft2d(a);
	b = fft2d(b);
	for(int i=0;i<ms;i++)
		for(int j=0;j<ms;j++)
			a[i][j] *= b[i][j];

	a = fft2d(a, true);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(int(real(a[i+r-1][j+c-1]) + 1e-3) == count)
				std::cout << 1;
			else
				std::cout << 0;
		}
		std::cout << '\n';
	}
}