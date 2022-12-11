#include <bits/stdc++.h>

using namespace std;

const int maxn = 130;

struct matrix
{
	int m, n;
	double mat[maxn][maxn];
	
	void init(int _m, int _n)
	{
		m = _m;
		n = _n;
		for(int i=0; i<=m; i++)
			for(int j=0; j<=n; j++)
				mat[i][j] = 0;
	}
};

matrix O, I, res;

int m, n;

double P[maxn];

matrix nhan(matrix &a, matrix &b)
{
	//cout<<"t"<<endl;
	matrix c;
	c.init(a.m, b.n);
	for(int i=0; i<=c.m; i++)
	{
		for(int j=0; j<=c.n; j++)
		{
			double t = 0;
			for(int k=0; k<=a.n; k++)
			{
				t += (a.mat[i][k]*b.mat[k][j]);
			}
			c.mat[i][j] = t;
		}
	}
	return c;
}

matrix power(matrix &a, int m)
{
	//cout<<m<<endl;
	if (m == 0)
		return I;
	
	matrix x = power(a, m/2);
	x = nhan(x, x);
	if (m&1)
		x = nhan(x, a);
	return x;
}

int main()
{
	//freopen("test.inp", "r", stdin);
	for(int i=0; i<maxn; i++)
		P[i] = 0;
	scanf("%d%d", &m, &n);
	for(int i=0; i<=n; i++)
		scanf("%lf", &P[i]);
	//cout<<n<<endl;
	for(int i=1; i<=100; i++)
	{
		if ((1<<i) > n)
		{
			//cout<<n<<endl;
			n = (1<<i)-1;
			break;
		}
	}
	//cout<<n<<endl;
	I.init(n, n);
	for(int i=0; i<=n; i++)
		I.mat[i][i] = 1;
	
	O.init(n, n);
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			int k = (i^j);
			O.mat[i][k] += P[j];
		}
	}
	
	O = power(O, m);
	res.init(n, 0);
	res.mat[0][0] = 1;
	res = nhan(O, res);
	double dres = 0;
	for(int i=1; i<=n; i++)
		dres += res.mat[i][0];
	printf("%.9f\n", dres);
	return 0;
}