#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <algorithm>

typedef long long int ll;
typedef long double ld;

const ld PI = acos(-1.0);

typedef std::complex<ld> Complex;
typedef std::vector<Complex> CVector;

void print_vector(CVector a)
{
	for(int i=0;i<a.size();i++)
		std::cout << int(real(a[i]) + 0.5) << ' ';
	std::cout << '\n';
}

CVector fft(CVector x, bool inv = false)
{
	int n = x.size();

	std::vector<int> inverse(n, 0);
	CVector r(n, 0);

	ld angle = 2 * PI / n;
	if(inv)
		angle = -angle;

	for(int i=0;i<n;i++)
		r[i] = Complex(cosl(i * angle), sinl(i * angle));

	int LOG = 0;
	while(1 << (LOG + 1) < n)
		LOG++;
	for(int i=1;i<n;i++)
		inverse[i] = (inverse[i >> 1] >> 1) | ((i & 1) << LOG); 

	for(int i=0;i<n;i++)
	{
		int to = inverse[i];
		if(i<to)
			std::swap(x[i], x[to]);
	}

	for(int len=1;len<n;len<<=1)
	{
		for(int i=0;i<n;i+=len<<1)
		{
			int cur_root = 0;
			int delta = n / (2 * len);
			for(int j=0;j<len;j++)
			{
				Complex a = x[i + j];
				Complex b = x[i + j + len];
				Complex c = r[cur_root] * b;
				x[i + j] = a + c;
				x[i + j + len] = a - c;
				cur_root += delta;
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

CVector mul(CVector a, CVector b)
{
	//std::cout << "multiplying:\n";
	//print_vector(a);
	//print_vector(b);
	a = fft(a);
	b = fft(b);
	for(int i = 0; i < a.size(); i++)
		a[i] *= b[i];
	a = fft(a, true);
	//std::cout << "got: ";print_vector(a);
	return a;
}

const int ms = 500500;

char buffer[ms];

int main()
{
	int t;
	std::cin >> t;
	while(t--)
	{
		int n;
		scanf("%i", &n);
		//std::cout << "n is " << n << "\n";
		scanf(" %s", buffer);
		int size = 1;
		while(size < 2 * n)
			size *= 2;
		//std::cout << "size is " << size << "\n";
		CVector a[3], b[3], c[3];
		a[0] = a[1] = a[2] = CVector(n, 0);
		for(int i = 0; i < n; i++)
		{
			//std::cout << "on pos " << i << "\n";
			if(buffer[i] == 'V')
				a[0][i] = a[2][i] = 1;
			else if(buffer[i] == 'K')
				a[1][i] = a[2][i] = 1;
		}
		//std::cout << "debug\n";
		for(int i = 0; i < 3; i++)
		{
			b[i] = a[i];
			std::reverse(b[i].begin(), b[i].end());
			while(b[i].size() != size)
				b[i].push_back(0);
			while(a[i].size() != size)
				a[i].push_back(0);
			//c[i] = mul(a[i], b[i]);
		}
		CVector other = mul(a[0], b[1]);
		std::vector<int> ans;
		//print_vector(other);
		for(int i = 1; i < n; i++)
		{
			//std::cout << n - i - 1 << ": on pos " << i << ", ( "<< int(real(c[0][n - i - 1]) + real(c[1][n - i - 1]) + 0.5) << ", " << int(real(c[2][n - i - 1]) + 0.5) << ")\n";
			//if(int(real(c[0][n - i - 1]) + real(c[1][n - i - 1]) + 0.5) == int(real(c[2][n - i - 1]) + 0.5))
			//	ans.push_back(i);
			long long cur = 0;
			for(int j = i; j < n; j += i)
			{
				//std::cout << "on " << n - j - 1 << "\n";
				cur += int(real(other[n - j - 1] + other[n + j - 1]) + 0.5);
			}
			if(cur == 0)
				ans.push_back(i);
		}
		ans.push_back(n);
		printf("%i\n", int(ans.size()));
		for(int i = 0; i < ans.size(); i++)
		{
			if(i)
				printf(" ");
			printf("%i", ans[i]);
		}
		printf("\n");
	}
}